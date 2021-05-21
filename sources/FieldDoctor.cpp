#include "FieldDoctor.hpp"

namespace pandemic{
  Player& FieldDoctor::treat(City c_){

    if(city!=c_ && !Board::connect(city,c_)) {
            throw invalid_argument{"exception not connect city and this is not my city"};
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
