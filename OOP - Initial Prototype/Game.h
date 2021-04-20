#pragma once

#include <string>

class Game
{
	public:
		Game(const std::string&, const std::string&,const int&,const int&);
		~Game();

		const std::string& GetName() const;
		const std::string& GetDescription() const;
		
		void setDiscountAmount(const int& discount);

		int GetCost() const;
	private:
		std::string name;
		std::string description;
		int cost;
		int ageRating;
		int discount = 0;
};