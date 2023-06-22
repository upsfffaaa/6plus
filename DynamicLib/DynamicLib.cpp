#include "pch.h"
#include "Header.h"

#include <cstring>


bool searchCharacters(const char* input, const char* characters) {
    const size_t inputLength = strlen(input);
    const size_t charactersLength = strlen(characters);

    // ������� ������ ������� �������� ������ � ������������ �������� ������� ASCII
    bool charMap[256] = { false };

    // ��������� ������ ������� �������� ���������� true ��� ���� �������� �� ������ characters
    for (size_t i = 0; i < charactersLength; i++) {
        charMap[(int)characters[i]] = true;
    }

    // ��������� ������ ������ �� ������ input
    for (size_t j = 0; j < inputLength; j++) {
        // ���� ������ �� ��� ������ � ������� ������� ��������, ���������� false
        if (!charMap[(int)input[j]]) {
            return false;
        }
    }

    // ���� ��� ������� ���� �������, ���������� true
    return true;
}
