#include "stroger.hpp"

size_t sizeSt = 0;

size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool IsStoregeCreated = false;

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

}

void AddProduct()
{
	std::wstring chooseId, chooseCount, choose;
	int id = 0;
	size_t cout = 0;
	while (true)
	{

	}
}
