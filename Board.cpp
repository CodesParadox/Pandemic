#include "Board.hpp"
#include <iostream>
#include <map>
#include <string>
using namespace pandemic;
using namespace std;

namespace pandemic{


             Board::Board(){}
             bool Board::is_clean(){
                  return true;
             }
          
            int &Board::operator[](City c)
               {
                  return Inferctioncubes[c];
                    }    

        std::ostream &operator<<(std::ostream &os, const Board &c)
             {
                    return os;
             }
    }
      // City& City::connectTo(City &target)
      // {
      //       if (!isConnectedTo(target))
      //       {
      //             _connections.push_back(&target);
      //       }
      //       return *this;
      // }


      // bool Board::is_clean() {
      // for (auto[k, v] : cities) {
      //       if (v.get_disease_cubes() != 0) {
      //             return false;
      //       }
      // }
      // return true;
      // }

      // void Board::generateGameContentAtStartOfGame()
      // {
      //     this->generatePlayerCards();

      //     // Give each player four cards, while we have cards.
      //     for (int playerIndex = 0; playerIndex < this->getNumberOfPlayers(); playerIndex++) {
      //         for (int i = 0; i < 4; i++) {
      //             if (this->_playerWithdrawPile.size() == 0) {
      //                 break;
      //             } else {
      //                 this->getPlayer(playerIndex).addCard(this->_playerWithdrawPile.at(this->_playerWithdrawPile.size() - 1));
      //                 this->_playerWithdrawPile.pop_back();
      //             }
      //         }
      //         int i = RandomNumberGenerator::next(0, 6);
      //         // Give each player a random role card.
      //         RoleCard *p = new RoleCard(RoleCard::roleCardNames[i]);
      //         this->getPlayer(playerIndex).setRoleCard(p);
      //     }



    std::map<City, std::set<City>> Board::conector
           {
            {SanFrancisco,{LosAngeles, Chicago, Tokyo, Manila}},
            {Chicago,{SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
            {Atlanta,{Chicago, Miami, Washington}},
            {Montreal,{Chicago, Washington, NewYork}},
            {NewYork,{Montreal, Washington, London, Madrid}},
            {Washington,{Atlanta, NewYork, Montreal, Miami}},
            {London,{NewYork, Madrid, Essen, Paris}},
            {Madrid,{London, NewYork, Paris, SaoPaulo, Algiers}},
            {Paris,{Algiers, Essen, Madrid, Milan, London}},
            {Essen,{London, Paris,Milan, StPetersburg}},
            {Milan,{Essen, Paris, Istanbul}},
            {StPetersburg,{Essen, Istanbul, Moscow}},

            {LosAngeles,{SanFrancisco, Chicago, MexicoCity, Sydney}},
            {MexicoCity,{LosAngeles, Chicago, Miami, Lima, Bogota}},
            {Miami,{Atlanta, MexicoCity, Washington, Bogota}},
            {Bogota,{MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
            {Lima,{MexicoCity, Bogota, Santiago}},
            {Santiago,{Lima}},
            {BuenosAires,{Bogota, SaoPaulo}},
            {SaoPaulo,{Bogota, BuenosAires, Lagos, Madrid}},
            {Lagos,{SaoPaulo, Khartoum, Kinshasa}},
            {Khartoum,{Cairo ,Lagos, Kinshasa, Johannesburg}},
            {Kinshasa,{Lagos, Khartoum, Johannesburg}},
            {Johannesburg,{Kinshasa, Khartoum}}
        };

        
