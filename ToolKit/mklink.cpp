#include "mklink.h"

sub_mklink::sub_mklink()
{
	printf("mklink子模块已启动\n");
	printf("mklink子模块 暂且不支持中文路径，所以请勿添加任何中文路径，可能会导致报错\n");
	printf("中文可以直接用于注释，但不可做路径\n");
}
sub_mklink::~sub_mklink()
{
	printf("mklink子模块已关闭\n");
}

sub_mklink::config& sub_mklink::read_config()
{

	//TODO: 读取和返回配置文件内容
	// 1. 读取配置文件
	std::vector<std::string> buffer_rconfig_un;
	std::string buffer_rconfig_source;
	std::string buffer_rconfig_target;

	rconfig(buffer_rconfig_un);

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


int mklink_start()
{
	/*
	C:\Users\renhui>mklink /j "C:\Users\renhui\Desktop\a_test" "H:\b_test"
	为 C:\Users\renhui\Desktop\a_test <<===>> H:\b_test 创建的联接
	*/

	/*int result = system("mklink /j \"C:\\Users\\renhui\\Desktop\\a_test\" \"H:\\b_test\"");
	if (result == 0) {
		std::cout << "Junction created successfully." << std::endl;
	}
	else {
		std::cout << "Failed to create junction. Error code: " << result << std::endl;
	}*/
	//system("mklink /j \"C:\\Users\\renhui\\Desktop\\a_test\" \"H:\\b_test\"");

	sub_mklink mklink;
	sub_mklink::config cfg = mklink.read_config();
	if (!cfg.success)
	{
		return -1;
	}

	for (int i = 0; i < cfg.source_path.size(); ++i)
	{
		//std::cout << cfg.source_path.size();
		std::cout << "源路径: " << cfg.source_path[i] << std::endl;
		std::cout << "目标路径: " << cfg.target_path[i] << std::endl;
		std::string command = "mklink /j \"" + cfg.target_path[i] + "\" \"" + cfg.source_path[i] + "\"";
		system(command.c_str());
	}

	return 0;

}