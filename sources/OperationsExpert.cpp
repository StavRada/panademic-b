#include "OperationsExpert.hpp"

using namespace std;


namespace pandemic{
    Player& OperationsExpert::build(){
      board.build_station(city);
      return *this;
    }
}
