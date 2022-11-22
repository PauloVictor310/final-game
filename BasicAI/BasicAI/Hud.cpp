/**********************************************************************************
// Hud (Código Fonte)
//
// Criação:     02 Ago 2019
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Heads Up Display
//
**********************************************************************************/

#include "Hud.h"
#include "BasicAI.h"
#include "iostream"

// ------------------------------------------------------------------------------

// inicializa contadores
uint Hud::missiles = 0;
uint Hud::oranges = 0;
uint Hud::magentas = 0;
uint Hud::blues = 0;
uint Hud::greens = 0;
uint Hud::particles = 0;

// ------------------------------------------------------------------------------

Hud::Hud()
{
    win = new Sprite("Resources/New/levelwin.png");
    lose = new Sprite("Resources/New/levellose.png");
    // cria fonte para exibição de texto
    font = new Font("Resources/new/agency32.png");
    font->Spacing(130);
    bold = new Font("Resources/new/agency32.png");
    bold->Spacing(130);

    // carrega sprites
    infoBox = new Sprite("Resources/new/newInfobox.png");

    // inicializa contador de frames e tempo transcorrido
    frameCount = 0;
    totalTime = 0.0f;
    fps = 0;
}

// ------------------------------------------------------------------------------

Hud::~Hud()
{
    delete font;
    delete bold;
    delete infoBox;
}

// -------------------------------------------------------------------------------

void Hud::Update()
{
    // tempo acumulado dos frames
    totalTime += gameTime;

    // incrementa contador de frames
    frameCount++;

    // a cada 1000ms (1 segundo) atualiza indicador de FPS
    if (totalTime >= 1.0f)
    {
        fps = frameCount;
        frameCount = 0;
        totalTime -= 1.0f;
    }

    if (BasicAI::isGameOver) {
        if (window->KeyPress(VK_RETURN)) {
            // calcula posição para manter viewport centralizada
            BasicAI::player->MoveTo(447, 2033);
            BasicAI::player->life = 100;
            BasicAI::isGameOver = false;
        }
    }
}

// -------------------------------------------------------------------------------

void Hud::Draw()
{
    // desenha elementos da interface
    if (!BasicAI::isGameOver && !BasicAI::isWin) {
        infoBox->Draw(game->viewport.right - 140, game->viewport.top, Layer::FRONT, 0.5);

        // define cor do texto
        Color textColor{ 1.0f, 1.0f, 1.0f, 1.0f };

        // desenha texto
        text.str("");
        text << BasicAI::player->life;
        font->Draw(1500, 18, text.str(), textColor, 0.0f, 0.2f);
    }
    

    if (BasicAI::isGameOver) {
        lose->Draw(game->viewport.left + window->CenterX(), game->viewport.top + window->CenterY(), Layer::FRONT, 0.8);
    }

    if (BasicAI::isWin) {
        win->Draw(game->viewport.left + window->CenterX(), game->viewport.top + window->CenterY(), Layer::FRONT, 0.8);
    }
}

// -------------------------------------------------------------------------------
