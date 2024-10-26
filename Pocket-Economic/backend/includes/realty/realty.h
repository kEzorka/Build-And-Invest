#pragma once

#include <iostream>

class LandPlot;
class RealEstateAgency;
class Calamity;
class Player;

class Realty {
public:
    virtual void setBuildingCost(const int64_t& cost);
    virtual void setBuildingTime(const int64_t& time);
    virtual void setOwner(Player* owner);
    virtual void setLandPlot(LandPlot* land_plot);
    virtual void setCalamity(Calamity* calamity);
    virtual void setNumberOfRealty(const int& number);
    virtual void setNewness(const int& newness) {}
    virtual void setCoordsInBuildingLand(const std::pair<int, int>& coords);

    virtual int64_t getBuildingCost() const;
    virtual int64_t getBuildingTime() const;
    virtual Player* getOwner() const;
    virtual LandPlot* getLandPlot() const;
    virtual Calamity* getCalamity();
    virtual int getNumberOfRealty() const;
    virtual int64_t getIncome() const;
    virtual int getNewness() const { return 0; }
    virtual std::pair<int, int> getCoordsInBuildingLand() const;

    virtual bool isBuilt() const;

protected:
    int64_t building_cost_ = 0;
    int64_t building_time_ = 4; //in month
    Player* owner_ = nullptr;
    LandPlot* land_plot_ = nullptr;
    int number_of_realty_ = 0;

    Calamity* cur_calamity_ = nullptr;

    std::pair<int, int> coords_in_building_land_;

};
