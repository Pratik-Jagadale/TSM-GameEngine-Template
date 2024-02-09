#include "pch.h"

#include "Application.h"
#include "../Log/Log.h"
#include "../Log/LogFile.h"

int main()
{

}
namespace TSM
{

	Application::Application()
	{
		// INITIAILIZING CONSOLE LOG
		TSM::Log::initialize();
		TSM_INFO("Staring Log!");
		TSM_CORE_INFO("Staring Core Log!");

		// INITIALIZING FILE LOG
		TSM::LogFile::CreateLogFile();
	}

	Application::~Application()
	{
		TSM::LogFile::CloseLogFile();
	}

	int Application::initialize(void)
	{
		return 0;
	}

	void Application::uninitialize(void)
	{

	}

	void Application::update(void)
	{

	}
	void Application::display(void)
	{

	}
}
