#pragma once

#include "../Core.h"

namespace TSM {

	class TSM_API Application
	{
	public:
		Application();
		~Application();

		int initialize(void);
		void uninitialize(void);
		void update(void);
		void display(void);
	};

	Application* CreateApplication()
	{
		return new Application();
	}

}
