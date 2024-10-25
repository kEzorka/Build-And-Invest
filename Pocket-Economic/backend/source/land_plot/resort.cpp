#include "../../includes/land_plot/resort.h"
#include "../../includes/player.h"

void Resort::setCostOfNextUpdate(const int64_t& cost) {
    cost_of_next_update_ = cost;
}

void Resort::setCurIncome(const int64_t& income) {
    cur_income_ = income;
}

int64_t Resort::getIncome() const {
    return cur_income_;
}

void Resort::update() {
    if (update_stage_ >= 3) {
        throw std::runtime_error("can't update resort");
    }
    if (cost_of_next_update_ > owner_->getMoney()) {
        throw std::runtime_error("player doesnt have enough money to nuy this land");
    }
    owner_->setMoney(owner_->getMoney() - cost_of_next_update_);
    ++update_stage_;
    cost_of_next_update_ *= static_cast<int64_t>(update_stage_) * 2;
    cur_income_ *= 2;
}
