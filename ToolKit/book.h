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
	//������ϵ�˽ṹ��
	struct Person
	{
		//����
		std::string m_name = "";
		//�Ա�  1 �� 2 Ů
		uint8_t m_Sex = 0;
		//����
		int m_Age = -1;
		//�绰
		std::string m_Phone = "";
		//סַ
		std::string m_Addr = "";
	};

	//����ͨѶ¼�ṹ��
	struct Addressbooks
	{
		//ͨѶ¼�б������ϵ�˵�����
		struct Person personArray[MAX];
		//ͨѶ¼�е�ǰ��¼��ϵ�˵ĸ���
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


	//ͨѶ¼�ṹ�����
	struct Addressbooks abs;

};

void book_start();

#endif