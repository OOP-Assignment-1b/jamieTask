#include "PurchaseMenu.h"

PurchaseMenu::PurchaseMenu(const std::string& title, Application* app, const int& index) : index(index), Menu(title, app) 
{

	
	Paint(); // required in constructor
}

void PurchaseMenu::OutputOptions()
{
	auto game = app->GetStore().getGames()[this->index];
	Line(game->GetDescription());
	double cost = game->GetCost();
	cost /= 100;
	std::stringstream formatString;
	formatString  << "Cost: " << std::setprecision(5) << cost;
	Line(formatString.str());
	if (app->IsUserLoggedIn())
	{
		Line("Credits: " + std::to_string(app->GetCurrentUser()->getCredits()));
	}
}



bool PurchaseMenu::HandleChoice(char choice)
{



	return false;
}
