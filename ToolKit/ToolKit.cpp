// ToolKit.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

// 标准库
#include <iostream>
#include <string>

// 自定义库
#include "toolkit.h"

using namespace std;




/*

Tips: 本程序用了些许的宏定义，所以使用时要稍加注意


TODO: 1. 处理空指针传参问题（改用引用？🤔?）
	  2. 加入文件读写功能，实现数据持久化
	  3. 完善功能，例如：mklink的链接功能


*/



// 暂且处理好了 XD    //使用的栈区空间太多，容易导致栈溢出，应该使用堆区空间
int main()
{
	while (true)
	{
		int select;
		Pr_LINE;
		Pr_SELECT(1, "通讯录");
		Pr_SELECT(2, "mklink");
		Pr_LINE;
		std::cout << "输入序号选择你所希望使用的功能: " << std::endl;
		std::cin >> select;
		switch (select)
		{
		case 1:
			book_start();
			break;
		case 2:
			mklink_start();
			break;
		default:
			break;
		}

	}


	PAUSE();
	return 0;

}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
