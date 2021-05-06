#include "Game.h"

Game::Game(const std::string& name, const std::string& desc, const int& cost, const int& rating, const int& likes, const int& dislikes, const int& id)
	: name(name), description(desc), cost(cost), ageRating(rating), likes(likes), dislikes(dislikes), id(id)
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

const int& Game::GetAgeRating() const
{
	return ageRating;
}

const int& Game::GetRating() const
{
	//|-------------------------------------------------------------------|
	//|C++ is stupid int will not divided eg (1 / 3) * 100 = 0 in c++!!!!!|
	//|-------------------------------------------------------------------|
	return likes > 0 ? nearbyint((static_cast<double>(likes) / (static_cast<double>(likes) + static_cast<double>(dislikes))) * 100) : 0;
}

const int& Game::GetId() const
{
	return id;
}

const void Game::AddReview(const bool& review)
{
	review == true ? likes++ : dislikes++;
}

const int& Game::GetLikes() const
{
	return likes;
}

const int& Game::GetDislikes() const
{
	return dislikes;
}

int Game::GetCost() const
{
	return cost;
}