#include "Scientist.hpp"

namespace pandemic{

  Player& Scientist::discover_cure(Color c_){

    if(!board.there_is_research_station(city)) {
            throw invalid_argument{"exception has no research station"};
    }
    int count1 = 0;
    for( const auto & i : cards) {
                    count1++;
    }
    if(count1 < num_) {
            throw invalid_argument{"ilegall"};
    }

    //delete 5 cards in the same color of desease
    count1 = 1;
    for(auto it = cards.begin(); it != cards.end(); count1++){
        if(count1 == num_) { break; }
        if(c_ ==Board::city_color(*it)) {
            it = cards.erase(it);
        }else {
            ++it;
        }
    }
    board.add_discover_cure(c_);
    return *this;
  }

 }
