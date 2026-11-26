#ifndef _USER_HPP_
#define _USER_HPP_

#include "serviseFunction.hpp"

extern size_t userSize;
extern size_t currentId;
extern std::wstring CurrentStatus;

extern std::wstring* LoginArr;
extern std::wstring* PassArr;
extern std::wstring* StatusArr;
extern size_t* userId;
extern double* salesArr;
extern double* fineArr;

extern size_t maxLogin;
extern size_t minLogin;
extern size_t maxPass;
extern size_t minPass;

extern bool isSetCreated;

extern std::unordered_set<wchar_t> п;

extern std::unordered_set<wchar_t> PassSymbols;

void ShowUsers(int mode = 0);
void ChangeAccaunt();
void CreateNewAccaunt();

bool CheckLogin(const std::wstring& login);
bool CheckPass(const std::wstring& pass);
void CreateSet();







#endif // !_USER_HPP_