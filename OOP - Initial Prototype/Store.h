#pragma once

#include "Game.h"
#include "List.h"

class Store
{
	public:
		Store();
		~Store();
		List<Game*> games; // TODO: should be a dynamic collection
	private:
};