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
		Game* game;

		const int& GetLibraryItemIndex();
		const void ReviewGame(const bool&);
		const void Purchase();
};

