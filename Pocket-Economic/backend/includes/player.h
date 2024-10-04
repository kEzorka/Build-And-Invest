#pragma once
#include "realty/supermarket.h"
#include "realty/house.h"
#include "realty/land_plot.h"

#include <iostream>
#include <vector>

class Player {
public:
	void setNickname(const std::wstring& nickname);


	void giveSupermarket(Supermarket* realty);
	void buyRealty();

	void buyLand();


	void setMoney(const int64_t& money);

	std::vector<Supermarket*> getRealty() const;
	int64_t getMoney() const;

protected:


private:
	std::wstring nickname_;

	std::vector<House*> house_arr_;
	std::vector<Supermarket*> supermarket_arr_;
	int64_t money_;

};
