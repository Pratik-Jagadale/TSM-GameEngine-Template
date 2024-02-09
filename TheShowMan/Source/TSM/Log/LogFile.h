#pragma once
#include "LogFile.h"
#include "../Core.h"

namespace TSM
{
	class TSM_API LogFile
	{
	public:
		LogFile();
		~LogFile();

		static bool CreateLogFile(void);
		static void PrintGLInfo(void);
		static void PrintLog(const char* fmt, ...);
		static void CloseLogFile(void);

	private:
		static FILE* gpFile;
	};
}

// Window Log Macros
#define TSM_PRINT_LOG(...) ::TSM::LogFile::PrintLog(__VA_ARGS__)
#define TSM_PRINT_GLINFO(...) ::TSM::LogFile::PrintGLInfo(__VA_ARGS__)
