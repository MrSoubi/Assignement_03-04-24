#pragma once

static class Utils
{
public:
	static string PlatformToString(Platform::String^ pstring);
	static wstring PlatformToWString(Platform::String^ pstring);
	static wstring StringToWString(string str);
	static string WStringToString(wstring wstr);
};

