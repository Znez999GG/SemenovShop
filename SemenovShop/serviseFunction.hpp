#ifndef _SERVISEFUNCTIN_HPP_
#define _SERVISEFUNCTIN_HPP_

#include <iomanip>
#include <iostream>
#include <string>
#include <Windows.h>

void GetLine(std::wstring& str);

inline void Err()
{
	std::wcout << L"Некорректный ввод\n\n";
	Sleep(1500);
}

template<typename ArrType>
void FillArray(ArrType* dynamiArr, ArrType* staticArr, size_t commonSize)
{
	for (size_t i = 0; i < commonSize; i++)
	{
		dynamiArr[i] = staticArr[i];
	}
}

bool IsNumber(const std::wstring& str);













#endif // !_SERVISEFUNCTIN_HPP_