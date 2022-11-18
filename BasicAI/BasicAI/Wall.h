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
// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                                          // tipos específicos da engine
#include "Object.h"                                         // interface de Object
#include "Sprite.h"                                         // interface de Sprites

// ---------------------------------------------------------------------------------

class Wall : public Object 
{
public:
    uint color;                                             // cor da parede
    float velX;                                             // velocidade horizontal
    float velY;                                             // velocidade vertical

    Wall(float x1, float y1, float x2, float y2);           // construtor para bbox retangular
    Wall(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float x5, float y5,
        float x6, float y6, float x7, float y7, float x8, float y8, float x9, float y9, float x10, float y10, 
        float x11, float y11, float x12, float y12, float x13, float y13, float x14, float y14, float x15, float y15, 
        float x16, float y16, float x17, float y17, float x18, float y18, float x19, float y19, float x20, float y20);   // construtor para bbox polígono (paredes inclinadas)
    ~Wall();                                                // destrutor

    void Update();                                          // atualização do objeto
    void Draw();                                            // desenho do objeto
    void OnCollision(Object* obj);                          // tratamento de colisão
};

// ---------------------------------------------------------------------------------
