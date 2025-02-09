#include "mklink.h"

#include <filesystem>
#include <cstdio>

/*

TODO: 1. 文件复制到新位置，并删除旧文件，然后创建连接	O
      2. 美化界面，增加提示信息	✔

*/

sub_mklink::sub_mklink()
{
	printf("====================================\n");
	printf("mklink子模块已启动\n");
	printf("====================================\n\n");
	printf("Tips: mklink子模块 暂且不支持中文路径，所以请勿添加任何中文路径，可能会导致报错\n");
	printf("中文可以直接用于注释，但不可做路径\n\n");
}
sub_mklink::~sub_mklink()
{
	printf("\n====================================\n");
	printf("mklink子模块已关闭\n");
	printf("====================================\n");
}

sub_mklink::config& sub_mklink::read_config()
{

	//TODO: 读取和返回配置文件内容
	// 1. 读取配置文件
	std::vector<std::string> buffer_rconfig_un;
	std::string buffer_rconfig_source;
	std::string buffer_rconfig_target;

	if (rconfig(buffer_rconfig_un))
	{
		cfg.success = false;

		std::cout << "\nconfig配置文件 格式如下：" << std::endl;
		std::cout << "文件名: config.cfg" << std::endl;
		std::cout << "格式如下: 路径中请勿包含任何中文, 否则无法识别, 允许存在多行隔开 \n \
如果没有路径, 请勿写路径头即source和target, 否则会报错!! \n\n \
source: C:\\b_test \n \
source: C:\\d_test \n \
\n \
\n \
target: D:\\a_test \n \
target: D:\\c_test \n \
" << std::endl;


		return cfg;
	}

	// 2. 提炼config_buffer的配置文件内容
	for (auto& line : buffer_rconfig_un)
	{
		if (line.find("source:") != std::string::npos)
		{
			buffer_rconfig_source = line.substr(line.find(":") + 2);
			cfg.source_path.push_back(buffer_rconfig_source);	// 将源路径添加到config结构体中
		}
		if (line.find("target:") != std::string::npos)
		{
			buffer_rconfig_target = line.substr(line.find(":") + 2);
			cfg.target_path.push_back(buffer_rconfig_target);	// 将目标路径添加到config结构体中
		}
	}

	// 3. 检测source和target数目是否相等
	if (cfg.source_path.size() != cfg.target_path.size())
	{
		std::cout << "源路径和目标路径数目不相等，请检查配置文件" << std::endl;
		cfg.success = false;
	}

	// 4. 返回config结构体
	return cfg;
}

// 复制文件到新位置，并删除旧文件，然后创建连接
bool copy_and_delete(const std::string& source, const std::string& target) {
    try {
        // 检查源路径是否存在
        if (!std::filesystem::exists(source)) {
            std::cerr << "源路径不存在: " << source << std::endl;
            return false;
        }

        // 获取目标父目录
        const auto target_path = std::filesystem::path(target);
        const auto parent_dir = target_path.parent_path();

        // 创建父目录（自动处理路径存在性）
        std::filesystem::create_directories(parent_dir); // 可能抛出异常

        // 检查目标路径是否冲突（如果是目录）
        if (std::filesystem::exists(target) && std::filesystem::is_directory(target)) {
            std::cerr << "错误: 目标已存在，无法继续，请删除目标或更改目标" << target << std::endl;
            return false;
        }

        // 复制文件/目录（支持递归）
        std::filesystem::copy(source, target, 
            std::filesystem::copy_options::overwrite_existing | 
            std::filesystem::copy_options::recursive); // 可能抛出异常

        // 删除源文件/目录
        std::filesystem::remove_all(source); // 可能抛出异常

        return true;
    } catch (const std::filesystem::filesystem_error& e) {
        // 细化错误类型提示
        if (e.code() == std::errc::permission_denied) {
            std::cerr << "权限不足: " << e.path1() << std::endl;
        } else {
            std::cerr << "文件操作失败: " << e.what() << std::endl;
        }
        return false;
    }
}

int mklink_start() {
    sub_mklink mklink;
    sub_mklink::config cfg = mklink.read_config();
    if (!cfg.success) {
        return -1;
    }

    for (int i = 0; i < cfg.source_path.size(); ++i) {
        std::cout << "================================" << std::endl;
        std::cout << "源路径: " << cfg.source_path[i] << std::endl;
        std::cout << "目标路径: " << cfg.target_path[i] << std::endl;

        if (copy_and_delete(cfg.source_path[i], cfg.target_path[i])) {
            std::string command = "mklink /j \"" + cfg.source_path[i] + "\" \"" + cfg.target_path[i] + "\"";
            system(command.c_str());
        } else {
            std::cerr << "文件复制或删除失败，跳过创建链接" << std::endl;
        }
    }
    std::cout << "================================" << std::endl;

    return 0;
}


//int mklink_start()
//{
//	sub_mklink mklink;
//	sub_mklink::config cfg = mklink.read_config();
//	if (!cfg.success)
//	{
//		return -1;
//	}
//
//	for (int i = 0; i < cfg.source_path.size(); ++i)
//	{
//		//std::cout << cfg.source_path.size();
//		std::cout << "================================" << std::endl;
//		std::cout << "源路径: " << cfg.source_path[i] << std::endl;
//		std::cout << "目标路径: " << cfg.target_path[i] << std::endl;
//		std::string command = "mklink /j \"" + cfg.target_path[i] + "\" \"" + cfg.source_path[i] + "\"";
//		system(command.c_str());
//	}
//	std::cout << "================================" << std::endl;
//
//	return 0;
//
//}