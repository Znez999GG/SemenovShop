#ifndef _SERVISEFUNCTIN_HPP_
#define _SERVISEFUNCTIN_HPP_

#include <iomanip>
#include <iostream>
#include <string>
#include <Windows.h>
#include <cwctype>

void GetLine(std::wstring& str);
bool IsNumber(const std::wstring& str);
bool IsNotSame(std::wstring& chooseName, std::wstring* nameArr, size_t NameArrSize);


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

template<class ArrType>
void ArrPushBack(ArrType*& arr, size_t size)
{
	size++;
	ArrType* temp = new ArrType[size];
	for (size_t i = 0; i < size - 1; i++)
	{
		temp[i] = arr[i];
	}
	std::swap(temp, arr);
	delete[]temp;
}

template<class ArrType>
void ArrDeleteByIndex(ArrType*& arr, size_t size, size_t index)
{
	size--;
	ArrType* temp = new ArrType[size];

	for (size_t i = 0, j = 0; i < size; i++, j++)
	{
		if (j == index)
		{
			j++;
		}
		temp[i] = arr[j];
	}
	std::swap(temp, arr);
	delete[]temp;
	
}





#endif // !_SERVISEFUNCTIN_HPP_