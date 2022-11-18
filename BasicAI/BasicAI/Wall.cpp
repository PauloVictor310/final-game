/**********************************************************************************
// Wall (Arquivo de Cabeçalho)
//
// Criação:     18 Nov 2022
//
// Compilador:  Visual C++ 2022
//
// Descrição:   Parede do jogo X
//
**********************************************************************************/

#include "Wall.h"
#include "BasicAI.h"

// ---------------------------------------------------------------------------------

Wall::Wall(float x1, float y1, float x2, float y2)
{
    // bbox da parede
    BBox(new Rect(x1, y1, x2, y2));

    color = NULL;

    // velocidades iniciais
    velX = 0.0f;
    velY = 0.0f;

    // tipo do objeto
    type = WALL;
}

Wall::Wall(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float x5, float y5,
    float x6, float y6, float x7, float y7, float x8, float y8, float x9, float y9, float x10, float y10,
    float x11, float y11, float x12, float y12, float x13, float y13, float x14, float y14, float x15, float y15,
    float x16, float y16, float x17, float y17, float x18, float y18, float x19, float y19, float x20, float y20)
{

    Point sloping[20] =
    {
        Point(x1, y1), Point(x2, y2), Point(x3, y3), Point(x4, y4), Point(x5, y5),
        Point(x6, y6), Point(x7, y7), Point(x8, y8), Point(x9, y9), Point(x10, y10),
        Point(x11, y11), Point(x12, y12), Point(x13, y13), Point(x14, y14), Point(x15, y15),
        Point(x16, y16), Point(x17, y17), Point(x18, y18), Point(x19, y19), Point(x20, y20),
    };
    // bbox da parede
    BBox(new Poly(sloping, 20));

    color = NULL;

    // velocidades iniciais
    velX = 0.0f;
    velY = 0.0f;

    // tipo do objeto
    type = WALL;
}

// ---------------------------------------------------------------------------------

Wall::~Wall()
{

}

// ---------------------------------------------------------------------------------

void Wall::Update()
{

}

void Wall::Draw()
{

}

// ---------------------------------------------------------------------------------

void Wall::OnCollision(Object* obj)
{

}