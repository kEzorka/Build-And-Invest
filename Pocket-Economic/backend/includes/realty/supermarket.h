#pragma once

#include "realty.h"

class Supermarket : virtual public Realty {
public:
	enum class SupermarketType {
		Supermarket,
		Hypermarket,
		Non
	};
	void setSupermarketType(const SupermarketType& type);
	void setCostOfOneProduct(const int64_t& cost);

	Supermarket::SupermarketType getSupermarketType() const;
	int64_t getCostOfOneProduct() const;

private:
	SupermarketType supermarket_type_ = SupermarketType::Non;
	int64_t cost_of_one_poduct_ = 0;

};
