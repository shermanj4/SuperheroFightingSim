#pragma once
#include <string>
#include <vector>
#include "Powers.h"

class Hero {
private:
    int mMaxHealth;
    int mCurrentHealth;
    std::string mName;
    std::vector<Power*> mPowers;
public:
    //Function: Hero (parameterized)
    //Purpose: take in line and seperate and store the values accordingly
    //Input: string
    //Output: none
    Hero(std::string& heroLine);
    //Function: Hero (deconstructor)
    //Purpose: delete the power vector
    //Input: none
    //Output: none
    ~Hero();
    //Function: getName
    //Purpose: get the hero's name
    //Input: none
    //Output: string
    std::string getName();
    //Function: getHealth
    //Purpose: get the hero's current health
    //Input: none
    //Output: int
    int getHealth();
    //Function: printPowers
    //Purpose: print the hero's powers
    //Input: none
    //Output: none
    void printPowers();
    //Function: printHealth
    //Purpose: print the hero's name and health
    //Input: none
    //Output: none
    void printHealth();
    //Function: useRandomPower
    //Purpose: pick a random power to use
    //Input: none
    //Output: power*
    Power* useRandomPower();
    //Function: takeDamage
    //Purpose: decrease health by 1
    //Input: none
    //Output: none
    void takeDamage();
    //Function: resetHealth
    //Purpose: reset the heroes health
    //Input: none
    //Output: none
    void resetHealth();
};
