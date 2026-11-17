#ifndef _STROGER_HPP_
#define  _STROGER_HPP_

#include "serviseFunction.hpp"


//размер масиисвов склада
extern size_t sizeSt;
extern size_t* idArr;
extern std::wstring* nameArr;
extern size_t* countArr;
extern double* priceArr;
extern bool IsStoregeCreated;

extern size_t maxStorageSize;
extern size_t currentStorageSize;
extern double maxPrice;

void CreateStorage(int mode = 0);
void ShowStorage(int mode = 0);
void AddProduct();
void RemoveProduct();
void ChangePrice();

void ChangeStorage();





































#endif  // !_STROGER_HPP_

