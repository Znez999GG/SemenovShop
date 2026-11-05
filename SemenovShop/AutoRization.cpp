#include "AutoRization.hpp"


void Start()
{
	while (true)
	{
		if (Login())
		{
			if (CurrentStatus == L"SuperAdmin")
			{
				
			}
			else if (CurrentStatus == L"Admin")
			{
				// to do
			}
			else if (CurrentStatus == L"User")
			{
				// to do
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
					std::wcout << L"\nДобро пожаловать" << LoginArr[i] << "\n";
					std::wcout << L"Ваш уровень доступа:" << StatusArr[i] << L"\n";
					currentId = userId[i];
					CurrentStatus = StatusArr[i];
				}
				else
				{
					std::wcout << L"Неверный логин или пароль повторите попытку\n\n";
					Sleep(1500);
				}
			}

		}

	}
	return false;
}