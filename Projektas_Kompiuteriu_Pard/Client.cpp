#pragma warning(disable:4996)
#include "Client.h"

void Client::SetShoppingCart(Item & item)
{
	for (size_t i = 0; i < this->ShoppingCart.size(); i++)
	{
		if (this->ShoppingCart[i].GetName() == item.GetName())
		{
			this->Quantity[i] += 1;
			return;
		}
	}
	this->ShoppingCart.push_back(item);
	this->Quantity.push_back(1);
}

void Client::DeleteItem(int index)
{
	if (this->Quantity[index - 1] > 1)
	{
		this->Quantity[index - 1] -= 1;
		return;
	}
	this->ShoppingCart.erase(this->ShoppingCart.begin() + (index - 1));
}

void Client::PrintShoppingCart()
{
	if (this->ShoppingCart.size())
	{
		float Total = 0;
		for (size_t i = 0; i < this->ShoppingCart.size(); i++)
		{
			std::cout << i + 1 << ". " << this->ShoppingCart[i].GetName() << " Kiekis: " << this->Quantity[i] << " Kaina: " << this->ShoppingCart[i].GetPrice() << std::endl;
			Total += (this->ShoppingCart[i].GetPrice() * this->Quantity[i]);
		}
		std::cout << std::endl << "Is viso moketi: " << Total << std::endl;
	}
	else
		std::cout << "Krepselis tuscias" << std::endl;
}


void Client::PrintPurchaseHistory()
{
	if (this->PurchaseHistory.size())
	{
		for (size_t i = 0; i < this->PurchaseHistory.size(); i++)
		{
			std::tm * now = std::localtime(&this->Date[i]);
				std::cout << this->PurchaseHistory[i].GetName() << "\nKaina: " << this->PurchaseHistory[i].GetPrice() << "\nData: " << now->tm_year + 1900 << "-" <<  now->tm_mon + 1 << "-" << now->tm_mday << "\nLaikas: " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << "\nBusena: Apmoketa\n";
		}
	}
	else
		std::cout << "Mokejimo istorija tuscia" << std::endl;
}

void Client::PurchaseItems()
{
	std::time_t time = std::time(NULL);
	for (size_t i = 0; i < this->ShoppingCart.size(); i++)
	{
		this->PurchaseHistory.push_back(this->ShoppingCart[i]);
		this->Date.push_back(time);
		DeleteItem(i + 1);
	}
}

Client::Client()
{
}

Client::~Client()
{
}