
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


namespace pandemic{
  class Medic: public Player{
    public:
      Medic(Board& board,City city) : Player(board,city,"Medic"){}
      Player& treat(City c) override;
      void funcionToMedic() override;
  };
}
