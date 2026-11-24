#include "stroger.hpp"

size_t sizeSt = 0;

size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool IsStoregeCreated = false;

size_t maxStorageSize = 5000;
size_t currentStorageSize = 0;
double maxPrice = 50000;
//действия 1
void CreateStorage(int mode)
{
	if (mode == 0 && !IsStoregeCreated)
	{
		const size_t staticSize = 10;

		size_t idArrStatic[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
		std::wstring nameArrStatic[staticSize]
		{
			L"Tornado:Storm",L"Tornado:Asian",L"Tornado:Russian",L"Tornado:Coconut",
			L"Adrenalin:Rush",L"Adrenalin:Breeze",L"Adrenalin:Original",
			L"Volt:blueberry-pomegranate",L"Volt:mango-lime",L"Volt:Grapefruit-strawberry",
		};
		size_t countArrStatic[staticSize](35, 56, 49, 54, 110, 69, 1488, 75, 32, 92);
		double priceArrStatic[staticSize](79.99, 79.99, 79.99, 79.99, 129.99, 129.99, 129.99, 89.99, 89.99, 89.99);

		sizeSt = staticSize;
		idArr = new size_t[sizeSt];
		nameArr = new std::wstring[sizeSt];
		countArr = new size_t[sizeSt];
		priceArr = new double[sizeSt];

		FillArray(idArr, idArrStatic, sizeSt);
		FillArray(nameArr, nameArrStatic, sizeSt);
		FillArray(countArr, countArrStatic, sizeSt);
		FillArray(priceArr, priceArrStatic, sizeSt);
		for (size_t i = 0; i < sizeSt; i++)
		{
			currentStorageSize += countArrStatic[i];
		}

		IsStoregeCreated = true;

	}
	else if (mode == 1)
	{

	}
	else
	{
		std::wcout << L"Склад уже сделан\n\n";
	}


}
void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::wcout << L"Йоу зацени магаз\n\n";
		std::wcout << L"ID\t" <<std::fixed << std::left << std::setw(40) << L"Название товара\t"
			<< L"Количество товара\t" << L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(35) << nameArr[i]
				<< L"\t\t" << countArr[i] << L"\t\t" << priceArr[i] << L"\n";
		}
		std::wcout << "\n";
		system("pause");
	}
	else if (mode == 1)
	{
		system("cls");
		std::wcout << L"Йоу зацени магаз\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t"
			<< L"Количество товара\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(35) << nameArr[i]
				<< L"\t\t" << countArr[i] << L"\n";
		}
		std::wcout << "\n\n";
		std::wcout << L"Заполненость склада " << currentStorageSize << L" из " << maxStorageSize << L"\n\n";
	}
	else if (mode == 2)
	{
		system("cls");
		std::wcout << L"Йоу зацени магаз\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t"
			<< L"Количество товара\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(35) << nameArr[i]
				<< L"\t\t" << countArr[i] << L"\n";
		}
		std::wcout << "\n\n";
		std::wcout << L"Заполненость склада " << currentStorageSize << L" из " << maxStorageSize << L"\n\n";
	}
	else if (mode == 3)
	{
		system("cls");
		std::wcout << L"Йоу зацени магаз\n\n";

		std::wcout << L"ID\t" <<std::fixed << std::left << std::setw(40) << L"Название товара\t"
			<< L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(35) << nameArr[i]
				<< L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << "\n\n";

	}
	else if (mode == 4)
	{
		system("cls");
		std::wcout << L"Йоу зацени магаз\n\n";

		std::wcout << L"ID\t" << std::fixed << std::left << std::setw(40) << L"Название товара\t"
			<<L"\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(35) << nameArr[i]
				<< L"\t"  << L"\n";
		}
		std::wcout << "\n\n";

	}
	else
	{
		std::wcerr << "_SHOW_STORAGE_MODE_NOT_FOUND\n\n";
		Sleep(1500);
	}

}
void AddProduct()
{
	std::wstring chooseId, chooseCount, choose;
	int id = 0;
	size_t count = 0;
	while (true)
	{
		ShowStorage(1);
		std::wcout << L"Введите id товара для пополнения или \"exit\" для выхода\n";
		GetLine(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции пополнение товара";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) -1;
			if (id<0 || id>sizeSt - 1)
			{
				Err();
			}
			else 
			{
				std::wcout << L"Введите количество товара для пополнения";
				GetLine(chooseCount);

				if (IsNumber(chooseCount))
				{
					count = std::stoull(chooseCount);
					if (count <0 || count > maxStorageSize - currentStorageSize)
					{
						std::wcout << L"Некорректное количество! На складе осталось"
							<< maxStorageSize - currentStorageSize << L"Свободных мест\n\n";
						Sleep(2000);


					}
					else
					{
						while (true)
						{
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" ----> "
								<< countArr[id] + count << L"\n\n";
							std::wcout << L"Подтвердить?\n1-Да\n2-Нет\n\n Ввод:";
							GetLine(choose);
							if (choose == L"1")
							{
								std::wcout << L"Товар успешно пополнен\n\n";
								countArr[id] += count;
								currentStorageSize += count;
								Sleep(1500);
								break;
									
							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена пополнения" << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}	
	}
}
void RemoveProduct()
{
	std::wstring chooseId, chooseCount, choose;
	int id = 0;
	size_t count = 0;
	while (true)
	{
		ShowStorage(2);
		std::wcout << L"Введите id товара для списания или \"exit\" для выхода\n";
		GetLine(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции списание товара";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id<0 || id>sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите количество товара для списания";
				GetLine(chooseCount);

				if (IsNumber(chooseCount))
				{
					count = std::stoull(chooseCount);
					if (count <0 || count > countArr[id])
					{
						std::wcout << L"Некорректное количество! На складе осталось"
							<< maxStorageSize - currentStorageSize << L"Выбраного товара\n\n";
						Sleep(2000);


					}
					else
					{
						while (true)
						{
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" ---->"
								<< countArr[id] - count << L"\n\n";
							std::wcout << L"Подтвердить?\n1-Да\n2-Нет\n\n Ввод:";
							GetLine(choose);
							if (choose == L"1")
							{
								std::wcout << L"Товар успешно списан\n\n";
								countArr[id] -= count;
								currentStorageSize -= count;
								Sleep(1500);
								break;

							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена списания" << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}
void ChangePrice()
{
	std::wstring chooseId, choosePrice, choose;
	int id = 0;
	double price = 0;
	while (true)
	{
		ShowStorage(3);
		std::wcout << L"Введите id товара для списания или \"exit\" для выхода\n";
		GetLine(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции изминение цены";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id<0 || id>sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите количество новую стоимость товара\n";
				GetLine(choosePrice);

				if (IsNumber(choosePrice))
				{
					price = std::stoull(choosePrice);
					if (price <0 || price > maxPrice)
					{
						std::wcout << L"Некорректная цена! Макисмально возможная цена:"
							<< maxPrice << L" рублей\n\n";
						Sleep(2000);


					}
					else
					{
						while (true)
						{
							std::wcout << nameArr[id] << L"\t" << priceArr[id] << L" ---->"
								<< price << L"\n\n";
							std::wcout << L"Подтвердить?\n1-Да\n2-Нет\n\n Ввод:";
							GetLine(choose);
							if (choose == L"1")
							{
								std::wcout << L"Цена успешно изменена\n\n";
								// :)
								priceArr[id] = price;
								Sleep(1500);
								break;

							}
							else if (choose == L"2")
							{
								std::wcout << L"Отмена изминения цены" << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}
						}
					}
				}
			}
		}
	}
}

//вывод действий 2
void ChangeStorage()
{
	std::wstring choose;
	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\t Редактирование склада\n";
		std::wcout << L"1 - Добавление нового товара\n";
		std::wcout << L"2 - Изминение названия товара\n";
		std::wcout << L"3 - Удаление товара\n";
		std::wcout << L"4 - Изменить лимиты склада\n";
		std::wcout << L"0 - выход\n";
		std::wcout << L"Ввод:\n";
		GetLine(choose);
		if (choose == L"1")
		{
			AddNewProduct();
		}
		else if (choose == L"2" && sizeSt >0)
		{
			ChangeProductName();
		}
		else if (choose == L"3" && sizeSt > 0)
		{
			DeleteProduct();
		}
		else if (choose == L"4")
		{
			ChangeStorageLimits();
		}
		else if (choose == L"0")
		{
			std::wcout << L"Выход из редактора склада\n\n";
			Sleep(1500);
			break;
		}
		else
		{
			if (sizeSt < 1)
			{
				std::wcout << L"\nСклад пуст\n\n";
			}
			Err();
		}
		
	}
}

//действия 2
void AddNewProduct()
{
	std::wstring chooseName, chooseCount, choosePrice, choose;
	size_t count = 0;
	double price = 0;
	while (true)
	{
		while (true)
		{
			system("cls");
			std::wcout << L"Введите название нового товара иди \"exit\" для выхода\n";
			GetLine(chooseName);
			if (chooseName == L"exit" || chooseName == L"Exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}
			if (chooseName.size() < 3 || chooseName.size() > 40)
			{
				std::wcout << L"Ошибка длинны названя товара\n";
				std::wcout << L"Допустимое значение от 3 до 40 символов";
				std::wcout << L"Кол-во сиволов в названии вашего нового товара: "
					<< chooseName.size() << L"\n\n";
				Sleep(1500);
				
			}
			else if (IsNotSame(chooseName, nameArr, sizeSt))
			{
				break;
			}
			else
			{
				std::wcout << L"Данный товар уже есть на складе";
			}
		}

		while (true)
		{
			system("cls");
			std::wcout << L"Сколько товара вы хотите добавить\n";
			GetLine(chooseCount);
			if (chooseCount == L"exit" || chooseCount == L"Exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}

			if (IsNumber(chooseCount))
			{
				count = std::stoull(chooseCount);
				if (count <0 || count > maxStorageSize - currentStorageSize)
				{
					std::wcout << L"Некорректное количество! На складе осталось "
						<< maxStorageSize - currentStorageSize << L" места\n\n";
					Sleep(2000);


				}
				else
				{
					break;
				}
			}
		}

		while (true)
		{ 
				system("cls");
			std::wcout << L"Введите цену нового товара\n";
			GetLine(choosePrice);
			if (choosePrice == L"exit" || choosePrice == L"Exit")
			{
				std::wcout << L"Отмена добавления нового товара\n\n";
				Sleep(1500);
				return;
			}
			if (IsNumber(choosePrice))
			{
				price = std::stoull(choosePrice);
				if (price <0 || price > maxPrice)
				{
					std::wcout << L"Некорректная цена! Макисмально возможная цена:"
						<< maxPrice << L" рублей\n\n";
					Sleep(2000);
				}
				else
				{
					break;
				}
			}
		}

		while (true)
		{
			system("cls");
			std::wcout << L"Новый товар " << chooseName << L"\n";
			std::wcout << L"Кол-во " << count << L"\n";
			std::wcout << L"Цена: " <<std::fixed << price << L"\n\n";
			std::wcout << L"Подтвердить?\n1-Да\n2-Нет\n\n Ввод: ";
			GetLine(choose);
			if (choose == L"1")
			{
				std::wcout << L"Загрузка новых данных в базу";
				for (size_t i = 0; i < 3; i++)
				{
					Sleep(650);
					std::wcout << L".";
				}
				ArrPushBack(idArr, sizeSt);
				ArrPushBack(nameArr, sizeSt);
				ArrPushBack(countArr, sizeSt);
				ArrPushBack(priceArr, sizeSt);
				sizeSt++;
				idArr[sizeSt - 1] = sizeSt;
				nameArr[sizeSt - 1] = chooseName;
				countArr[sizeSt - 1] = count;
				priceArr[sizeSt - 1] = price;
				// :)
				std::wcout << L"\nНовый товар успешно добавлен\n\n";
				Sleep(1500);
				break;
				continue;
			}
			else if (choose == L"2")
			{
				std::wcout << L"Отмена\n\n";
				Sleep(1500);
				break;
			}
			else
			{
				Err();
			}
		}
	}	
}
void ChangeProductName()
{

	std::wstring chooseName, chooseId, choose;
	int id = 0;
	while (true)
	{
		system("cls");

		ShowStorage(4);

		std::wcout << L"Введите Id товара или \"exit\" для выхода\n";
		GetLine(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение опции измениение названия товара\n\n";
			Sleep(1500);
			return;
		}
		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id <0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите новое названиие для товара\n";
				GetLine(chooseName);
				if (chooseName.size() < 3 || chooseName.size() > 40)
				{
					std::wcout << L"Ошибка длинны названя товара\n";
					std::wcout << L"Допустимое значение от 3 до 40 символов\n";
					std::wcout << L"Кол-во сиволов в названии вашего нового товара: "
						<< chooseName.size() << L"\n\n";
					Sleep(1500);
					

				}
				if (!IsNotSame(chooseName, nameArr, sizeSt))
				{
					std::wcout << L"Данный товар уже есть на складе";
				}
				else
				{
					while (true)
					{
						system("cls");
						std::wcout << nameArr[id] << L" ----> "
							<< nameArr[id] << L"\n\n";
						std::wcout << L"Подтвердить?\n1-Да\n2-Нет\n\nВвод: ";
						GetLine(choose);
						if (choose == L"1")
						{
							std::wcout << L"Переименование завершено\n\n";
							nameArr[id] = chooseName;
							Sleep(1500);
							break;

						}
						else if (choose == L"2")
						{
							std::wcout << L"Отмена изминение товара" << nameArr[id] << L"\n";
							Sleep(1500);
							break;
						}
						else
						{
							Err();
						}
					}
				}
			}
		}
	}
}
void DeleteProduct()
{
	std::wstring chooseId, pass;
	int id = 0;
	while (true)
	{
		system("cls");

		ShowStorage(4);

		std::wcout << L"Введите название нового товара иди \"exit\" для выхода\n";
		GetLine(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение опции измениение названия товара\n\n";
			Sleep(1500);
			return;
		}
		if (IsNumber(chooseId))
		{
			id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Подтвердите удаление товара: " << nameArr[id]
					<< L"\nВведите пароль Супер администратора\n";
				GetLine(pass);
				if (pass == PassArr[0])
				{
					std::wcout << L"Удеаление товара";
					for (size_t i = 0; i < 3; i++)
					{
						Sleep(650);
						std::wcout << L".";
					}
					Sleep(650);

					currentStorageSize -= countArr[id];
					ArrDeleteByIndex(idArr, sizeSt, id);
					ArrDeleteByIndex(nameArr, sizeSt, id);
					ArrDeleteByIndex(countArr, sizeSt, id);
					ArrDeleteByIndex(priceArr, sizeSt, id);
					sizeSt--;
					for (size_t i = id; i < sizeSt; i++)
					{
						idArr[i] = i + 1;
					}
					// :)
					std::wcout << L"\nТовар успешно удален";
					Sleep(1500);
					continue;
				}
				else 
				{
					Err();
				}
			}
		}
	}
}
void ChangeStorageLimits()
{
	std::wcout << "\n\nВ процессе разработки";
	Sleep(1500);
}







