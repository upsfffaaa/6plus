#include "pch.h"
#include "Header.h"

#include <cstring>


bool searchCharacters(const char* input, const char* characters) {
    const size_t inputLength = strlen(input);
    const size_t charactersLength = strlen(characters);

    // Создаем массив булевых значений длиной в максимальное значение символа ASCII
    bool charMap[256] = { false };

    // Заполняем массив булевых значений значениями true для всех символов из строки characters
    for (size_t i = 0; i < charactersLength; i++) {
        charMap[(int)characters[i]] = true;
    }

    // Проверяем каждый символ из строки input
    for (size_t j = 0; j < inputLength; j++) {
        // Если символ не был найден в массиве булевых значений, возвращаем false
        if (!charMap[(int)input[j]]) {
            return false;
        }
    }

    // Если все символы были найдены, возвращаем true
    return true;
}
