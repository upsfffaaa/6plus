// StaticLib.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include <iostream>
#include "framework.h"

using namespace std;

void fnStaticLib(const bool& result)
{
	if (result)
	{
		cout << "да" << std::endl;
	}
	else
	{
		cout << "Ненет" << std::endl;
	}
}
