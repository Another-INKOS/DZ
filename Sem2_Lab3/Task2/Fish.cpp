#include "Fish.h"

Fish::Fish(std::string n) : Animal(n) {}

void Fish::breathe() {
    std::cout << name << " jabrami bul bul" << std::endl;
}

void Fish::swim() {
    std::cout << name << " plivet v kompote (znachit mi sidim v bolote)" << std::endl;
}
