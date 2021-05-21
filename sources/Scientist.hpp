
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"


namespace pandemic{
  class Scientist: public Player{
    private:
    int num_;
    public:
      Scientist(Board& b,City c,int num) : Player(b,c,"Scientist"),num_(num){}
      Player& discover_cure(Color c_) override;
  };
}
