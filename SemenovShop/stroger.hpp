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

void CreateStorage(int mode = 0);
void ShowStorage(int mode = 0);
void AddProduct();







































#endif  // !_STROGER_HPP_

