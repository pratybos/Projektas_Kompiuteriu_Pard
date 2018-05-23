#include "Shop.h"

Shop::Shop										() {
	File.open("Goods.txt");
	if (File.good()) {
		size_t N;
		size_t n;
		Item NewItem;
		std::string Temp;
		int IntTemp;
		File >> N;
		for (size_t i = 0; i < N; i++) {
			File >> n;
			File >> Temp;
			NewItem.SetName(Temp);
			File >> Temp;
			NewItem.SetDescription(Temp);
			File >> Temp;
			NewItem.SetType(Temp);
			File >> IntTemp;
			NewItem.SetWarranty(IntTemp);
			File >> IntTemp;
			NewItem.SetPrice(IntTemp);
			for (size_t j = 0; j < n; j++) {
				Goods.push_back(NewItem);
			}
			GoodsTypes.push_back(NewItem.GetType());
		}
	}
	File.close();
}

void Shop::PrintGoods							() {
	std::cout << "**********************Goods**********************" << std::endl;
	std::cout << "*************************************************" << std::endl;
	std::vector<Item> GoodOnce = Goods;

	for (int i = 0; i < GoodOnce.size(); i++) {
		for (int j = i + 1; j < GoodOnce.size(); j++) {
			if (Goods[i].GetName() == GoodOnce[j].GetName()) {
				GoodOnce.erase(GoodOnce.begin() + j);
			}
		}
	}

	for (size_t j = 0; j < GoodOnce.size(); j++) {
		std::cout << "ID: " << j << " - " << Goods[j].GetName() << "\nPrice: " << Goods[j].GetPrice() << "\nWarranty: " << Goods[j].GetWarranty() << "\nDescription: " << Goods[j].GetDescription() << std::endl;
		std::cout << "*************************************************" << std::endl;
	}
}
void Shop::PrintGoods							(std::string Type) {
	std::cout << "**********************" << Type << "**********************" << std::endl;
	std::cout << "*************************************************" << std::endl;
	for (size_t j = 0; j < Goods.size(); j++) {
		if (Goods[j].GetType() == Type) {
			std::cout << "ID: " << j << " - " << Goods[j].GetName() << "\nPrice: " << Goods[j].GetPrice() << "\nWarranty: " << Goods[j].GetWarranty() << "\nDescription: " << Goods[j].GetDescription() << std::endl;
			std::cout << "*************************************************" << std::endl;
			break;
		}
	}
}
std::vector<Item>& Shop::GetGoods				() {
	return this->Goods;
}
void Shop::PrintGoodsTypes						() {
	std::cout << "*******************Goods Types*******************" << std::endl;
	for (int i = 0; i < GoodsTypes.size(); i++) {
		std::cout << "ID: " << i << " - " << GoodsTypes[i] << std::endl;
	}
}
std::vector<std::string>& Shop::GetGoodsTypes	() {
	return this->GoodsTypes;
}
Item Shop::BuyGoods								(size_t ID, int & Money) {
	Item Sell;
	Sell = Goods[ID];
	if (Money >= Sell.GetPrice()) {
		Money -= Sell.GetPrice();
	} else {
		std::cout << "Not enough money" << std::endl;
	}
	Goods.erase(Goods.begin() + ID);
	return Sell;
}

Shop::~Shop										() {
	if (File.is_open()) {
		File.close();
	}
	Goods.clear();
	GoodsTypes.clear();
}