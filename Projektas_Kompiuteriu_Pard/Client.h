#pragma once
#include <vector>
#include <ctime>
#include <iostream>
#include "Item.h"

class Client
{
private:
	std::vector<Item>			ShoppingCart;
	std::vector<Item>			PurchaseHistory;
	std::vector<std::time_t>	Date;
	//std::vector<bool>			ItemState;
	std::vector<int>			Quantity;

public:
	// Shopping cart //
	void SetShoppingCart(Item & item);
	void DeleteItem(int index);
	void PrintShoppingCart();

	void PurchaseItems();
	void PrintPurchaseHistory();

	Client();
	~Client();
};