#include "book.h"

Book::Book()
{
	_AVIOD_VOID_NULL_POINTER();
	// 处理空指针问题
	//初始化通讯录中当前的人员个数
	this->abs.m_Size = 0;
}

Book::~Book()
{
	// 处理空指针问题
}
//封装函数显示界面 如  void showMenu();
//菜单界面
void Book::showMenu()
{
	Pr_LINE;
	Pr_SELECT(1, "添加联系人");
	Pr_SELECT(2, "显示联系人");
	Pr_SELECT(3, "删除联系人");
	Pr_SELECT(4, "查找联系人");
	Pr_SELECT(5, "修改联系人");
	Pr_SELECT(6, "清空联系人");
	Pr_SELECT(0, "退出通讯录");
	Pr_LINE;
}

//1、添加联系人
void Book::addPerson(Addressbooks* abs)
{
	// 避免类的空指针异常
	_AVIOD_VOID_NULL_POINTER();

	// 临时存储
	//性别
	int sex = 0;

	//姓名
	std::string name = "";

	//年龄
	int age = 0;

	//电话
	//char phone[PHONE_LEN + 2] = "";
	std::string phone = "";

	//住址
	std::string address;

	/*-------------------------------------------------------*/


	//判断通讯录是否已满，如果满了就不再添加
	if (abs->m_Size == MAX)
	{
		std::cout << "通讯录已满，无法添加！" << std::endl;
		return;
	}
	//添加具体联系人
	std::cout << "请输入姓名：" << std::endl;
	std::cin >> name;
	// 退出输入
	if (name == "-1")
	{
		CLEAR();
		return;
	}
	CLEAR();
	showMenu();

	/*-------------------------------------------------------*/

	//性别
	std::cout << "请输入性别：" << std::endl;
	std::cout << "1——男" << std::endl;
	std::cout << "2——女" << std::endl;
	std::cout << "3——其他" << std::endl;

	while (true)
	{
		//如果输入的是1或者2可以退出循环，因为输入的是正确值
		//如果输入有误，重新输入

		if (!(std::cin >> sex)) { // 检查输入是否为整数
			std::cin.clear(); // 清除 std::cin 的错误标志
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略无效输入
			std::cout << "输入有误，请重新输入(1, 2, 3)：" << std::endl;
			continue;
		}
		// 退出输入
		if (sex == -1)
		{
			CLEAR();
			return;
		}

		if (sex == MALE || sex == FEMALE || sex == OTHER)
		{
			CLEAR();
			showMenu();
			break;
		}
	}

	/*-------------------------------------------------------*/

	//年龄
	std::cout << "请输入年龄：" << std::endl;

	while (true)
	{
		if (!(std::cin >> age)) { // 检查输入是否为整数
			std::cin.clear(); // 清除 std::cin 的错误标志
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略无效输入
			std::cout << "请输入正确的数字0 ~ 150 ：" << std::endl;
			continue;
		}
		// 退出输入
		if (age == -1)
		{
			CLEAR();
			return;
		}
		if (age > 0 && age <= 150)
		{
			CLEAR();
			showMenu();
			break;
		}

		std::cout << "请输入正确的数字0 ~ 150 ：" << std::endl;
		continue;
	}

	/*-------------------------------------------------------*/

	//电话
	while (1)
	{
		std::cout << "请输入电话号码：" << std::endl;
		std::cin >> phone;
		if (phone == "-1")
		{
			CLEAR();
			return;
		}
		if (phone.length() != PHONE_LEN)	// length() or size() is OK!
		{
			std::cout << "请输入正确的号码\n";
			continue;
		}
		CLEAR();
		showMenu();
		break;
	}

	/*-------------------------------------------------------*/

	//住址
	std::cout << "请输入家庭住址：" << std::endl;
	std::cout << "按回车键跳过" << std::endl;

	// 清楚前面的空格输入，避免无关字符影响
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// 读取一行字符串，包括空格
	std::getline(std::cin, address);

	// 退出输入
	if (address == "-1")
	{
		CLEAR();
		return;
	}

	// 判定是否为空
	if (address.empty())
	{
		CLEAR();
		showMenu();
	}

	/*-------------------------------------------------------*/

	//统一更新 通讯录人员 信息 和 人数
	abs->personArray[abs->m_Size].m_name = name;
	abs->personArray[abs->m_Size].m_Sex = sex;
	abs->personArray[abs->m_Size].m_Age = age;
	abs->personArray[abs->m_Size].m_Phone = phone;
	abs->personArray[abs->m_Size].m_Addr = address;
	abs->m_Size++;

	std::cout << "添加成功" << std::endl;

	PAUSE();//按任意键继续
	CLEAR();//清屏操作

}

//2、显示联系人
void Book::showPerson(Addressbooks* abs)
{
	// 避免类的空指针异常
	_AVIOD_VOID_NULL_POINTER();

	int p_num = 0;

	//判断通讯录中人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0)
	{
		std::cout << "当前记录为空" << std::endl;
		PAUSE();
		CLEAR();
		return;
	}
	for (int i = 0; i < abs->m_Size; i++)
	{
		std::cout << (i + 1) << "、" << abs->personArray[i].m_name << std::endl;
	}

	//输入 具体联系人 编号
	std::cin >> p_num;
	if (abs->personArray[p_num - 1].m_Sex == OTHER)
	{
		CLEAR();
		showMenu();
		std::cout << "\n姓名： " << abs->personArray[p_num - 1].m_name << std::endl;
		std::cout << "性别：" << "其他" << std::endl;
	}
	else
	{
		CLEAR();
		showMenu();
		std::cout << "\n姓名： " << abs->personArray[p_num - 1].m_name << std::endl;
		std::cout << "性别：" << (abs->personArray[p_num - 1].m_Sex == MALE ? "男" : "女") << std::endl;
	}
	std::cout << "年龄：" << abs->personArray[p_num - 1].m_Age << std::endl;
	std::cout << "电话：" << abs->personArray[p_num - 1].m_Phone << std::endl;
	std::cout << "住址：" << abs->personArray[p_num - 1].m_Addr << std::endl << std::endl;
	PAUSE();
	CLEAR();
}

//检测联系人是否存在
int Book::isExist(Addressbooks* abs, std::string name)
{

	// 避免类的空指针异常
	_AVIOD_INT_NULL_POINTER();

	for (int i = 0; i < abs->m_Size; i++)
	{
		// 检测当前联系人 “名称” 是否存在与 通讯录中
		if (abs->personArray[i].m_name == name)
		{
			return i;
		}

	}
	return -1;
}

//3、删除联系人
void Book::deletePerson(Addressbooks* abs)
{

	// 避免类的空指针异常
	_AVIOD_VOID_NULL_POINTER();

	std::cout << "请输入您要删除的联系人(姓名)：" << std::endl;

	for (int i = 0; i < abs->m_Size; i++)
	{
		std::cout << (i + 1) << "、" << abs->personArray[i].m_name << std::endl;
	}

	std::string name = "";
	std::cin >> name;

	//ret == -1 未查到
	//ret != -1	查到了
	int ret = isExist(abs, name);

	if (ret == -1)
	{
		std::cout << "查无此人";
		PAUSE();
		CLEAR();
		return;
	}
	//查找到人，要进行删除操作
	for (int i = ret; i < abs->m_Size; i++)
	{
		//可以用 "链表" 来实现删除，减少了数据的移动，从而提高了效率 !!! 后面再改

		//数据前移 这个数被前面的信息代替，从而达到删除的效果
		abs->personArray[i] = abs->personArray[i + 1];
	}
	abs->m_Size--; //更新通讯录中的人员数
	std::cout << "删除成功" << std::endl;

}
//4、查找指定联系人信息
void Book::findPerson(Addressbooks* abs)
{

	// 避免类的空指针异常
	_AVIOD_VOID_NULL_POINTER();

	std::cout << "请输入您要查找的联系人：" << std::endl;

	for (int i = 0; i < abs->m_Size; i++)
	{
		std::cout << (i + 1) << "、" << abs->personArray[i].m_name << std::endl;
	}

	std::string name = "";
	std::cin >> name;

	//判定指定的联系人是否存在通讯录中
	int ret = isExist(abs, name);

	//未找到联系人
	if (ret != -1)
	{
		std::cout << "查无此人";
		//任意键按下后清屏
		PAUSE();
		CLEAR();
		return;
	}
	// 找到联系人
	std::cout << "姓名：" << abs->personArray[ret].m_name << std::endl;
	std::cout << "性别：" << abs->personArray[ret].m_Sex << std::endl;
	std::cout << "年龄：" << abs->personArray[ret].m_Age << std::endl;
	std::cout << "电话：" << abs->personArray[ret].m_Phone << std::endl;
	std::cout << "住址：" << abs->personArray[ret].m_Addr << std::endl;
}

//TODO: 有BUG，似乎修改完之后无法正确的使用别的功能以及退出


//5、修改联系人
void Book::modifyPerson(Addressbooks* abs)
{

	// 避免类的空指针异常
	_AVIOD_VOID_NULL_POINTER();

	std::cout << "请输入你要修改的联系人名字：" << std::endl;

	for (int i = 0; i < abs->m_Size; i++)
	{
		std::cout << (i + 1) << "、" << abs->personArray[i].m_name << std::endl;
	}

	// 临时变量
	std::string name;
	int sex;
	int age;
	std::string phone;
	std::string address;
	int select;

	std::cin >> name;

	int ret = isExist(abs, name);

	if (ret == -1)
	{
		std::cout << "查无此人";
		PAUSE();
		CLEAR();
		return;
	}

	while (true)
	{
		CLEAR();
		Pr_LINE;
		std::cout << "*****    修改内容：    *****" << std::endl;
		Pr_SELECT(1, "姓名   ");
		Pr_SELECT(2, "性别   ");
		Pr_SELECT(3, "年龄   ");
		Pr_SELECT(4, "电话   ");
		Pr_SELECT(5, "住址   ");
		Pr_SELECT(0, "退出   ");
		Pr_LINE;

		std::cin >> select;

		switch (select)
		{
		case 1://姓名
			std::cout << "请输入姓名：" << std::endl;
			std::cin >> name;
			abs->personArray[ret].m_name = name;
			std::cout << "修改成功" << std::endl;
			break;
		case 2://性别
			std::cout << "请输入性别：" << std::endl;
			std::cout << "1——男  2——女" << std::endl;
			std::cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				std::cout << "修改成功" << std::endl;
				break;
			}
			std::cout << "输入有误，请重新输入" << std::endl;

		case 3://年龄
			std::cout << "请输入年龄：" << std::endl;
			std::cin >> age;
			abs->personArray[ret].m_Age = age;
			std::cout << "修改成功" << std::endl;
			break;
		case 4://电话
			std::cout << "请输入电话号码：" << std::endl;
			std::cin >> phone;
			abs->personArray[ret].m_Phone = phone;
			std::cout << "修改成功" << std::endl;
			break;
		case 5://住址
			std::cout << "请输入住址：" << std::endl;
			std::cin >> address;
			abs->personArray[ret].m_Addr = address;
			std::cout << "修改成功" << std::endl;
			break;
		case 0://退出
			CLEAR();
			break;
		}
		break;
	}

}

//6、清空联系人
void Book::cleanPerson(Addressbooks* abs)
{

	// 避免类的空指针异常
	_AVIOD_VOID_NULL_POINTER();

	// 名义上的清空😂
	abs->m_Size = 0;
	std::cout << "通讯录已清空" << std::endl;
	PAUSE();
	CLEAR();
}

void book_start()
{

	//应该将这个开辟到堆区更好些
	Book* book = new Book;

	int select = 0;

	while (true)
	{
		//菜单调用
		book->showMenu();

		std::cin >> select;

		if (select == 0) //0、退出通讯录
		{
			std::cout << "欢迎下次使用" << std::endl;
			break;
		}
		CLEAR();

		if (select > 6 || select < 0)
		{
			std::cout << "输入有误，请重新输入" << std::endl;
			std::cout << "按任意键继续..." << std::endl;
			PAUSE();
			CLEAR();
			continue;
		}

		book->showMenu();

		switch (select)
		{
		case 1: //1、添加联系人
			book->addPerson(&book->abs);//利用地址传递，给以修饰实参
			break;
		case 2: //2、显示联系人
			book->showPerson(&book->abs);
			break;
		case 3://3、删除联系人
			book->deletePerson(&book->abs);
			break;
		case 4: //4、查找联系人
			book->findPerson(&book->abs);
			break;
		case 5: //5、修改联系人
			book->modifyPerson(&book->abs);
			break;
		case 6: //6、清空联系人
			book->cleanPerson(&book->abs);
			break;
		default:
			break;
		}


	}

	// 释放堆区空间
	delete book;
	book = NULL;
}

