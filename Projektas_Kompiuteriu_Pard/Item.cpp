#include "Item.h"

void Item::SetPrice			(float Price) {
	this->Price = Price;
}
void Item::SetName			(std::string Name) {
	this->Name = Name;
}
void Item::SetDescription	(std::string Description) {
	this->Description = Description;
}
void Item::SetType			(std::string Type) {
	this->Type = Type;
}
void Item::SetWarranty		(int Warranty) {
	this->Warranty = Warranty;
}

float Item::GetPrice			() {
	return this->Price;
}
std::string Item::GetName		() {
	return this->Name;
}
std::string Item::GetDescription() {
	return this->Description;
}
std::string Item::GetType() {
	return this->Type;
}
int Item::GetWarranty			() {
	return this->Warranty;
}
