#pragma once

#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
using namespace std;

namespace pandemic{
  class Board{
  private:

      map<City,int> cube;
      set<City> station;
      set<Color> discover_cure;
      static map<City,Color> colors;
      static map<City,set<City>> neib;
    public:
      static Color city_color(City c);
      static bool connect(City& c1 ,City& c2);

      void add_discover_cure(Color c_);
      bool exsist_discover_cure(City c_);
      void build_station(City c);
      bool there_is_research_station(City c);

      bool is_clean();
      void remove_cures();
      void remove_stations();
      int & operator[]( City c );
      friend ostream& operator<<(ostream& os,Board const & b);
  };
}
