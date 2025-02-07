#include "mklink.h"

sub_mklink::sub_mklink()
{
	printf("mklink��ģ��������\n");
	printf("mklink��ģ�� ���Ҳ�֧������·����������������κ�����·�������ܻᵼ�±���\n");
	printf("���Ŀ���ֱ������ע�ͣ���������·��\n");
}
sub_mklink::~sub_mklink()
{
	printf("mklink��ģ���ѹر�\n");
}

sub_mklink::config& sub_mklink::read_config()
{

	//TODO: ��ȡ�ͷ��������ļ�����
	// 1. ��ȡ�����ļ�
	std::vector<std::string> buffer_rconfig_un;
	std::string buffer_rconfig_source;
	std::string buffer_rconfig_target;

	rconfig(buffer_rconfig_un);

	// 2. ����config_buffer�������ļ�����
	for (auto& line : buffer_rconfig_un)
	{
		if (line.find("source:") != std::string::npos)
		{
			buffer_rconfig_source = line.substr(line.find(":") + 2);
			cfg.source_path.push_back(buffer_rconfig_source);	// ��Դ·����ӵ�config�ṹ����
		}
		if (line.find("target:") != std::string::npos)
		{
			buffer_rconfig_target = line.substr(line.find(":") + 2);
			cfg.target_path.push_back(buffer_rconfig_target);	// ��Ŀ��·����ӵ�config�ṹ����
		}
	}

	// 3. ���source��target��Ŀ�Ƿ����
	if (cfg.source_path.size() != cfg.target_path.size())
	{
		std::cout << "Դ·����Ŀ��·����Ŀ����ȣ����������ļ�" << std::endl;
		cfg.success = false;
	}

	// 4. ����config�ṹ��
	return cfg;
}


int mklink_start()
{
	/*
	C:\Users\renhui>mklink /j "C:\Users\renhui\Desktop\a_test" "H:\b_test"
	Ϊ C:\Users\renhui\Desktop\a_test <<===>> H:\b_test ����������
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
		std::cout << "Դ·��: " << cfg.source_path[i] << std::endl;
		std::cout << "Ŀ��·��: " << cfg.target_path[i] << std::endl;
		std::string command = "mklink /j \"" + cfg.target_path[i] + "\" \"" + cfg.source_path[i] + "\"";
		system(command.c_str());
	}

	return 0;

}