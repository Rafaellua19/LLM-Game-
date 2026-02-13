#include <iostream>
#include <string>

using namespace std;

/*

HELLO EVERYONE! THIS IS A SIMPLE C++ PROGRAM TO DEMONSTRATE THE CONCEPT OF OBJECTS AND CLASSES.

IF YOU THINK ABOUT THIS IS SOME KIND OF CALCULATOR, BUT INSTEAD OF CALCULATING NUMBERS, IT CALCULATES THE ENERGY LEVEL OF A DOG NAMED MAX.

IT CAN BE MORE PLAYFULL THAN A CALCULATOR, BECAUSE IT CAN BARK, EAT, REST, PLAY AND WALK. ALL THESE ACTIONS AFFECT THE ENERGY LEVEL OF MAX.

YOU CAN CUSTOMIZE THE NAME, CREATE NEW FUNCTIONS, OR EVEN CREATE NEW ANIMAL CLASSES LIKE CAT, BIRD, ETC. THE POSSIBILITIES ARE ENDLESS!

*/

class Animal {
    private:
    string name;
    int energy;

protected:
void increaseEnergy (int amount) {
energy += amount;
if (energy > 100) energy = 100;
}

void decreaseEnergy (int amount) {
energy -= amount;
if (energy < 0) { 
energy = 0;
}
}

string getName() {
return name;
}

public:

Animal(string name, int energy) {
this->name = name;
this->energy = energy;
}

void showEnergy() {
cout << name << " has energy = " << energy << endl;
}
};

class Dog : public Animal {
public:
Dog(string name, int energy) : Animal(name, energy) {}

void bark() {
cout << getName() << " says: It's wicked outside Woof!" << endl;
decreaseEnergy(80);
}

void rest() {
cout << getName() << " is resting " << endl;
increaseEnergy(20);
}

void play() {
cout << getName() << " is playing with his ball " << endl;
decreaseEnergy(15);
}

void walk() {
cout << getName() << " is walking by your side " << endl;
decreaseEnergy(20);
}
};
