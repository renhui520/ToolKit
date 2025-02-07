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
		bool success = true; // 是否成功
		std::vector<std::string> source_path; // 源路径
		std::vector<std::string> target_path; // 目标路径
	};

	config& read_config();


private:
	config cfg;
};

int mklink_start();

#endif // !__MKLINK_H__
