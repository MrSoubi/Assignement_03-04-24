#include "pch.h"
#include "Utils.h"

string Utils::PlatformToString(Platform::String^ pstring)
{
	std::wstring wsstr(pstring->Data());
	std::string s(wsstr.begin(), wsstr.end());
	return s;
}

wstring Utils::PlatformToWString(Platform::String^ pstring)
{
	std::wstring wsstr(pstring->Data());
	return wsstr;
}

wstring Utils::StringToWString(string str)
{
	wstring temp = wstring(str.begin(), str.end());
	return temp;
}

string Utils::WStringToString(wstring wstr)
{
	return string();
}
