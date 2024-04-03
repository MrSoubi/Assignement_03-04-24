#include "pch.h"
#include "Utils.h"

string Utils::PlatformToString(Platform::String^ in)
{
	std::wstring wsstr(in->Data());
	std::string s(wsstr.begin(), wsstr.end());
	return s;
}

wstring Utils::PlatformToWString(Platform::String^ in)
{
	std::wstring wsstr(in->Data());
	return wsstr;
}

wstring Utils::StringToWString(string str)
{
	wstring temp = wstring(str.begin(), str.end());
	return temp;
}
