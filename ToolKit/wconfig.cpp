#include "wconfig.h"


int wconfig(std::string& buffer)
{
	std::ofstream ofs;
	ofs.open("config.cfg", std::ios::out);

	if (!ofs.is_open())		//用is_open()函数判断是否成功打开
	{
		std::cout << "config配置文件打开失败" << std::endl;
		return -1;
	}


	ofs.close();
	return 0;
}