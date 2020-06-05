#pragma once
#include <string>

const int FLIGHT = 1;
const int GADGETS = 2;
const int INTELLIGENCE = 3;
const int LASER = 4;
const int NATIONALISM = 5;
const int STRENGTH = 6;

class Power {
protected:
    std::string mDescription;
public:
    //Function: getDescription
    //Purpose: get the powers description
    //Input: none
    //Output: string
    std::string getDescription();
    //Function: getID
    //Purpose: get powers ID
    //Input: none
    //Output: none
    virtual int getID() = 0;
    //Function: use
    //Purpose: say something when the power is used
    //Input: none
    //Output: string
    virtual void use() = 0;
    //Function: fight
    //Purpose: determine which power wins in a fight
    //Input: Power*
    //Output: int
    virtual int fight(Power*) = 0;
};

class FlightPower : public Power {
public:
    //Function: Constructor
    //Purpose: set the powers description
    //Input: none
    //Output: none
    FlightPower();
    //Function: getID
    //Purpose: get powers ID
    //Input: none
    //Output: none
    int getID();
    //Function: use
    //Purpose: say something when the power is used
    //Input: none
    //Output: string
    void use();
    //Function: fight
    //Purpose: determine which power wins in a fight
    //Input: Power*
    //Output: int
    int fight(Power*);
};

class GadgetsPower : public Power {
public:
    //Function: Constructor
    //Purpose: set the powers description
    //Input: none
    //Output: none
    GadgetsPower();
    //Function: getID
    //Purpose: get powers ID
    //Input: none
    //Output: none
    int getID();
    //Function: use
    //Purpose: say something when the power is used
    //Input: none
    //Output: string
    void use();
    //Function: fight
    //Purpose: determine which power wins in a fight
    //Input: Power*
    //Output: int
    int fight(Power*);
};

class IntelligencePower : public Power {
public:
    //Function: Constructor
    //Purpose: set the powers description
    //Input: none
    //Output: none
    IntelligencePower();
    //Function: getID
    //Purpose: get powers ID
    //Input: none
    //Output: none
    int getID();
    //Function: use
    //Purpose: say something when the power is used
    //Input: none
    //Output: string
    void use();
    //Function: fight
    //Purpose: determine which power wins in a fight
    //Input: Power*
    //Output: int
    int fight(Power*);
};

class LaserPower : public Power {
public:
    //Function: Constructor
    //Purpose: set the powers description
    //Input: none
    //Output: none
    LaserPower();
    //Function: getID
    //Purpose: get powers ID
    //Input: none
    //Output: none
    int getID();
    //Function: use
    //Purpose: say something when the power is used
    //Input: none
    //Output: string
    void use();
    //Function: fight
    //Purpose: determine which power wins in a fight
    //Input: Power*
    //Output: int
    int fight(Power*);
};

class NationalismPower : public Power {
public:
    //Function: Constructor
    //Purpose: set the powers description
    //Input: none
    //Output: none
    NationalismPower();
    //Function: getID
    //Purpose: get powers ID
    //Input: none
    //Output: none
    int getID();
    //Function: use
    //Purpose: say something when the power is used
    //Input: none
    //Output: string
    void use();
    //Function: fight
    //Purpose: determine which power wins in a fight
    //Input: Power*
    //Output: int
    int fight(Power*);
};

class StrengthPower : public Power {
public:
    //Function: Constructor
    //Purpose: set the powers description
    //Input: none
    //Output: none
    StrengthPower();
    //Function: getID
    //Purpose: get powers ID
    //Input: none
    //Output: none
    int getID();
    //Function: use
    //Purpose: say something when the power is used
    //Input: none
    //Output: string
    void use();
    //Function: fight
    //Purpose: determine which power wins in a fight
    //Input: Power*
    //Output: int
    int fight(Power*);
};
//Function: powerFactory
//Purpose: create a new power based off of the string in the input file
//Input: string
//Output: Power*
Power* powerFactory(std::string powerString);
