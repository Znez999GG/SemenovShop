#include "user.hpp"


size_t userSize = 3;
size_t currentId = 2;
std::wstring CurrentStatus;

std::wstring* LoginArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2"};
std::wstring* PassArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
std::wstring* StatusArr = new std::wstring[userSize]{ L"SuperAdmin", L"Admin", L"User" };

size_t* userId = new size_t[userSize] {0, 1, 2};

void ChangeAccaunt()
{
	std::wstring choose;
	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\t Редактирование учетных записей\n";
		std::wcout << L"1 - Создать новый аккаунт\n";
		std::wcout << L"2 - Показать всех сотрудников\n";
		std::wcout << L"3 - Изменить пароль\n";
		std::wcout << L"4 - Изменить уровни доступа\n";
		std::wcout << L"5 - Редактировать премии и штравы сотрудников\n";
		std::wcout << L"6 - Удалить аккаунт\n";
		std::wcout << L"0 - Выход\n";
		std::wcout << L"Ввод:\n";
		GetLine(choose);
		if (choose == L"1")
		{
			CreateNewAccaunt();
		}
		else if (choose == L"2")
		{

		}
		else if (choose == L"3")
		{

		}
		else if (choose == L"4")
		{

		}
		else if (choose == L"5")
		{

		}
		else if (choose == L"6")
		{

		}
		else if (choose == L"0")
		{
			std::wcout << L"Выход из реестра учетных записей\n\n";
			Sleep(1500);
			break;
		}
		else
		{
			Err();
		}

	}
}

void CreateNewAccaunt()
{
	std::wstring chooseLogin, choosePass, chooseStatus, choose;

	while (true)
	{
		while (true)
		{
			system("cls");
			std::wcout << L"Введите логин нового товара \"exit\" для выхода\n";
			GetLine(chooseLogin);
			if (chooseLogin == L"exit" || chooseLogin == L"Exit")
			{
				std::wcout << L"Отмена создания учетной записи\n\n";
				Sleep(1500);
				return;
			}

			if (true) //тут остановились unordered_set
			{
				break;
			}
		}


	}

}
