#include <iostream>
#include <vector>
#include "Fish.h"
#include "FlyingBird.h"

int main() {
    Fish nemo("Nemo");
    nemo.breathe();
    nemo.swim();

    FlyingBird Red("Red iz ANGRY BIRDS");
    Red.eat();
    Red.fly();
  
    Animal* myZoo[3];
    myZoo[0] = new Fish("Karasik");
    myZoo[1] = new Bird("Pingvinchiki");
    myZoo[2] = new FlyingBird("Papugay");

    for (int i = 0; i < 3; i++) {
        std::cout << "jivotnoye [" << i << "]: ";
        myZoo[i]->breathe(); 
    }
    for (int i = 0; i < 3; i++) {
        delete myZoo[i];
    }
    return 0;
}
