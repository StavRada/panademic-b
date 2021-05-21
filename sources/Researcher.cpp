#include "Researcher.hpp"

namespace pandemic{
const int cards_num = 5;

  Player& Researcher::discover_cure(Color c_){

    int count1 = 0;
    for( const auto & i : cards) {
            if( Board::city_color(i) == c_) {
                    count1++;
            }
    }
    if(count1 < cards_num) {
            throw invalid_argument{"ilegall"};
    }

    //delete 5 cards in the same color of desease
    count1 = 1;
    for(auto it = cards.begin(); it != cards.end(); count1++){
        if(count1 == cards_num) { break; }
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
