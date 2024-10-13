#include "../../includes/realty/house.h"

void House::setFlatTypesArr(const std::vector<FlatType*>& vec) {
	flats_arr_ = vec;
}

void House::FlatType::setFlatsCnt(FlatType* flat, const int& cnt, const int& free) {
	flat->cnt_ = cnt;
	flat->free_ = free;
}

void House::FlatType::setFreeFlatsCnt(FlatType* flat, const int& free_cnt) {
	if (free_cnt > flat->cnt_) {
		throw std::runtime_error("your cnt of free flats is bigger than cnt of flats in the house");
	} else {
		flat->free_ = free_cnt;
	}
}

void House::FlatType::pushFlat() {
	++cnt_;
	++free_;
}

House::Flat* House::FlatType::getFlat() const {
	return flat_;
}

int House::FlatType::getFlatsCnt(FlatType* flat) const {
	return cnt_;
}

int House::FlatType::getFreeFlats(FlatType* flat) const {
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
