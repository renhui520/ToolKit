#include "rconfig.h"


int rconfig(std::vector<std::string>& buffers)
{
	std::string buffer;

	std::ifstream ifs;
	ifs.open("config.cfg", std::ios::in);

	if (!ifs.is_open())		//��is_open()�����ж��Ƿ�ɹ���
	{
		std::cout << "config�����ļ���ʧ��" << std::endl;
		return -1;
	}

	while (std::getline(ifs, buffer))
	{
		buffers.push_back(buffer);
		//std::cout << buffer << std::endl; // ���buffer�����е�����
	}



	ifs.close();
	return 0;
}