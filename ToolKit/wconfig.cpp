#include "wconfig.h"


int wconfig(std::string& buffer)
{
	std::ofstream ofs;
	ofs.open("config.cfg", std::ios::out);

	if (!ofs.is_open())		//��is_open()�����ж��Ƿ�ɹ���
	{
		std::cout << "config�����ļ���ʧ��" << std::endl;
		return -1;
	}


	ofs.close();
	return 0;
}