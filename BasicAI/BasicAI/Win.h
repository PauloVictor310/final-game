/**********************************************************************************
// GameOver (Arquivo de Cabe�alho)
//
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Fim do jogo
//
**********************************************************************************/

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class Win : public Game
{
private:
    Sprite* title = nullptr;       // tela de fim

public:
    void Init();                    // inicializa��o do n��el
    void Update();                  // l�gica da tela de fim
    void Draw();                    // desenho da tela
    void Finalize();                // finaliza��o do n��el
};

// ------------------------------------------------------------------------------
