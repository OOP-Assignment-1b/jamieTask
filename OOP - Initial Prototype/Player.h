#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "List.h"
#include "Date.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&);
		~Player();
		List<LibraryItem*> library;
};