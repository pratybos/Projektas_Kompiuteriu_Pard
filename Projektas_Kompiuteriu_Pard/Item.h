#pragma once
#include <string>


class Item {
public:
	void SetPrice		(float Price);
	void SetName		(std::string Name);
	void SetDescription	(std::string Description);
	void SetType		(std::string Type);
	void SetWarranty	(int Warranty);

	float GetPrice				();
	std::string GetName			();
	std::string GetDescription	();
	std::string GetType			();
	int GetWarranty				();

private:
	float		Price;
	std::string Name;
	std::string Description;
	std::string Type;
	int			Warranty;
};

