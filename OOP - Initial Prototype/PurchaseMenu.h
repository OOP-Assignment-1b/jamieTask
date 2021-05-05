#pragma once
#include "Menu.h"
#include <sstream>
#include <iomanip>

class PurchaseMenu : public Menu
{
	public:
		PurchaseMenu(const std::string& title, Application* app, const int& index);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;
	private:

		int index;
};

