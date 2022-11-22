/**********************************************************************************
// Delay (Código Fonte)
//
// Criação:     02 Ago 2019
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Sincroniza uma ação
//
**********************************************************************************/

#include "Delay.h"
#include "BasicAI.h"
#include "WaveO.h"
#include "WaveM.h"
#include "WaveB.h"
#include "WaveG.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

Delay::Delay()
{
    logo = new Sprite("Resources/New/levelhome.png");
    
    timer.Start();

    notPlayed = true;
    fase1 = false;
    fase2 = false;
    fase3 = false;
    fase4 = false;
}

// ------------------------------------------------------------------------------

Delay::~Delay()
{
    delete logo;
}

// -------------------------------------------------------------------------------

void Delay::Update()
{
    if (window->KeyPress(VK_RETURN)) {
        notPlayed = false;
        BasicAI::viewHUD = true;
        BasicAI::audio->Stop(START);
    }

    if (notPlayed)
    {
        
    }
    if (!fase1 && timer.Elapsed(2.0f) && !notPlayed)
    {
        // toca música do jogo
        BasicAI::audio->Play(THEME, true);
        BasicAI::scene->Add(new WaveO(), STATIC);
        
        fase1 = true;
    }

    if (!fase2 && timer.Elapsed(4.0f) && !notPlayed)
    {
        BasicAI::scene->Add(new WaveM(), STATIC);
        fase2 = true;
    }

    if (!fase3 && timer.Elapsed(6.0f) && !notPlayed)
    {
        BasicAI::scene->Add(new WaveB(), STATIC);
        fase3 = true;
    }

    if (!fase4 && timer.Elapsed(18.0f) && !notPlayed)
    {
        BasicAI::scene->Add(new WaveG(), STATIC);
        BasicAI::scene->Delete();
        fase4 = true;
        BasicAI::audio->Stop(THEME);
        BasicAI::audio->Play(DANGER);
    }

}

// -------------------------------------------------------------------------------

void Delay::Draw()
{
    if (notPlayed)
        logo->Draw(game->viewport.left + window->CenterX() , game->viewport.top + window->CenterY(), Layer::FRONT, 0.8);
}

// -------------------------------------------------------------------------------
