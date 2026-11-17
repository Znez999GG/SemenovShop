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
		double priceArrStatic[staticSize](79.99, 79.99, 79.99, 79.99, 129.99, 129.99, 129.99, 89.9, 89.9, 89.9);

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
		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t"
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

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t"
			<< L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::left << std::setw(35) << nameArr[i]
				<< L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << "\n\n";

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
