#include <iostream>
#include "../StaticLib/Header.h"
#include <Windows.h>
#include <string>

#define MAX_STRING_LENGTH 256

int main()
{
    // Установка кодировки ввода и вывода на консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    HANDLE dynamicLib; // Использование HANDLE вместо HINSTANCE
    dynamicLib = LoadLibrary(L"DynamicLib.dll"); // Загрузка динамической библиотеки
    if (!dynamicLib) {
        std::cerr << "Ошибка загрузки динамической библиотеки" << std::endl;
        return 1;
    }

    typedef bool (*CharSearchFunc)(const char*, const char*);
    CharSearchFunc searchFunc = reinterpret_cast<CharSearchFunc>(GetProcAddress(dynamicLib, "SearchCharacters"));

    if (!searchFunc) {
        std::cerr << "Ошибка поиска функции в динамической библиотеке" << std::endl;
        FreeLibrary(dynamicLib);
        return 1;
    }

    char input[MAX_STRING_LENGTH];
    std::cout << "Введите строку: ";
    std::cin.getline(input, MAX_STRING_LENGTH);

    char characters[MAX_STRING_LENGTH];
    std::cout << "Введите, что в ней искать: ";
    std::cin.getline(characters, MAX_STRING_LENGTH);

    std::cout << "Содержит ли строка \"" << input << "\" символы \"" << characters << "\" ?" << std::endl;

    bool result = searchFunc(input, characters); // Использование динамической библиотеки
    std::cout << "Результат: " << result << std::endl; // Простой вывод результата в консоль

    FreeLibrary(dynamicLib); // Выгрузка динамической библиотеки

    return 0;
}

