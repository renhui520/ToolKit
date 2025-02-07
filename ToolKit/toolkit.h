// C++风格
//#pragma once

// C风格
#ifndef __TOOLKIT_H__
#define __TOOLKIT_H__


#include "book.h"
#include "mklink.h"
#include "rconfig.h"
#include "wconfig.h"



#define _AVIOD_VOID_NULL_POINTER() if (this == NULL)	\
{	\
std::cout << "空指针异常！" << std::endl;	\
return;	\
}

#define _AVIOD_INT_NULL_POINTER() if (this == NULL)	\
{	\
std::cout << "空指针异常！" << std::endl;	\
return -1;	\
}

#define Pr_LINE std::cout << "*******************************\n"
#define Pr_SELECT(which, info) std::cout << "*****    " << which << "、" << info << "    *****\n"		// info大约为5个中文字

#define PAUSE() system("pause")
#define CLEAR() system("cls")

#endif // !__TOOLKIT_H__


