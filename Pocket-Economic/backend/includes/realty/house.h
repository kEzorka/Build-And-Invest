#pragma once

#include "realty.h"
#include <vector>

class House : public virtual Realty {
public:
    enum class HouseType {
        MonoliticHouse,
        PanelHouse,
        BrickHouse,
        Non
    };

    class Flat {
    public:
        Flat(const int& area = 0, const int64_t& cost_of_square_meter = 0)
            : area_(area), cost_of_square_meter_(cost_of_square_meter) {}
        Flat(const Flat&) = default;
        Flat(Flat&&) = default;
        Flat& operator=(const Flat&) = default;
        Flat& operator=(Flat&&) = default;
        ~Flat() = default;
        void setArea(const int& area) { area_ = area; }
        void setCostOfSquareMeter(const int& cost) { cost_of_square_meter_ = cost; }
        int getArea() const { return area_; }
        int64_t getCostOfSquareMeter() const { return cost_of_square_meter_; }

    private:
        int area_ = 0;
        int64_t cost_of_square_meter_ = 0;

    };

    class FlatType {
    public:
        FlatType(Flat* flat = nullptr, const int& cnt = 1, const int& free = 1) 
            : flat_(flat), cnt_(cnt), free_(free) {}
        FlatType(const FlatType&) = default;
        FlatType(FlatType&&) = default;
        FlatType& operator=(const FlatType&) = default;
        FlatType& operator=(FlatType&&) = default;
        ~FlatType() = default;

        void setFlatsCnt(const int& cnt, const int& free);
        void setFreeFlatsCnt(const int& free_cnt);
        void pushFlat();

        House::Flat* getFlat() const;
        int getFlatsCnt() const;
        int getFreeFlats() const;

    private:
        Flat* flat_ = nullptr;
        int cnt_ = 1;
        int free_ = 1;
    };

public:
    void setFlatTypesArr(const std::vector<FlatType*>& vec);
    void setHouseType(const House::HouseType& type);
    virtual void setNewness(const int& newness) override final;

    void pushFlatType(FlatType* flat);
    void pushFlatTypesArr(const std::vector<FlatType*>& vec);


    std::vector<FlatType*> getFlatTypesArr() const;
    House::HouseType getHouseType() const;
    virtual int getNewness() const override;

private:
    std::vector<FlatType*> flats_arr_;
    HouseType house_type_ = HouseType::Non;
    int newness_ = 0;

};

