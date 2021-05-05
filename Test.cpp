
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
#include "Color.hpp"
#include "Virologist.hpp"
#include "GeneSplicer.hpp"
#include "FieldDoctor.hpp"
#include <stdexcept>
#include <string>
using namespace pandemic;
using namespace std;

    Board b1;
OperationsExpert operationsExpert{b1, Algiers};
Dispatcher dispatcher{b1, Cairo};
Scientist scientist{b1, Washington, 4};
Researcher researcher{b1, Washington};
Medic medic{b1, Washington};
Virologist virologist{b1, Bogota};
GeneSplicer geneSplicer{b1, Delhi};
FieldDoctor fieldDoctor{b1, Essen};



TEST_CASE("Checking the operator []"){
	Board b;  
	b[Washington] = 3;       
    CHECK_NOTHROW(b[Algiers] = 3);
    CHECK_NE(b[Algiers], 4);
    b[Bangkok] = 2; 
    CHECK(b[Bangkok] == 2);
    b[Madrid] = 2;
    CHECK(b[Madrid] == 2);
    b[BuenosAires] = 1; 
    CHECK(b[BuenosAires] == 1);
    b[Washington] = 1;
    b[Madrid] = 0;
    CHECK(b[Washington] != 3);
    CHECK(b[Madrid] == 0);
    b[BuenosAires] = 2;
    CHECK(b[BuenosAires] != 0);
    CHECK(b[BuenosAires] == 2);
    b[LosAngeles] = 4;
    CHECK(b[LosAngeles] == 4);
    b[Lima] = 0;
    CHECK(b[Lima] == 0);
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
    CHECK_THROWS(operationsExpert.fly_direct(Washington)); 
    CHECK_NOTHROW(dispatcher.drive(Bangkok));
    CHECK_NOTHROW(dispatcher.fly_direct(Atlanta)); 
    scientist.take_card(Washington);
    scientist.take_card(Beijing);
    scientist.take_card(Lima);
    scientist.take_card(Karachi);
    b1[Beijing] = 4;
    medic.treat(Beijing);
    CHECK_NOTHROW(scientist.discover_cure(Red));     
    CHECK_NOTHROW(researcher.discover_cure(Yellow)); 
    CHECK(b1[Beijing] == 0);   
    geneSplicer.take_card(Bangkok);                    
    CHECK_NOTHROW(virologist.treat(StPetersburg)); 
    geneSplicer.take_card(London);
    geneSplicer.take_card(LosAngeles);
    CHECK(b1[StPetersburg] == 0);
    geneSplicer.take_card(Tokyo);
    geneSplicer.take_card(Taipei);
    CHECK_NOTHROW(geneSplicer.discover_cure(Black)); 
    CHECK_NOTHROW(fieldDoctor.treat(London));        
}

Board b;
OperationsExpert operationsExpert{b, Atlanta};
Dispatcher dispatcher{b, Atlanta};
Scientist scientist{b, Atlanta, 3};
Researcher researcher{b, Atlanta};
Medic medic{b, Atlanta};
Virologist virologist{b, Atlanta};
GeneSplicer geneSplicer{b, Atlanta};
FieldDoctor fieldDoctor{b, Atlanta};

TEST_CASE("Not Possible"){
            CHECK_THROWS(operationsExpert.drive(SaoPaulo));
            CHECK_THROWS(dispatcher.drive(Cairo));
            CHECK_THROWS(scientist.drive(SaoPaulo));
            CHECK_THROWS(researcher.drive(Cairo));
            CHECK_THROWS(medic.drive(SaoPaulo));
            CHECK_THROWS(operationsExpert.fly_direct(Madrid));
            CHECK_NOTHROW(dispatcher.fly_direct(NewYork));
            CHECK_THROWS(scientist.fly_direct(Madrid));
            CHECK_THROWS(virologist.drive(Cairo));
            CHECK_THROWS(geneSplicer.drive(SaoPaulo));
            CHECK_THROWS(fieldDoctor.drive(Cairo));
            CHECK_THROWS(researcher.fly_direct(London));
            CHECK_THROWS(medic.fly_direct(London));
            CHECK_THROWS(virologist.fly_direct(Paris));
            CHECK_THROWS(geneSplicer.fly_direct(London));
            CHECK_THROWS(fieldDoctor.fly_direct(NewYork));

}
