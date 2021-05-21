#include "Dispatcher.hpp"

namespace pandemic {
Player& Dispatcher::fly_direct(City c_){
        if(city==c_) {
                throw invalid_argument{"exception same city"};
        }

        if(!board.there_is_research_station(city)) {
                 return Player::fly_direct(c_);
             }
             city=c_;
        return *this;
}
}
