//#pragma once
#ifndef __MKLINK_H__
#define __MKLINK_H__

#include <iostream>
#include <vector>


#include "rconfig.h"
#include "wconfig.h"

#include "toolkit.h"

class sub_mklink
{
public:
	sub_mklink();
	~sub_mklink();

	struct config
	{
		bool success = true; // �Ƿ�ɹ�
		std::vector<std::string> source_path; // Դ·��
		std::vector<std::string> target_path; // Ŀ��·��
	};

	config& read_config();


private:
	config cfg;
};

int mklink_start();

#endif // !__MKLINK_H__
