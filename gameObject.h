#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <stdint.h>
#include <vector>
#include <string.h>

//mesh à chaque gameobject
//hitbox
//drawable?


class GameObject {

    char* name;
    GameObject parent; //si c'est la scene, la référence est nulle
    std::vector<GameObject> children;

public:
    GameObject();

    void addChild(GameObject &child) {
        children.push_back(child);
    }

    void assignParent(GameObject &parent) {
        this->parent = parent;
    }

private:

};

#endif // GAMEOBJECT_H
