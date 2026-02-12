#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    int id;             //Private: only Animal can read/write this

protected:
    int energy;        //Protected: Animal + derived classes can read/write this

public:
    string name;       //Public: anyone can read/write this (including main)


Animal(string name, int id) {
        this->name = name;
        this->id = id;
        this->energy = 100; // Default energy level
    }

    void rest() {
        energy += 10; // Resting increases energy
        cout << name << " rests. Energy: " << energy << endl;
    }

    void showId() {
        cout << name << " has id: " << id << endl;
    }

};

//Dog is a derived class (inherirts from Animal)
class Dog : public Animal {
public:
    Dog(string name, int id) : Animal(name, id) {}

    //Derived class can access protected members (energy)
    void play() {
        energy -= 20; // OK: energy is protected in Animal
        cout << name << " plays. Energy = " << energy << endl;
    }

//main() can indirectly modify protected data through public method
void setEnergy(int e) {
        energy = e; // OK: energy is protected in Animal
    }
};

//Another derived class
class Cat : public Animal {
public: 
    Cat(string name, int id) : Animal(name, id) {}

    void sleep() {
        energy += 5; // OK: protected
        cout << name << " sleeps. Energy = " << energy << endl;
    }
};

int main() {
    cout << "=== Creating objects ===" << endl;

    Animal a("Generic Animal", 1);
    Dog d("Mortadelo", 2);
    Cat c("Filemon", 3);

    cout << "\n=== public access ===" << endl;
    a.name = "RenamedAnimal";          // OK: public
    cout << "Animal name: " << a.name << endl;

    cout << "\n=== calling public methods ===" << endl;
    a.rest();                          // updates protected via animal method
    d.play();                          // updates protected via dog method
    c.sleep();                         // updates protected via cat method

    cout << "\n=== private: not accessible from main ===" << endl;
    // a.id = 10;                      // ERROR: id is private
    // d.id = 10;                      // ERROR: id is private
    a.showId();                       // OK: indirect access via public method

    cout << "\n=== protected: not directly accessible from main ===" << endl;
    // a.energy = 50;                  // ERROR: protected
    // d.energy = 50;                  // ERROR: protected

    cout << "\n=== main can modify protected indirectly (through a derived class method) ===" << endl;
    d.setEnergy(2'0);                  // main() does NOT touch energy directly
    d.play();

    cout << "\n=== Done ===" << endl;
    return 0;
}
