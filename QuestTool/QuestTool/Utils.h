#pragma once

static class Utils
{
public:
	static string PlatformToString(Platform::String^ in);
	static wstring PlatformToWString(Platform::String^ in);
	static wstring StringToWString(string in);
};

