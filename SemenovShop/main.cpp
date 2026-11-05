#define NOMINMAX

#include <string>
#include <iostream> 
#include <Windows.h>
#include <limits>
#include <io.h>          
#include <fcntl.h> 

#include "AutoRization.hpp"


int main()
{

	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	Start();









	return 0;
}
	/*
	//система авторизации, логи пароль, вход
	//продажи: выбор товара, оплата, нал безнал, чек, галя отмена
	//склад: показать товары, пополнение, списание, изминение цены
	//Аккаунты: пользователи: супер админ, админ, клиент, продажи
	//служебные функции: всяка для работы программы
	*/

	
























