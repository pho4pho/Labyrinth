#ifndef GEOMETRYENGINE_H
#define GEOMETRYENGINE_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QColor>
#include <QVector>
#include <QVector2D>
#include <QVector3D>

class AbstractDrawObject: protected QOpenGLFunctions {
public:
    AbstractDrawObject();
    virtual ~AbstractDrawObject();
    virtual void draw(QOpenGLShaderProgram* program) = 0;
    virtual void setTexture(QVector2D* texcoords) = 0;
    void setTextured(bool value);
    bool getTextured();
protected:
    QOpenGLBuffer coordinateBuf;
    QOpenGLBuffer normalBuf;
    QOpenGLBuffer indexBuf;
    QOpenGLBuffer texcoordBuf;
    bool isTextured;
};


class PlaneDrawObject: public AbstractDrawObject {
public:
    PlaneDrawObject();
    PlaneDrawObject(QVector3D coordinates[]);
    ~PlaneDrawObject();
    void draw(QOpenGLShaderProgram *program);
    void setTexture(QVector2D* texcoords);
};

class BoxDrawObject: public AbstractDrawObject {
public:
    BoxDrawObject();
    ~BoxDrawObject();
    void draw(QOpenGLShaderProgram *program);
    void setTexture(QVector2D *texcoords);
    void setTextured(bool value);
private:
    PlaneDrawObject** faces;
};

class GeometryEngine : protected QOpenGLFunctions
{
public:
    GeometryEngine();
    virtual ~GeometryEngine();

    void drawCubeGeometry(QOpenGLShaderProgram *program);

private:
    void initCubeGeometry();

    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;
};

#endif // GEOMETRYENGINE_H
