#include "Game.h"

Game::Game(const std::string& name, const std::string& desc,const int& cost,const int& rating)
	: name(name), description(desc), cost(cost), ageRating(rating)
{
}

Game::~Game()
{
}

const std::string& Game::GetName() const
{
	return name;
}

const std::string& Game::GetDescription() const
{
	return description;
}

void Game::setDiscountAmount(const int& discount)
{
	this->discount = discount/100;
}

int Game::GetCost() const
{
	return cost - (cost * discount);
}