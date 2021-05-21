#include "Medic.hpp"

namespace pandemic{
  Player& Medic::treat(City c_){
    if(city!=c_) {
            throw invalid_argument{"exception you not here"};
    }
    if(board[c_]==0) {
            throw invalid_argument{"no more cubes"};
    }

    board[c_]=0;

    return *this;
  }

  void Medic::funcionToMedic(){
  if(board.exsist_discover_cure(city)){
    board[city]=0;
  }
}
}
