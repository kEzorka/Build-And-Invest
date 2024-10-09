#pragma once

#include <iostream>

class Player;
class LandPlot;
class RealEstateAgency;
class Calamity;

class Realty {
public:
    virtual void setBuildingCost(const int64_t& cost);
    virtual void setBuildingTime(const int64_t& time);
    virtual void setOwner(Player* owner);
    virtual void setLandPlot(LandPlot* land_plot);
    virtual void setDemand(const int& demand);
    virtual void setSupply(const int& supply);
    virtual void setCalamity(Calamity* calamity);

    virtual int64_t getBuildingCost() const;
    virtual int64_t getBuildingTime() const;
    virtual Player* getOwner() const;
    virtual LandPlot* getLandPlot() const;
    virtual int getDemand() const;
    virtual int getSupply() const;
    virtual Calamity* getCalamity();

    virtual bool isBuilt() const;
    virtual void buyAdvert();

protected:
    int64_t building_cost_ = 0;
    int64_t building_time_ = 0;
    Player* owner_ = nullptr;
    LandPlot* lan_plot_ = nullptr;
    int demand_ = 0;
    int supply_ = 0;

    Calamity* cur_calamity_ = nullptr;

};
