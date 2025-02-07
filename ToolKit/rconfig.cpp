#include "rconfig.h"


int rconfig(std::vector<std::string>& buffers)
{
	std::string buffer;

	std::ifstream ifs;
	ifs.open("config.cfg", std::ios::in);

	if (!ifs.is_open())		//用is_open()函数判断是否成功打开
	{
		std::cout << "config配置文件打开失败" << std::endl;
		return -1;
	}

	while (std::getline(ifs, buffer))
	{
		buffers.push_back(buffer);
		//std::cout << buffer << std::endl; // 输出buffer缓存中的内容
	}



	ifs.close();
	return 0;
}