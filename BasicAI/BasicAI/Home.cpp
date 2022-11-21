/**********************************************************************************
// Home (Código Fonte)
//
// Criação:     14 Fev 2013
// Atualização: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "BasicAI.h"
#include "Etther.h"

// ------------------------------------------------------------------------------

Audio* Home::audio = nullptr;
Scene* Home::scene = nullptr;

// ------------------------------------------------------------------------------

void Home::Init()
{
    // cria gerenciador de cena
    scene = new Scene();
    backg = new Sprite("Resources/New/levelhome.png");

    /*audio = new Audio();
    audio->Add(MUSIC, "Resources/home.wav");
    audio->Play(MUSIC);*/
}

// ------------------------------------------------------------------------------

void Home::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyPress(VK_ESCAPE))
        window->Close();

    // se a tecla ENTER for pressionada
    if (window->KeyPress(VK_RETURN))
    {
        Etther::NextLevel<BasicAI>();
    }
    else
    {
        scene->Update();
    }
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete backg;
    delete scene;
}

// ------------------------------------------------------------------------------