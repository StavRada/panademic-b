#include "Player.hpp"
#include <algorithm>
namespace pandemic {

Player& Player::drive(City c_){
        if(city==c_) {
                throw invalid_argument{"exception not same type drive"};
        }
        if(!Board::connect(city,c_)) {
                throw invalid_argument{"exception connect drive"};
        }
        city=c_;
        funcionToMedic();
        return *this;
}

Player& Player::fly_direct(City c_){
        if(city==c_) {
                throw invalid_argument{"exception you already in"};
        }
        if(!cards.contains(c_)) {
                throw invalid_argument{"exception dont have option"};
        }
        city= c_;
        cards.erase(c_);
        funcionToMedic();
        return *this;
}

Player& Player::fly_charter(City c_){
        if(city==c_) {
                throw invalid_argument{"exception you already in"};
        }
        if(!cards.contains(city)) {
                throw invalid_argument{"exception dont have option"};
        }

        cards.erase(city);
        city = c_;
        funcionToMedic();
        return *this;
}

Player& Player::fly_shuttle(City c_){

        if(city==c_) {
                throw invalid_argument{"exception you already in"};
        }
        if (board.there_is_research_station(city) && board.there_is_research_station(c_)) {
                city=c_;
        }else{
                throw invalid_argument{"exception dont have option"};
        }
        funcionToMedic();
        return *this;
}

Player& Player::build(){
        if(!cards.contains(city)) {
                throw invalid_argument{"exception build"};
        }

        board.build_station(city);
        cards.erase(city);

        return *this;
}



Player& Player::discover_cure(Color c_){
        if(!board.there_is_research_station(city)) {
                throw invalid_argument{"exception has no research station"};
        }
        int count1 = 0;
        for( const auto & i : cards) {
                if( Board::city_color(i) == c_) {
                        count1++;
                }
        }
        const int num = 5;

        if(count1 < num) {
                throw invalid_argument{"ilegall"};
        }

        //delete 5 cards in the same color of desease
        count1 = 1;
        for(auto it = cards.begin(); it != cards.end(); count1++) {
                if(count1 == num) { break; }
                if(c_ ==Board::city_color(*it)) {
                        it = cards.erase(it);
                }else {
                        ++it;
                }
        }

        board.add_discover_cure(c_);

        return *this;

}


Player& Player::treat(City c_){
        if(city!=c_) {
                throw invalid_argument{"exception you not here"};
        }

        if(board[c_]<=0) {
                throw invalid_argument{"no more cubes"};
        }

        // discover cure in this city

        if(board.exsist_discover_cure(c_)) {
                board[c_]=0;
        }else{
                board[c_]--;
        }
        return *this;
}
Player& Player::take_card(City c_){
        cards.insert(c_);
        return *this;
}
}
