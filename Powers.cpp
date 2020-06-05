#include "Powers.h"
#include "Hero.h"
#include "StrLib.h"
#include <iostream>
#include <vector>

std::string Power::getDescription(){
    return mDescription;
}

FlightPower::FlightPower(){
    mDescription = "Ability to Fly";
}

int FlightPower::getID(){
    return FLIGHT;
}

void FlightPower::use(){
    std::cout << "flies away, mayber far away from this place." << std::endl;
}

int FlightPower::fight(Power* otherPower){
//    if(otherPower->getID() == GADGETS){
//        std::cout << "GADGET WINS - Rope snares make it tough to fly away." << std::endl;
//        return -1;
//    }
    if(otherPower->getID() == INTELLIGENCE){
        std::cout << "FLIGHT WINS - They just fly out of range of the attack." << std::endl;
        return 1;
    }
    else if(otherPower->getID() == LASER){
        std::cout << "LASER WINS -  They have a good sniper shot so flying doesn't help." << std::endl;
        return -1;
    }
    else if(otherPower->getID() == NATIONALISM){
        std::cout << "FLIGHT WINS - They just fly out of range of the attack." << std::endl;
        return 1;
    }
    else if(otherPower->getID() == STRENGTH){
        std::cout << "FLIGHT WINS - They just fly out of range of the attack." << std::endl;
        return 1;
    }
    else{
        std::cout << "They both fly away and hit a tree." << std::endl;
        return -1;
    }
}

GadgetsPower::GadgetsPower(){
    mDescription = "Cool technology";
}

int GadgetsPower::getID(){
    return GADGETS;
}

void GadgetsPower::use(){
    std::cout << "uses what's (hopefully) the right tool for the job." << std::endl;
}

int GadgetsPower::fight(Power* otherPower){
    if(otherPower->getID() == FLIGHT){
        std::cout << "GADGET WINS - Rope snares make it tough to fly away." << std::endl;
        return 1;
    }
    else if(otherPower->getID() == INTELLIGENCE){
        std::cout << "INTELLIGENCE WINS - Intelligence outsmarts the gadget." << std::endl;
        return -1;
    }
    else if(otherPower->getID() == LASER){
        std::cout << "GADGET WINS -  The gadget blocks the laser somewhow (not really sure how)." << std::endl;
        return 1;
    }
    else if(otherPower->getID() == NATIONALISM){
        std::cout << "GADGET WINS - Nationalism doesn't really do anything anyways, the gadget wins easy." << std::endl;
        return 1;
    }
    else if(otherPower->getID() == STRENGTH){
        std::cout << "STRENGTH WINS - Superhuman strength smashes the gadget." << std::endl;
        return -1;
    }
    else{
        std::cout << "They both use gadgets and suffer major internal bleeding." << std::endl;
        return -1;
    }
}

IntelligencePower::IntelligencePower(){
    mDescription = "Ability to get a perfect SAT";
}

int IntelligencePower::getID(){
    return INTELLIGENCE;
}

void IntelligencePower::use(){
    std::cout << "uses superhuman intelligence." << std::endl;
}

int IntelligencePower::fight(Power* otherPower){
    if(otherPower->getID() == FLIGHT){
        std::cout << "FLIGHT WINS - Being supersmart won't help against flight." << std::endl;
        return -1;
    }
    else if(otherPower->getID() == GADGETS){
        std::cout << "INTELLIGENCE WINS - Intelligence outsmarts the gadget." << std::endl;
        return 1;
    }
    else if(otherPower->getID() == LASER){
        std::cout << "LASER WINS -  Attempted to calculate the speed and trajectory of the laser but was too slow." << std::endl;
        return -1;
    }
    else if(otherPower->getID() == NATIONALISM){
        std::cout << "INTELLIGENCE WINS - Nationalism doesn't really do anything anyways, intelligence wins easy." << std::endl;
        return 1;
    }
    else if(otherPower->getID() == STRENGTH){
        std::cout << "INTILLEGENCE WINS - Superhuman strength is useless against superhuman intelligence." << std::endl;
        return 1;
    }
    else{
        std::cout << "They both are supersmart yet somehow get the question wrong." << std::endl;
        return -1;
    }
}

LaserPower::LaserPower(){
    mDescription = "Ability to shoot lasers out of eyesockets";
}

int LaserPower::getID(){
    return LASER;
}

void LaserPower::use(){
    std::cout << "uses very accurate and deadly laserbeams." << std::endl;
}

int LaserPower::fight(Power* otherPower){
    if(otherPower->getID() == FLIGHT){
        std::cout << "LASER WINS - They have a good sniper shot so flying doesn't help." << std::endl;
        return 1;
    }
    else if(otherPower->getID() == GADGETS){
        std::cout << "GADGET WINS - The gadget blocks the laser somewhow (not really sure how)." << std::endl;
        return -1;
    }
    else if(otherPower->getID() == INTELLIGENCE){
        std::cout << "LASER WINS -  Attempted to calculate the speed and trajectory of the laser but was too slow." << std::endl;
        return 1;
    }
    else if(otherPower->getID() == NATIONALISM){
        std::cout << "LASER WINS - Nationalism doesn't really do anything anyways, laser wins easy." << std::endl;
        return 1;
    }
    else if(otherPower->getID() == STRENGTH){
        std::cout << "STRENGTH WINS - strength overpowers laser." << std::endl;
        return -1;
    }
    else{
        std::cout << "They both shoot lasers into each others eyes." << std::endl;
        return -1;
    }
}

NationalismPower::NationalismPower(){
    mDescription = "Ability to inspire the common folk to rise against the elite";
}

int NationalismPower::getID(){
    return NATIONALISM;
}

void NationalismPower::use(){
    std::cout << "yells AMERICA F**K YEAH!." << std::endl;
}

int NationalismPower::fight(Power* otherPower){
    if(otherPower->getID() == FLIGHT){
        std::cout << "FLIGHT WINS - Nationalism cannot effect someone who's flown away." << std::endl;
        return -1;
    }
    else if(otherPower->getID() == GADGETS){
        std::cout << "GADGET WINS - Nationalism doesn't really do anything anyways, the gadget wins easy." << std::endl;
        return -1;
    }
    else if(otherPower->getID() == INTELLIGENCE){
        std::cout << "INTELLIGENCE WINS -  Nationalism doesn't really do anything anyways, intelligence wins easy." << std::endl;
        return -1;
    }
    else if(otherPower->getID() == LASER){
        std::cout << "LASER WINS - Nationalism doesn't really do anything anyways, laser wins easy." << std::endl;
        return -1;
    }
    else if(otherPower->getID() == STRENGTH){
        std::cout << "STRENGTH WINS - Nationalism doesn't really do anything anyways, strength wins easy." << std::endl;
        return -1;
    }
    else{
        std::cout << "Equal amounts of nationalism never lead to anything good." << std::endl;
        return -1;
    }
}

StrengthPower::StrengthPower(){
    mDescription = "Ability to pick up a car with one hand";
}

int StrengthPower::getID(){
    return STRENGTH;
}

void StrengthPower::use(){
    std::cout << "SMASH!." << std::endl;
}

int StrengthPower::fight(Power* otherPower){
    if(otherPower->getID() == FLIGHT){
        std::cout << "FLIGHT WINS - They just fly out of range of the attack." << std::endl;
        return -1;
    }
    else if(otherPower->getID() == GADGETS){
        std::cout << "Strength WINS - The gadget gets smashed." << std::endl;
        return 1;
    }
    else if(otherPower->getID() == INTELLIGENCE){
        std::cout << "INTELLIGENCE WINS -  Superhuman strength is useless against superhuman intelligence." << std::endl;
        return -1;
    }
    else if(otherPower->getID() == LASER){
        std::cout << "STRENGTH WINS - strength overpowers laser." << std::endl;
        return 1;
    }
    else if(otherPower->getID() == NATIONALISM){
        std::cout << "STRENGTH WINS - Nationalism doesn't really do anything anyways, strength wins easy." << std::endl;
        return 1;
    }
    else{
        std::cout << "Two smashes doesn't really end well." << std::endl;
        return -1;
    }
}

Power* powerFactory(std::string powerString){
    if(powerString == "intel"){
        Power* intelligence = new IntelligencePower;
        return intelligence;
    }
    else if(powerString == "strength"){
        Power* strength = new StrengthPower;
        return strength;
    }
    else if(powerString == "laser"){
        Power* laser = new LaserPower;
        return laser;
    }
    else if(powerString == "gadget"){
        Power* gadget = new GadgetsPower;
        return gadget;
    }
    else if(powerString == "flight"){
        Power* flight = new FlightPower;
        return flight;
    }
    else{
        Power* national = new NationalismPower;
        return national;
    }
}


