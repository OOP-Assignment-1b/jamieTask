#pragma once

#include <string>
#include <vector>

#include "LibraryItem.h"
#include "User.h"
#include "List.h"
#include "Date.h"

class Player : public User
{
public:
	Player(const std::string&, const std::string&, const Date&, const std::string& role);
	~Player();
	void addLibraryItem(LibraryItem* item);
	std::vector<LibraryItem*> getAllItems() const;
private:
	std::vector<LibraryItem*> library;
};