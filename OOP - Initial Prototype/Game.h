#pragma once

#include <string>
#include <math.h>  

class Game
{
public:
	Game(const std::string&, const std::string&, const int&, const int&, const int&, const int&, const int&);
	~Game();

	const std::string& GetName() const;
	const std::string& GetDescription() const;
	const int& GetAgeRating() const;
	const int& GetRating() const;

	const int& GetId() const;

	const void AddReview(const bool&);

	const int& GetLikes() const;
	const int& GetDislikes() const;

	int GetCost() const;
private:
	std::string name;
	std::string description;
	int id;
	int cost;
	int ageRating;
	int likes;
	int dislikes;
};