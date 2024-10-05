#pragma once

#include "realty.h"
#include <vector>

class House : public virtual Realty {
public:
	class FlatType {
	public:
		void setArea(const int& area) { area_ = area; }
		int getArea() const { return area_; }

	private:
		int area_;

	};
	struct Flat {
		FlatType flat;
		int cnt = 1;
		int free = 1;
	};

public:
	virtual void setTotalHouseArea(const int64_t& area);
	virtual void setAreaOfFlats(const std::vector<Flat*>& vec);

	virtual void pushAreaOfFlat(Flat* area);
	virtual void pushAreaOfFlat(const std::vector<Flat*>& vec);



	virtual int64_t getTotalHouseArea() const;
	virtual std::vector<Flat*> getAreaOfFlats() const;

private:
	int64_t total_house_area_;
	std::vector<Flat*> flats_arr_;

};

