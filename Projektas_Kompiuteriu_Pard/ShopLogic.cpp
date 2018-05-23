#include "ShopLogic.h"

void ShopLogic::Start() {
	while (true) {
		std::cout << "0 - Exit" << std::endl;
		std::cout << "1 - Krepselis" << std::endl;
		std::cout << "2 - Pirkimo istorija" << std::endl;
		std::cout << "3 - Prekiu paieska" << std::endl;
		int Selection;
		std::cin >> Selection;
		system("CLS");
		switch (Selection) {
		case 0:
			return;
			break;
		case 1:
			_Client.PrintShoppingCart();
			std::cout << "0 - Exit" << std::endl;
			std::cout << "1 - Apmoketi uzprekes" << std::endl;
			int _Sell;
			std::cin >> _Sell;
			switch (Selection) {
			case 0:
				break;
			case 1:
				_Client.PurchaseItems();
				break;
			default:
				break;
			}
			//system("PAUSE");
			system("CLS");
			break;
		case 2:
			_Client.PrintPurchaseHistory();
			system("PAUSE");
			system("CLS");
			break;
		case 3:
			_Shop.PrintGoodsTypes();
			int _Sel;
			std::cin >> _Sel;
			system("CLS");
			_Shop.PrintGoods(_Shop.GetGoodsTypes()[_Sel]);
			std::cout << "Pasirinkite preke" << std::endl;
			std::cin >> _Sel;
			system("CLS");
			_Client.SetShoppingCart(_Shop.GetGoods()[_Sel]);
			//system("PAUSE");
			system("CLS");
			break;
		default:
			break;
		}
	}



}
