#pragma once
#include "Shop.h"
#include "Client.h"

class ShopLogic {
public:
	void Start();

private:
	Client _Client;
	Shop _Shop;
};

