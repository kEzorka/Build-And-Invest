#include "../includes/player.h"
#include "../includes/realty/house.h"
#include "../includes/realty/realty.h"

void Player::setNickname(const std::wstring& nickname) {
	nickname_ = nickname;
}

void Player::giveSupermarket(Supermarket* realty) {
	supermarket_arr_.push_back(realty);
}

void Player::buyRealty() {
	//buy realty using real estate agency
}

void Player::buyLand() {
	//buy land using real estate agency
}

void Player::setMoney(const int64_t& money) {
	money_ = money;
}

std::vector<Supermarket*> Player::getRealty() const {
	return supermarket_arr_;
}

int64_t Player::getMoney() const {
	return money_;
}

