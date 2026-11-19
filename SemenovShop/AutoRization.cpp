#include "AutoRization.hpp"


void Start()
{
	while (true)
	{
		if (Login())
		{
			if (CurrentStatus == L"SuperAdmin")
			{
				CreateStorage();
				SuperAdminMenu();
			}
			else if (CurrentStatus == L"Admin")
			{
				// to do
				std::wcout << L"admin меню не сделано";
			}
			else if (CurrentStatus == L"User")
			{
				// to do
				std::wcout << L"user меню не сделано";
			}
			else
			{
				std::wcerr << L"\n\n_CURRENT_STATUS_LOGIN_ERROR_\n\n";
			}
		}
		else
		{
			system("cls");
			std::wcout << L"Всего доброго\n";
			Sleep(1500);
			break;
		}
	}
}

bool Login()
{
	std::wstring login, pass;

	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\n\t\t\tДобро пожаловать в магазин \n\n\t\t\tEnergy-Shop\n\n";
		std::wcout << L"Введите логин \"exit\" для выхода: ";
		GetLine(login);
		if (login == L"exit" || login == L"Exit")
		{
			return false;
		}
		else
		{
			std::wcout << L"Введите пароль:";
			GetLine(pass);
			for (size_t i = 0; i < userSize; i++)
			{
				if (login == LoginArr[i] && pass == PassArr[i])
				{
					std::wcout << L"\nДобро пожаловать " << LoginArr[i] << "\n";
					std::wcout << L"Ваш уровень доступа: " << StatusArr[i] << L"\n";
					currentId = userId[i];
					CurrentStatus = StatusArr[i];
					Sleep(1500);
					return true;
				}
				
				
				
				
			}
			std::wcout << L"Неверный логин или пароль повторите попытку\n\n";
			Sleep(1500);

		}


	}
	return false;
}

void SuperAdminMenu()
{
	std::wstring choose;
	while (true)
	{
		system("cls");

		std::wcout << L"1 - Начать продажи\n";
		std::wcout << L"2 - Посмотреть склад\n";
		std::wcout << L"3 - Пополнить склад\n";
		std::wcout << L"4 - Списать товары\n";
		std::wcout << L"5 - Изменить цены\n";
		std::wcout << L"6 - Редактировать склад\n";
		std::wcout << L"7 - Редактировать сотрудников\n";
		std::wcout << L"8 - Отчёт о прибыли\n";
		std::wcout << L"0 - Выход\n";
		std::wcout << L"Ввод:";
		GetLine(choose);
		
		if (choose == L"1")
		{

		}
		else if (choose == L"2")
		{
			ShowStorage();

		}
		else if (choose == L"3")
		{
			AddProduct();
		}
		else if (choose == L"4")
		{
			RemoveProduct();
		}
		else if (choose == L"5")
		{
			ChangePrice();
		}
		else if (choose == L"6")
		{
			ChangeStorage();
		}
		else if (choose == L"7")
		{

		}
		else if (choose == L"8")
		{

		}
		else if (choose == L"0")
		{

		}
		else
		{
			Err();
		}

	}
}
