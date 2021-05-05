#pragma once
#include <iostream>
#include <ostream>
#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
#include <string>
namespace pandemic {

    class Board {
      //     private: // need to check 
      //         Board();
      //        ~Board();
                 static std::map<City, std::set<City>> conector;
                std::set<City> HQstations;
                std::map<City, int> Inferctioncubes;

          public:
            Board();
            ~Board();
            bool is_clean();   
             bool isCureDiscovered(const Color type) const;
             int& operator[](City city);
             bool Board::CheckResearch(City city);
              void remove_cures(){};
              friend std::ostream &operator<<(std::ostream &os, const Board &c);
             //void Board::generateGameContentAtStartOfGame()
            int& operator[] (City city);
             //Board connectTo(City& target);	// Declares that this city is connected to another given city
    };					
}