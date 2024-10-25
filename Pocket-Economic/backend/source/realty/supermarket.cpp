#include "../../includes/realty/supermarket.h"

void Supermarket::setSupermarketType(const SupermarketType& type) {
	supermarket_type_ = type;
}

void Supermarket::setCostOfOneProduct(const int64_t& cost) {
	cost_of_one_poduct_ = cost;
}

Supermarket::SupermarketType Supermarket::getSupermarketType() const {
	return supermarket_type_;
}

int64_t Supermarket::getCostOfOneProduct() const {
	return cost_of_one_poduct_;
}
