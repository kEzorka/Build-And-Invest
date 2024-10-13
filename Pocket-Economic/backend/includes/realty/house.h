#pragma once

#include "realty.h"
#include <vector>

class House : public virtual Realty {
public:
    class Flat {
    public:
        Flat(const int& area = 0) : area_(area) {}
        Flat(const Flat&) = default;
        Flat(Flat&&) = default;
        Flat& operator=(const Flat&) = default;
        Flat& operator=(Flat&&) = default;
        ~Flat() = default;
        void setArea(const int& area) { area_ = area; }
        int getArea() const { return area_; }

    private:
        int area_ = 0;

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

        void setFlatsCnt(FlatType* flat, const int& cnt, const int& free);
        void setFreeFlatsCnt(FlatType* flat, const int& free_cnt);
        void pushFlat();

        House::Flat* getFlat() const;
        int getFlatsCnt(FlatType* flat) const;
        int getFreeFlats(FlatType* flat) const;

    private:
        Flat* flat_ = nullptr;
        int cnt_ = 1;
        int free_ = 1;
    };

public:
    void setFlatTypesArr(const std::vector<FlatType*>& vec);


    void pushFlatType(FlatType* flat);
    void pushFlatTypesArr(const std::vector<FlatType*>& vec);


    std::vector<FlatType*> getFlatTypesArr() const;

private:
    std::vector<FlatType*> flats_arr_;

};

