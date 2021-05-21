#include "GeneSplicer.hpp"

namespace pandemic{
        const int num_=5;
  Player& GeneSplicer::discover_cure(Color c_){

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
        it = cards.erase(it);
    }

    board.add_discover_cure(c_);
    return *this;
  }
}
