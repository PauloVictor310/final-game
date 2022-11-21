/**********************************************************************************
// DimensionFighter (Arquivo de Cabeçalho)
//
// Criação:     05 Out 2011
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Resources.h"

// ------------------------------------------------------------------------------

// ------------------------------------------------------------------------------

class Etther : public Game
{
private:
    static Game* level;            // nú“el atual do jogo

public:
    static Audio* audio;           // sistema de áudio

    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

    template<class T>
    static void NextLevel()         // muda para próximo nú“el do jogo
    {
        if (level)
        {
            level->Finalize();
            delete level;
            level = new T();
            level->Init();
        }
    };
};

// ---------------------------------------------------------------------------------
