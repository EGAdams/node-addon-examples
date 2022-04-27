#include "GameObject.h"
#include <iostream>
#include "Player.h"

GameObject::GameObject(){};
GameObject::~GameObject(){};
void GameObject::startGame() {
    std::cout << "starting game inside gameObject..." << std::endl;
}


