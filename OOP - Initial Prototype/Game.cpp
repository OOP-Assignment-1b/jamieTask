#include "Game.h"

Game::Game(const std::string& name, const std::string& desc,const int& cost,const int& rating, const int& likes, const int& dislikes)
	: name(name), description(desc), cost(cost), ageRating(rating), likes(likes), dislikes(dislikes)
{}

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

const int& Game::GetRating() const
{
	return likes > 0 ? ((likes / (likes + dislikes)) * 100) : 0;
}

void Game::setDiscountAmount(const int& discount)
{
	this->discount = discount/100;
}

int Game::GetCost() const
{
	return cost - (cost * discount);
}