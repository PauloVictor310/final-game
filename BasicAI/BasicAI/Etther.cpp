/**********************************************************************************
// DimensionFighter (C�digo Fonte)
//
// Cria��o:     05 Out 2011
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Jogo estilo plataforma usando a engine do curso
//
**********************************************************************************/

#include "Engine.h"
#include "Etther.h"
#include "BasicAI.h"
//#include "GameOver.h"

// ------------------------------------------------------------------------------

// inicializa membros est�ticos da classe
Game* Etther::level = nullptr;
Audio* Etther::audio = nullptr;

// ------------------------------------------------------------------------------

void Etther::Init()
{
    // cria sistema de �udio
    audio = new Audio();
    //audio->Add(MENU, "Resources/Menu.wav");
    //audio->Add(MUSIC, "Resources/Music.wav");
    //audio->Add(TRANSITION, "Resources/Transition.wav");

    // inicializa n��el de abertura do jogo
    level = new BasicAI();
    level->Init();
}

// ------------------------------------------------------------------------------

void Etther::Update()
{
    // atualiza n��el
    level->Update();
}

// ------------------------------------------------------------------------------

void Etther::Draw()
{
    // desenha n��el
    level->Draw();
}

// ------------------------------------------------------------------------------

void Etther::Finalize()
{
    level->Finalize();

    delete audio;
    delete level;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    // cria motor do jogo
    Engine* engine = new Engine();

    // configura janela
    //engine->window->Mode(WINDOWED);
    //engine->window->Size(3840, 2160);
    engine->window->Mode(BORDERLESS);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Etther 2");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(false);

    // cria o jogo
    Game* game = new BasicAI();

    // configura o jogo
    game->Size(3840, 2160);

    // inicia execu��o
    int status = engine->Start(game);

    // destr�i motor 
    delete engine;

    // encerra
    return status;
}