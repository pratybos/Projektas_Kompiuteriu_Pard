#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include <algorithm>

class Shop {
public:
	Shop									();
	void PrintGoods							();
	void PrintGoods							(std::string Type);
	std::vector<Item> & GetGoods			();
	void PrintGoodsTypes					();
	std::vector<std::string> & GetGoodsTypes();
	Item BuyGoods							(size_t ID, int & Money);
	~Shop									();
private:
	std::fstream				File;
	std::vector<Item>			Goods;
	std::vector<std::string>	GoodsTypes;
};

