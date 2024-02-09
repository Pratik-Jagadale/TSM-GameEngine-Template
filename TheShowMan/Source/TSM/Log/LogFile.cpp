#include "pch.h"
#include "LogFile.h"

namespace TSM
{
	FILE* LogFile::gpFile;

	LogFile::LogFile()
	{

	}

	LogFile::~LogFile()
	{

	}

	bool LogFile::CreateLogFile(void)
	{
		//code
		if (gpFile != NULL)
			return(FALSE);

		if (fopen_s(&gpFile, "Log.txt", "w") != 0)
		{
			MessageBox(NULL, TEXT("Failed To Create Log File \"Log.txt\" !!! Exitting Now ..."), TEXT("LOG FILE ERROR"), MB_ICONERROR | MB_OK);
			return(FALSE);
		}

		else
		{
			fprintf(gpFile, "============================================================\n");
			fprintf(gpFile, "Log File \"Log.txt\" Has Been Created Successfully !!!\n");
			fprintf(gpFile, "============================================================\n\n");
		}
		return(TRUE);
	}

	void LogFile::PrintGLInfo(void)
	{

	}

	void LogFile::PrintLog(const char* fmt, ...)
	{
		//variable declarations
		va_list arg;
		int ret;

		//code
		if (gpFile == NULL)
			return;
		va_start(arg, fmt);
		ret = vfprintf(gpFile, fmt, arg);
		va_end(arg);
	}

	void LogFile::CloseLogFile(void)
	{
		//code
		if (gpFile == NULL)
			return;

		fprintf(gpFile, "============================================================\n");
		fprintf(gpFile, "Log File \"Log.txt\" Has Been Closed Successfully !!!\n");
		fprintf(gpFile, "============================================================\n");

		fclose(gpFile);
		gpFile = NULL;
	}

}
