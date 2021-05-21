#include "Virologist.hpp"

namespace pandemic {
Player& Virologist::treat(City c_){
        if(city!=c_) {
                if(!cards.contains(c_)) {
                        throw invalid_argument{"exception you not have card"};
                }
                cards.erase(c_);
        }
        if(board[c_]==0) {
                throw invalid_argument{"no more cubes"};
        }
        // discover cure this city
        if(board.exsist_discover_cure(c_)) {
                board[c_]=0;
        }else{
                board[c_]--;
        }

        return *this;
}
}
