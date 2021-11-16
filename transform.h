#include <QVector3D>
#include <QVector4D>
#include <QMatrix4x4>
#include <math.h>
#ifndef TRANSFORM_H
#define TRANSFORM_H


class Transform
{
    //point p(x,y,z,1) = positions
    //versor v(x,y,z,0) = directions

//    float s;                //uniform scale
//    QGraphicsRotation r;    //rotation
//    QVector3D t;            //translation
//    QMatrix4x4 m;           //final matrix

public:
    Transform();

    static QVector4D trScaling(float scale, QVector4D p) {
        QMatrix4x4 m = matScaling(scale);
        return operator*(m, p); //result = (x,y,z,1)
    }

    static QVector4D trTranslation(QVector3D t, QVector4D p) {
        QMatrix4x4 m = matTranslation(t);
        return operator*(m, p);
    }

    static QVector4D trRotationX(float angle, QVector4D p) {
        QMatrix4x4 m = QMatrix4x4(1.0, 0.0, 0.0, 0.0,
                                  0.0, cos(angle), -sin(angle), 0.0,
                                  0.0, sin(angle), cos(angle), 0.0,
                                  0.0, 0.0, 0.0, 1.0);
        return operator*(m, p);
    }

    static QVector4D trRotationY(float angle, QVector4D p) {
        QMatrix4x4 m = QMatrix4x4(cos(angle), 0.0, sin(angle), 0.0,
                                  0.0, 1.0, 0.0, 0.0,
                                  -sin(angle), 0.0, cos(angle), 0.0,
                                  0.0, 0.0, 0.0, 1.0);
        return operator*(m, p);
    }

    static QVector4D trRotationZ(float angle, QVector4D p) {
        QMatrix4x4 m = QMatrix4x4(cos(angle), -sin(angle), 0.0, 0.0,
                                  sin(angle), cos(angle), 0.0, 0.0,
                                  0.0, 0.0, 1.0, 0.0,
                                  0.0, 0.0, 0.0, 1.0);
        return operator*(m, p);
    }

    static QVector4D trRotation(QVector3D angle, QVector4D p) {
        QMatrix4x4 rotate = matRotation(angle);
        return operator*(rotate, p);
    }

    static QVector4D trTransform(float scale, QVector3D angle, QVector3D translation, QVector4D p) {
        QMatrix4x4 s = matScaling(scale);
        QMatrix4x4 r = matRotation(angle);
        QMatrix4x4 t = matTranslation(translation);

        return operator*(operator*(operator*(s, r), t), p);
    }

private:
    static QMatrix4x4 matScaling(float scale) {
        return QMatrix4x4(scale, 0.0, 0.0, 0.0,
                          0.0, scale, 0.0, 0.0,
                          0.0, 0.0, scale, 0.0,
                          0.0, 0.0, 0.0, 1.0);
    }

    static QMatrix4x4 matTranslation(QVector3D t) {
        return QMatrix4x4(1.0, 0.0, 0.0, t.x(),
                          0.0, 1.0, 0.0, t.y(),
                          0.0, 0.0, 1.0, t.z(),
                          0.0, 0.0, 0.0, 1.0);
    }

    static QMatrix4x4 matRotation(QVector3D angle) {
        QMatrix4x4 rX = QMatrix4x4(1.0, 0.0, 0.0, 0.0,
                                   0.0, cos(angle.x()), -sin(angle.x()), 0.0,
                                   0.0, sin(angle.x()), cos(angle.x()), 0.0,
                                   0.0, 0.0, 0.0, 1.0);
        QMatrix4x4 rY = QMatrix4x4(cos(angle.y()), 0.0, sin(angle.y()), 0.0,
                                   0.0, 1.0, 0.0, 0.0,
                                   -sin(angle.y()), 0.0, cos(angle.y()), 0.0,
                                   0.0, 0.0, 0.0, 1.0);
        QMatrix4x4 rZ = QMatrix4x4(cos(angle.z()), -sin(angle.z()), 0.0, 0.0,
                                   sin(angle.z()), cos(angle.z()), 0.0, 0.0,
                                   0.0, 0.0, 1.0, 0.0,
                                   0.0, 0.0, 0.0, 1.0);
        return operator*(operator*(rX, rY), rZ);
    }

};


#endif // TRANSFORM_H
