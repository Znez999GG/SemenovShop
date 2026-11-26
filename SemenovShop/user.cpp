#include "user.hpp"


size_t userSize = 3;
size_t currentId = 2;
std::wstring CurrentStatus;

std::wstring* LoginArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2"};
std::wstring* PassArr = new std::wstring[userSize]{ L"admin", L"user1", L"user2" };
std::wstring* StatusArr = new std::wstring[userSize]{ L"SuperAdmin", L"Admin", L"User" };
size_t* userId = new size_t[userSize] {0, 1, 2};
double* salesArr = new double[userSize] {};
double* fineArr = new double[userSize] {};


size_t maxLogin = 12;
size_t minLogin = 5;
size_t maxPass = 16;
size_t minPass = 8;

bool isSetCreated = false;

std::unordered_set<wchar_t> LoginSymbols;
std::unordered_set<wchar_t> PassSymbols;


void ShowUsers(int mode)
{
	if (mode == 0)
	{
		system("cls");

		std::wcout << L"ID\t" << std::left << std::setw(maxLogin) << L"Логин\t" << std::setw(maxPass) << L"Пароль\t"
			<< std::setw(StatusArr[0].size() + 2) << L"Роль\t" << L"Продажи\t\t" << L"Штрафы\n\n";
		//закончим тут

		std::wcout << L"\n\n";
		system("pause");

	}
}

void ChangeAccaunt()
{
	if (!isSetCreated)
	{
		CreateSet();
	}
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
			std::wcout << L"Создайте новый логин \"exit\" для выхода\n";
			GetLine(chooseLogin);
			if (chooseLogin == L"exit" || chooseLogin == L"Exit")
			{
				std::wcout << L"Отмена создания учетной записи\n\n";
				Sleep(1500);
				return;
			}

			if (CheckLogin(chooseLogin))
			{
				break;
			}
		}


	}
	while (true)
	{
		while (true)
		{
			system("cls");
			std::wcout << L"Создайте новый пароль  \"exit\" для выхода\n";
			GetLine(choosePass);
			if (choosePass == L"exit" || choosePass == L"Exit")
			{
				std::wcout << L"Отмена создания учетной записи\n\n";
				Sleep(1500);
				return;
			}

			if (CheckPass(choosePass))
			{
				break;
			}
		}


	}
	while (true)
	{
		while (true)
		{
			system("cls");
			std::wcout << L"Введите роль нового пользователя \"exit\" для выхода\n";
			std::wcout << L"1 - Сотрудник\n";
			std::wcout << L"2 - Администратор\n";
			std::wcout << L"Ввод:\n";
			GetLine(choose);
			if (choosePass == L"exit" || choosePass == L"Exit")
			{
				std::wcout << L"Отмена создания учетной записи\n\n";
				Sleep(1500);
				return;
			}
			if (choose == L"1")
			{
				chooseStatus = L"User";
				break;
			}
			else if (choose == L"2")
			{
				std::wcout << L"Для подтверждения введите пароль Супер администратора";
				GetLine(choose);
				if (choose == PassArr[0])
				{
					chooseStatus = L"Admin";
					break;
				}
				else
				{
					Err();
				}
			}
			else
			{
				Err();
			}
		}
		

	}
	while (true)
	{
		system("cls");
		std::wcout << "Логин: " << chooseLogin << L"\n";
		std::wcout << "Пароль: " << choosePass << L"\n";
		std::wcout << "Роль: " << chooseStatus << L"\n";
		std::wcout << "Подтвердить? \n1 - да \n 2 - отмена\n Ввод: ";
		GetLine(choose);
		if (choose == L"1")
		{
			std::wcout << L"Создание аккаунта";
			for (size_t i = 0; i < 3; i++)
			{
				Sleep(650);
				std::wcout << L" .";
			}
			Sleep(650);
			ArrPushBack(userId, userSize);
			ArrPushBack(LoginArr, userSize);
			ArrPushBack(PassArr, userSize);
			ArrPushBack(StatusArr, userSize);
			ArrPushBack(fineArr, userSize);
			ArrPushBack(salesArr, userSize);
			userSize++;

			userId[userSize - 1] = userSize - 1;
			LoginArr[userSize - 1] = chooseLogin;
			PassArr[userSize - 1] = choosePass;
			StatusArr[userSize - 1] = choosePass;
			fineArr[userSize - 1] = 0.0;
			salesArr[userSize - 1] = 0.0;

			std::wcout << L"\n\nУчетная запись создана\n\n";
			Sleep(1500);
			break;
		}
		else if (choose == L"2")
		{
			std::wcout << L"Отмена создания учетной записи";
			Sleep(1500);
			break;
		}
		else
		{
			Err();
		}
	}

}

bool CheckLogin(const std::wstring& login)
{
	if (login.size() < minLogin || login.size() > maxLogin)
	{
		std::wcout << L"Ошибка длинны логина! Доступно от" << minLogin << L"ДО" 
			<< maxLogin << L"символов\n\n";
		Sleep(1500);
		return false;
	}
	if (!IsNotSame(login, LoginArr, userSize))
	{
		std::wcout << L"Такой пользователь уже существует\n\n";
		Sleep(1500);
		return false;
	}
	int count = 0;
	for (size_t i = 0; i < login.size(); i++)
	{
		if (!LoginSymbols.count(login[i]))
		{
			std::wcout << L"Некорректные символы в логине\nДопустимые символы A-Z, a-z, 0-9";
			Sleep(1400);
			return false;
		}
		if (!std::iswdigit(login[i]) && count < 5)
		{
			count++;
		}
	}
	if (count >= 4)
	{
		return true;
	}
	else
	{
		std::wcout << L"Слишком мало буквенных символов! Минимум 4 символа верхнего или нижнего регистра!\n\n";
		Sleep(1500);
		return false;
	}
}

bool CheckPass(const std::wstring& pass)
{
	if (pass.size() < minPass || pass.size() > maxPass)
	{
		std::wcout << L"Ошибка длинны Пароля! Доступно от" << minPass << L"ДО"
			<< maxPass << L"символов\n\n";
		Sleep(1500);
		return false;
	}
	int symbolCount = 0, letterCount = 0, letterCapCount = 0, numberCount = 0;
	for (size_t i = 0; i < pass.size(); i++)
	{
		if (!PassSymbols.count(pass[i]))
		{
			std::wcout << L"Некорректные символы в логине\n"
				<< "Допустимые символы A - Z, a - z, 0 - 9 и спец символы\n\n";
			Sleep(1400);
			return false;
		}
		if (!std::iswdigit(pass[i]) && numberCount < 2)
		{
			numberCount++;
		}
		else if (pass[i] >= L'A' && pass[i] < L'Z' && letterCapCount < 1)
		{
			letterCapCount++;
		}
		else if (pass[i] >= L'a' && pass[i] < L'z' && letterCapCount < 4)
		{
			letterCapCount++;
		}
		else
		{
			symbolCount++;
		}
	}
	if (symbolCount > 0 && letterCount > 3 && letterCapCount && numberCount > 1)
	{
		return true;
	}
	else
	{
		std::wcout << L"Некорректный пароль! Минимальные требования:\n";
		std::wcout << L"Цифры - 2 и более\n";
		std::wcout << L"Нижний регистр букв - 4 и более";
		std::wcout << L"Верхний регистр букв - 1 и более";
		std::wcout << L"Спецыальные символы - 1 и более";
		Sleep(1600);
		return false;
	}

}

void CreateSet()
{
	for (wchar_t i = L'0'; i <= '9'; i++)
	{
		LoginSymbols.insert(i);
	}
	for (wchar_t i = L'A'; i <= 'Z'; i++)
	{
		LoginSymbols.insert(i);
	}
	for (wchar_t i = L'a'; i <= 'z'; i++)
	{
		LoginSymbols.insert(i);
	}
	for (wchar_t i = L'!'; i <= '~'; i++)
	{
		LoginSymbols.insert(i);
	}
	isSetCreated = true;
}




