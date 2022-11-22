/**********************************************************************************
// Player (Arquivo de CabeÁalho)
// 
// CriaÁ„o:     10 Out 2012
// AtualizaÁ„o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// DescriÁ„o:   Define a classe jogador
//
**********************************************************************************/

#ifndef _BASICAI_PLAYER_H_
#define _BASICAI_PLAYER_H_

// ---------------------------------------------------------------------------------

#include "Object.h"                     // objetos do jogo
#include "Sprite.h"                     // desenho de sprites
#include "Vector.h"                     // representaÁ„o de vetores
#include "Particles.h"                  // sistema de part˙Äulas
#include "Controller.h"                 // entrada pelo controle
#include "Timer.h"                      // controle do tempo
#include "Types.h"

// ---------------------------------------------------------------------------------

enum PLAYERCOLOR { PBLUE, PRED, PYELLOW };

class Player : public Object
{
private:
    Sprite * spriteR;                    // sprite do player vermelho
    Sprite * spriteB;                     // sprite do player azul
    Particles * tail;                   // calda do jogador
    Particles * damage;            // sistema de part˙Äulas
    uint tailCount;                     // quantidade de part˙Äulas da calda
    
    Controller * gamepad;               // leitura do controle
    bool gamepadOn;                     // controle estÅEligado
    
    Timer timer;                        // controla tempo dos disparos
    llong start;                        // marcaÁ„o de in˙Äio do disparo
    bool axisCtrl;                      // habilita leitura de disparos
    bool keysCtrl;                      // habilita disparos pelas setas
    bool keysPressed;                   // qualquer seta pressionada
    float firingAngle;                  // direÁ„o dos disparos

public:
    static Image * missile;             // imagem do m˙êsil
    Vector speed;                       // velocidade e direÁ„o de movimento
    int totalLife;
    int life;
    int score;

    uint currColor;                     // cor atual do jogador

    Player();                           // construtor
    ~Player();                          // destrutor
    
    bool AxisTimed(int axisX, int axisY, float time);
    bool KeysTimed(bool pressed, float time);

    void OnCollision(Object* obj);     // resoluÁ„o da colis„o
    void WallCollision(Object* obj);    // revolve colis„o com wallE

    void Move(Vector && v);             // movimenta jogador
    void Update();                      // atualizaÁ„o
    void Draw();                        // desenho
}; 
// ---------------------------------------------------------------------------------

#endif