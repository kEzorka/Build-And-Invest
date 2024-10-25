#include "../../includes/realty/house.h"

void House::setFlatTypesArr(const std::vector<FlatType*>& vec) {
	flats_arr_ = vec;
}

void House::setHouseType(const House::HouseType& type) {
	house_type_ = type;
}

void House::setNewness(const int& newness) {
	newness_ = newness;
}

void House::FlatType::setFlatsCnt(const int& cnt, const int& free) {
	cnt_ = cnt;
	free_ = free;
}

void House::FlatType::setFreeFlatsCnt(const int& free_cnt) {
	if (free_cnt > cnt_) {
		throw std::runtime_error("your cnt of free flats is bigger than cnt of flats in the house");
	} else {
		free_ = free_cnt;
	}
}

void House::FlatType::pushFlat() {
	++cnt_;
	++free_;
}

House::Flat* House::FlatType::getFlat() const {
	return flat_;
}

int House::FlatType::getFlatsCnt() const {
	return cnt_;
}

int House::FlatType::getFreeFlats() const {
	return free_;
}

void House::pushFlatType(FlatType* flat) {
	flats_arr_.push_back(flat);
}

void House::pushFlatTypesArr(const std::vector<FlatType*>& vec) {
	flats_arr_.insert(flats_arr_.end(), vec.begin(), vec.end());
}




std::vector<House::FlatType*> House::getFlatTypesArr() const {
	return flats_arr_;
}

House::HouseType House::getHouseType() const {
	return house_type_;
}

int House::getNewness() const {
	return newness_;
}
