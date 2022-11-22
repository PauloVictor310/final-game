/**********************************************************************************
// Game (Arquivo de CabeÁalho)
//
// CriaÁ„o:     08 Dez 2012
// AtualizaÁ„o: 01 Nov 2021
// Compilador:  Visual C++ 2019
//
// DescriÁ„o:   Uma classe abstrata para representar um jogo.
//
//              Para criar um jogo o programador deve criar uma classe derivada
//              de Game e sobrescrever os mÈtodos Init, Update, Draw e Finalize.
//              Para rodar o jogo, deve-se passar o objeto Game para o mÈtodo
//              Start() de um objeto Engine.
//
**********************************************************************************/

#ifndef _PROGJOGOS_GAME_H_
#define _PROGJOGOS_GAME_H_

// ---------------------------------------------------------------------------------

#include "Types.h"
#include "Window.h"

// ---------------------------------------------------------------------------------

class Game
{
private:
    static Canvas world;                            // ·rea do jogo

    // Membros protegidos s„o privados para o mundo externo mas
    // p˙blicos para as classes derivadas, ou seja, as classes
    // derivadas de Game ser„o capazes de acessar estes membros.

protected:
    static Window* & window;                        // janela do jogo
    static Game*   & game;                          // jogo em execuÁ„o
    static float   & gameTime;                      // tempo do ˙ltimo quadro

public:
    ViewPort viewport;                              // ·rea vis˙ìel do jogo
    
    Game();                                         // construtor 

    // MÈtodos virtuais garantem que uma chamada atravÈs de um
    // ponteiro para a classe base, vai invocar o mÈtodo da classe
    // derivada, se ele existir, em vez de chamar sempre o mÈtodo 
    // da classe base.

    virtual ~Game();                                // destrutor
    virtual void OnPause();                         // pausa do jogo

    static void Size(float width, float height);    // define o tamanho do jogo
    static float Width();                           // retorna a largura do jogo
    static float Height();                          // retorna a altura do jogo
    static float CenterX();                         // retorna o centro do jogo no eixo x
    static float CenterY();                         // retorna o centro do jogo no eixo y

    // Estes mÈtodos s„o puramente virtuais, isto ÅE devem ser 
    // implementados em todas as classes derivas de Game.

    virtual void Init() = 0;                        // inicializaÁ„o do jogo
    virtual void Update() = 0;                      // atualizaÁ„o do jogo
    virtual void Draw() = 0;                        // desenho da cena
    virtual void Finalize() = 0;                    // finalizaÁ„o do jogo
};

// ---------------------------------------------------------------------------------

inline float Game::Width()
{ return world.width; }

inline float Game::Height()
{ return world.height; }

inline float Game::CenterX()
{ return world.centerX; }

inline float Game::CenterY()
{ return world.centerY; }

// ---------------------------------------------------------------------------------

#endif