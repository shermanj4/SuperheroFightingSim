#include "Hero.h"
#include "StrLib.h"
#include "Powers.h"
#include <iostream>
#include <ctime>




Hero::Hero(std::string& heroLine){
    std::vector<std::string> vectorLine = strSplit(heroLine, '|');
    mName = vectorLine[0];
    std::vector<std::string> powers = strSplit(vectorLine[1], ',');
    for(int i = 0; i < powers.size(); i++){
        mPowers.push_back(powerFactory(powers[i]));
    }
//    std::cout << vectorLine[2] << std::endl;
    mMaxHealth = std::stoi(vectorLine[2]);
    mCurrentHealth = mMaxHealth;
}

std::string Hero::getName(){
    return mName;
}

int Hero::getHealth(){
    return mCurrentHealth;
}

void Hero::printPowers(){
    std::cout << mName << " has the following powers..." << std::endl;
    for(int i = 0; i < mPowers.size(); i++){
        std::cout << mPowers[i]->getDescription() << std::endl;
    }
    std::cout << "---------------------------------------" << std::endl;
}

void Hero::printHealth(){
    std::cout << mName << "'s current health is: " << mCurrentHealth << std::endl;
}

Power* Hero::useRandomPower(){
    
    int i = std::rand() % mPowers.size();
    mPowers[i]->use();
    return mPowers[i];
}

void Hero::takeDamage(){
    mCurrentHealth = mCurrentHealth - 1;
}

void Hero::resetHealth(){
    mCurrentHealth = mMaxHealth;
}

Hero::~Hero(){
    for(int i = 0; i < mPowers.size(); i++){
        delete mPowers[i];
    }
}


