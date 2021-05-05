#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <string>
#include <iostream>


namespace pandemic {

// enum class Role
// {
//     GeneSplicer,
//     Dispatcher,
//     Medic,
//     OperationsExpert,
//     Virologist,
//     Researcher,
//     Scientist,
//     FieldDoctor
// };

    class Player {


    protected:
        Board &board;
        City city;
        std::string roler;
        std::set<City> cards;


        // private: 
        //     Board b;
        //     City c;
        //     const std::string player_role;
        //     std::string name;
        //     //Card* useExtraPlannerCard();
        //     //Card* removeCard(int index);
         
        public:
        //////////////Constructors//////////////////
           // Player();         
            Player(Board& b, City c, std::string r) :board(b), city(c), roler(r){};;
            ~Player();

            Player& drive(City c);
            Player& fly_direct(City c);
            Player& fly_charter(City c);
            Player& fly_shuttle(City c);
            Player& build();
            Player& discover_cure(Color c);
            Player& treat();
            Player& treat(City c);
           // const std::string role(); 
            Player& take_card(City c);
            std::string &role(){return roler;}
          

    };
}
/* 
      //modify playactions
      class Player: public PlayerAction{
      Player* playerAction;
      public:
      Player(PlayerAction *playerAction);

      PlayerRoleCard();

      void doAction(Player* player);
            }


      class Scientist: public PlayerRoleCard {
      PlayerAction* playerAction;
      std :: string name = "Scientist";

      public:
      Scientist(PlayerAction *playerAction);

      void doAction(Player* player);

      std::string &getName() ;

      };


      class OperationsExpert: public PlayerRoleCard {
      PlayerAction* playerAction;
      std :: string name = "OperationsExpert";

      public:
      OperationsExpert(PlayerAction *playerAction);

      void doAction(Player* player);

      std::string &getName() ;

      };


      class Medic: public PlayerRoleCard {
      PlayerAction* playerAction;
      std :: string name = "Medic";

      public:
      Medic(PlayerAction *playerAction);

      void doAction(Player* player);

      std::string &getName() ;

      }; 
      
 */
