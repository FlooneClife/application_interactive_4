#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <stdint.h>
#include <vector>
#include <string.h>
#include <QMatrix4x4>
#include "transform.h"

class GameObject {

    char* name;
    GameObject* parent; //si c'est la scene, la référence est nulle
    std::vector<GameObject*> children;
    std::vector<QVector4D> vertices;
    std::vector<QVector4D> texCoords;
    bool drawable;

public:
    GameObject(char* name, GameObject* parent, bool drawable) {
        this->name = name;
        this->parent = parent;
        this->drawable = drawable;
    }

    void addChild(GameObject &child) {
        children.push_back(&child);
    }

    void assignParent(GameObject &parent) {
        this->parent = &parent;
    }
    
    void transform(float scale, QVector3D angle, QVector3D translation) {
        for(QVector4D p : vertices) {
            Transform::trTransform(scale, angle, translation, p);
        }
        for(GameObject* child : children) {
            for(QVector4D p : child->vertices) {
                Transform::trTransform(scale, angle, translation, p);
            }
        }
    }

private:

};

#endif // GAMEOBJECT_H
