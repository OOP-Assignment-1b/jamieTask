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
		std::stringstream formatStringTwo;
		double credits = app->GetCurrentUser()->getCredits() / 100.00f;
		formatStringTwo << "Credits: " << std::setprecision(5) << credits;
		Line(formatStringTwo.str());
		Line();
		bool hasGame = false;
		Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
		auto games = player->getAllItems();

		for (int i = 0; i < games.length(); i++)
		{
			if (games[i]->getGame().GetName() == app->GetStore().getGames()[index]->GetName())
			{
				hasGame = !hasGame;
				Line("You own this game!");
				Line();
				Line("Purchased: " + games[i]->GetPurchasedDate().getDate());
				Line("Playtime: " + std::to_string(games[i]->GetPlaytime()));
			}
		}
		if(!hasGame){
			Option('P', "Purchase " + game->GetName());
		}
	}
	
}



bool PurchaseMenu::HandleChoice(char choice)
{

	if (app->IsUserLoggedIn())
	{
		switch (choice)
		{

		case 'P': {
				auto game = app->GetStore().getGames()[this->index];
				Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
				if (player->getCredits() >= game->GetCost())
				{
					player->removeCredits(game->GetCost());
					player->addLibraryItem(new LibraryItem(Date(Utils::getDay(), Utils::getMonth(), Utils::getYear()), *game, 0));
				}
			
		}break;
		}

	}
	

	return false;
}
