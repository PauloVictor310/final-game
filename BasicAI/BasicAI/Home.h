/**********************************************************************************
// Home (Arquivo de Cabeçalho)
//
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/


// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Audio.h"
#include "Scene.h"

// ------------------------------------------------------------------------------

class Home : public Game
{
private:
    Sprite* backg = nullptr;         // pano de fundo


public:
    static Audio* audio;
    static Scene* scene;           // cena do nú“el

    void Init();                    // inicia nú“el
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza nú“el
};

// -----------------------------------------------------------------------------