#include "Hero.h"
#include "Powers.h"
#include <iostream>
#include <fstream>

//Function: loadHeroes
//Purpose: load in the heroes from the text file
//Input: string and vector
//Output: none
void loadHeroes(std::string file, std::vector<Hero*>& hero){
    hero.clear();
    std::ifstream fileInput(file);
    // check if file is open
    if(fileInput.is_open()){
        // check if file still has lines
        while(fileInput.eof() != true){
            std::string line;
            std::getline(fileInput, line);
            //create new dynamic variable
            Hero* newHero = new Hero(line);
            hero.push_back(newHero);
        }
        std::cout << hero.size() << " heroes loaded." << std::endl;
    }
    else{
        std::cout << "Error" << std::endl;
    }
}

//Function: printRoster
//Purpose: print the heroes powers
//Input: vector
//Output: none
void printRoster(std::vector<Hero*>& hero){
    //loop through and print powers
    for(int i = 0; i < hero.size(); i++){
        hero[i]->printPowers();
    }
}

//Function: selectHero
//Purpose: select a hero to fight
//Input: vector and string
//Output: Hero pointer
Hero* selectHero(std::vector<Hero*>& heroVector, std::string& input){
    
    if(input == "0"){
        return heroVector[0];
    }
    else if(input == "1"){
        return heroVector[1];
    }
    else if(input == "2"){
        return heroVector[2];
    }
    else if(input == "3"){
        return heroVector[3];
    }
    else if(input == "4"){
        return heroVector[4];
    }
    else if(input == "5"){
        return heroVector[5];
    }
    else if(input == "6"){
        return heroVector[6];
    }
    else if(input == "7"){
        return heroVector[7];
    }
    else if(input == "8"){
        return heroVector[8];
    }
    else{
        return heroVector[9];
    }
    
}

//Function: heroCombat
//Purpose: fight two heroes
//Input: vector
//Output: none
void heroCombat(std::vector<Hero*>& heroes){
    //loop through hero vector and get their names
    for(int i = 0; i < heroes.size(); i++){
        std::cout << i << ": " << heroes[i]->getName() << std::endl;
    }
    //user input interface
    std::string input = " ";
    std::string input2 = " ";
    std::cout << "Select 2 heroes to fight." << std::endl;
    std::cout << "First hero: ";
    std::cin >> input;
    std::cout << std::endl;
    std::cout << "Second hero: ";
    std::cin >> input2;
    //call the select hero functions
    Hero* hero1 = selectHero(heroes, input);
    
    Hero* hero2 = selectHero(heroes, input2);
    //loop to see if user chose the same two heroes
    while(selectHero(heroes, input) == selectHero(heroes, input2)){
        std::cout << "error" << std::endl;
        std::cout << "Select 2 heroes to fight." << std::endl;
        std::cout << "First hero: ";
        std::cin >> input;
        std::cout << std::endl;
        std::cout << "Second hero: ";
        std::cin >> input2;
        hero1 = selectHero(heroes, input);
        
        hero2 = selectHero(heroes, input2);
    }
    //loop the fight until one hero runs out of health
    while(hero1->getHealth() != 0 || hero2->getHealth() != 0){
        hero1->printHealth();
        hero2->printHealth();
        std::cout << hero1->getName() << " ";
        Power* power1 = hero1->useRandomPower();
        std::cout << hero2->getName() << " ";
        Power* power2 = hero2->useRandomPower();
        
        if(power1->fight(power2) == -1){
            hero1->takeDamage();
            
        }
        else if(power2->fight(power1) == -1){
            hero2->takeDamage();
            
        }
        
        std::cout << "--------------------------------------------------------------" << std::endl;
        //reset health at the end of the fight
        if(hero1->getHealth() == 0){
            std::cout << hero2->getName() << " WINS!!!" << std::endl;
            hero1->resetHealth();
            break;
        }
        else if(hero2->getHealth() == 0){
            std::cout << hero1->getName() << " WINS!!!" << std::endl;
            hero2->resetHealth();
            break;
        }
        //it's a tie if both heroes hit 0 health at the same time
        else if(hero1->getHealth() == 0 && hero2->getHealth() == 0){
            std::cout << "IT'S A TIE, WOW" << std::endl;
        }
        
        
        
    }
    
    
    
    
}

int main(){
    //seed the number generator
    std::srand(std::time(0));
    std::string choice = " ";
    std::vector<Hero*> heroes;
    //Hero myHero("Superman|strength,flight,laser|5");
    //myHero.printHealth();
    // interface
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Load Heroes" << std::endl;
    std::cout << "2. Print Hero Roster" << std::endl;
    std::cout << "3. Hero Fight!" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << "> ";
    std::cin >> choice;
    //make sure user loads a file before choosing other options
    while(choice == "2" || choice == "3"){
        std::cout << "error: please load heroes" << std::endl;
        std::cout << "1. Load Heroes" << std::endl;
        std::cout << "2. Print Hero Roster" << std::endl;
        std::cout << "3. Hero Fight!" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "> ";
        std::cin >> choice;
    }
    //check to see if user chose a valid option
    while(choice != "1" && choice != "2" && choice != "3" && choice != "4"){
        std::cout << "error: please choose a valid option" << std::endl;
        std::cout << "1. Load Heroes" << std::endl;
        std::cout << "2. Print Hero Roster" << std::endl;
        std::cout << "3. Hero Fight!" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "> ";
        std::cin >> choice;
    }
    
    // loop to make sure user doesn't quit
    while(choice != "4"){
        if(choice == "1"){
            std::string input;
            std::cout << "Enter a file to load: ";
            std::cin >> input;
            loadHeroes(input, heroes);
            std::cout << "Choose an option:" << std::endl;
            std::cout << "1. Load Heroes" << std::endl;
            std::cout << "2. Print Hero Roster" << std::endl;
            std::cout << "3. Hero Fight!" << std::endl;
            std::cout << "4. Quit" << std::endl;
            std::cout << "> ";
            std::cin >> choice;
            while(choice != "1" && choice != "2" && choice != "3" && choice != "4"){
                std::cout << "error: please choose a valid option" << std::endl;
                std::cout << "1. Load Heroes" << std::endl;
                std::cout << "2. Print Hero Roster" << std::endl;
                std::cout << "3. Hero Fight!" << std::endl;
                std::cout << "4. Quit" << std::endl;
                std::cout << "> ";
                std::cin >> choice;
            }
            //print the heroes if choice is 2
            if(choice == "2"){
                std::cout << "The following " << heroes.size() << " heroes are loaded..." << std::endl;
                printRoster(heroes);
                std::cout << "Choose an option:" << std::endl;
                std::cout << "1. Load Heroes" << std::endl;
                std::cout << "2. Print Hero Roster" << std::endl;
                std::cout << "3. Hero Fight!" << std::endl;
                std::cout << "4. Quit" << std::endl;
                std::cout << "> ";
                std::cin >> choice;
                while(choice != "1" && choice != "2" && choice != "3" && choice != "4"){
                    std::cout << "error: please choose a valid option" << std::endl;
                    std::cout << "1. Load Heroes" << std::endl;
                    std::cout << "2. Print Hero Roster" << std::endl;
                    std::cout << "3. Hero Fight!" << std::endl;
                    std::cout << "4. Quit" << std::endl;
                    std::cout << "> ";
                    std::cin >> choice;
                }
            }
            //fight the heroes
            while(choice == "3"){
            
                heroCombat(heroes);
                std::cout << "Choose an option:" << std::endl;
                std::cout << "1. Load Heroes" << std::endl;
                std::cout << "2. Print Hero Roster" << std::endl;
                std::cout << "3. Hero Fight!" << std::endl;
                std::cout << "4. Quit" << std::endl;
                std::cout << "> ";
                std::cin >> choice;
                //make sure the user chose a valid option 
                while(choice != "1" && choice != "2" && choice != "3" && choice != "4"){
                    std::cout << "error: please choose a valid option" << std::endl;
                    std::cout << "1. Load Heroes" << std::endl;
                    std::cout << "2. Print Hero Roster" << std::endl;
                    std::cout << "3. Hero Fight!" << std::endl;
                    std::cout << "4. Quit" << std::endl;
                    std::cout << "> ";
                    std::cin >> choice;
                }
            
            }
            //quit and delete the data
            if(choice == "4"){
                std::cout << "Quitting" << std::endl;
                for(int i = 0; i < heroes.size(); i++){
                    delete heroes[i];
                }
            }
            
        }
        
    }
    
    
    return 0;
}
