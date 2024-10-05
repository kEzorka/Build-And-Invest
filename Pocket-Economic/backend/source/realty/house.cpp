#include "../../includes/realty/house.h"

void House::setTotalHouseArea(const int64_t& area) {
	total_house_area_ = area;
}

void House::setAreaOfFlats(const std::vector<Flat*>& vec) {
	flats_arr_ = vec;
}

void House::pushAreaOfFlat(Flat* area) {
	flats_arr_.push_back(area);
}

void House::pushAreaOfFlat(const std::vector<Flat*>& vec) {
	flats_arr_.insert(flats_arr_.end(), vec.begin(), vec.end());
}

int64_t House::getTotalHouseArea() const {
	return total_house_area_;
}

std::vector<House::Flat*> House::getAreaOfFlats() const {
	return flats_arr_;
}
