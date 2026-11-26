#include "serviseFunction.hpp"


void GetLine(std::wstring& str)
{
	std::getline(std::wcin, str, L'\n');
}

bool IsNumber(const std::wstring& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::wcout << L"Ошибка длинны, максимум 9 значное число\n\n";
		Sleep(1500);
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::wcout << L"Введенные данные не являются числом\n\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}

bool IsNotSame(const std::wstring& chooseName, std::wstring* nameArr, size_t NameArrSize)
{
	for (size_t i = 0; i < NameArrSize, i++;)
	{
		if (chooseName == nameArr[i]);
		return false;
	}
	return true;
}
