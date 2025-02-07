#ifndef __BOOK_H__
#define __BOOK_H__


#include <iostream>
#include <string>
#include "toolkit.h"


#define MAX 1000
#define PHONE_LEN 11



class Book
{
public:
	Book();
	~Book();

	enum
	{
		NONE,
		MALE,
		FEMALE,
		OTHER,
	};
	//设置联系人结构体
	struct Person
	{
		//姓名
		std::string m_name = "";
		//性别  1 男 2 女
		uint8_t m_Sex = 0;
		//年龄
		int m_Age = -1;
		//电话
		std::string m_Phone = "";
		//住址
		std::string m_Addr = "";
	};

	//设置通讯录结构体
	struct Addressbooks
	{
		//通讯录中保存的联系人的数据
		struct Person personArray[MAX];
		//通讯录中当前记录联系人的个数
		int m_Size;

	};


	void showMenu();
	void addPerson(Addressbooks* abs);
	int isExist(Addressbooks* abs, std::string name);
	void showPerson(Addressbooks* abs);
	void deletePerson(Addressbooks* abs);
	void findPerson(Addressbooks* abs);
	void modifyPerson(Addressbooks* abs);
	void cleanPerson(Addressbooks* abs);


	//通讯录结构体变量
	struct Addressbooks abs;

};

void book_start();

#endif