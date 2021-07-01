#pragma once

#include "City.hpp"
#include "Board.hpp"
#include "Color.hpp"
#include <unordered_set>
using namespace std;

namespace pandemic{
  class Player{
    protected:
      Board& board;
      unordered_set<City> cards;
      City city;
      string type_player;
    public:
      //constractur

      Player(Board& b,City c,string type) : board(b),city(c),type_player(type){}

      //function
      virtual void funcionToMedic(){}
       Player& drive(City c_);
       Player& fly_charter(City c_);
       Player& fly_shuttle(City c_);
      virtual Player& fly_direct(City c_);
      virtual Player& build();
      virtual Player& discover_cure(Color c_);
      virtual Player& treat(City c_);

      string role(){return type_player;};
      virtual Player& take_card(City c_);
  };
}
