
#include <iostream>
#include "doctest.h"
#include "Board.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Scientist.hpp"
#include "Researcher.hpp"
#include "Medic.hpp"
#include "City.hpp"
#include "Virologist.hpp"
#include "GeneSplicer.hpp"
#include "FieldDoctor.hpp"
#include <stdexcept>

using namespace pandemic;
using namespace std;

    Board b1;
OperationsExpert operationsExpert{b1, City::Algiers};
Dispatcher dispatcher{b1,  City::Cairo};
Scientist scientist{b1,  City::Washington, 4};
Researcher researcher{b1,  City::Washington};
Medic medic{b1, City::Washington};
Virologist virologist{b1,  City::Bogota};
GeneSplicer geneSplicer{b1,  City::Delhi};
FieldDoctor fieldDoctor{b1,  City::Essen};



TEST_CASE("Checking the operator []"){
	Board b;  
	b[City::Washington] = 3;       
    CHECK_NOTHROW(b[City::Algiers] = 3);
    CHECK_NE(b[City::Algiers], 4);
    b[City::Bangkok] = 2; 
    CHECK(b[City::Bangkok] == 2);
    b[City::Madrid] = 2;
    CHECK(b[City::Madrid] == 2);
    b[City::BuenosAires] = 1; 
    CHECK(b[City::BuenosAires] == 1);
    b[City::Washington] = 1;
    b[City::Madrid] = 0;
    CHECK(b[City::Washington] != 3);
    CHECK(b[City::Madrid] == 0);
    b[City::BuenosAires] = 2;
    CHECK(b[City::BuenosAires] != 0);
    CHECK(b[City::BuenosAires] == 2);
    b[City::LosAngeles] = 4;
    CHECK(b[City::LosAngeles] == 4);
    b[City::Lima] = 0;
    CHECK(b[City::Lima] == 0);
}

TEST_CASE("Checking players")
{
    CHECK(operationsExpert.role() == "OperationsExpert");
    CHECK(dispatcher.role() == "Dispatcher");
    CHECK(scientist.role() == "Scientist");
    CHECK(researcher.role() == "Researcher");
    CHECK(medic.role() == "Medic");
    CHECK(virologist.role() == "Virologist");
    CHECK(geneSplicer.role() == "GeneSplicer");
    CHECK(fieldDoctor.role() == "FieldDoctor");
    CHECK_NOTHROW(operationsExpert.build());
    CHECK_THROWS(operationsExpert.fly_direct( City::Washington)); 
    CHECK_NOTHROW(dispatcher.drive( City::Bangkok));
    CHECK_NOTHROW(dispatcher.fly_direct( City::Atlanta)); 
    scientist.take_card( City::Washington);
    scientist.take_card( City::Beijing);
    scientist.take_card( City::Lima);
    scientist.take_card( City::Karachi);
    b1[ City::Beijing] = 4;
    medic.treat(City::Beijing);
    CHECK_NOTHROW(scientist.discover_cure(Color::Red));     
    CHECK_NOTHROW(researcher.discover_cure(Color::Yellow)); 
    CHECK(b1[City::Beijing] == 0);   
    geneSplicer.take_card( City::Bangkok);                    
    CHECK_NOTHROW(virologist.treat( City::StPetersburg)); 
    geneSplicer.take_card( City::London);
    geneSplicer.take_card( City::LosAngeles);
    CHECK(b1[ City::StPetersburg] == 0);
    geneSplicer.take_card( City::Tokyo);
    geneSplicer.take_card( City::Taipei);
    CHECK_NOTHROW(geneSplicer.discover_cure( Color::Black)); 
    CHECK_NOTHROW(fieldDoctor.treat( City::London));        
}

