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
    bold->Spacing(100);

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
        BasicAI::scene->Remove(BasicAI::player, MOVING);
        if (window->KeyPress(VK_RETURN)) {
            // calcula posição para manter viewport centralizada
            /*BasicAI::player->MoveTo(447, 2033);
            BasicAI::player->life = 100;
            BasicAI::isGameOver = false;*/
            
            BasicAI::player = new Player();
            BasicAI::scene->Add(BasicAI::player, MOVING);
            BasicAI::isGameOver = false;
        }
    }

    if (BasicAI::isWin) {
        BasicAI::scene->Remove(BasicAI::player, MOVING);
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
        Color greenColor{ 0.0f, 1.0f, 0.0f, 1.0f };

        score.str("");
        score << "Score:";
        score << BasicAI::player->score;
        bold->Draw(1200, 18, score.str(), textColor, 0.0f, 0.2f);

        // desenha texto
        text.str("");
        text << BasicAI::player->life;
        font->Draw(1440, 18, text.str(), greenColor, 0.0f, 0.2f);
        
    }
    

    if (BasicAI::isGameOver) {
        Color textColor{ 1.0f, 1.0f, 1.0f, 1.0f };
        lose->Draw(game->viewport.left + window->CenterX(), game->viewport.top + window->CenterY(), Layer::FRONT, 0.8);
        score.str("");
        score << BasicAI::player->score;
        bold->Draw(910, 330, score.str(), textColor, 0.0f, 0.6f);
    }

    if (BasicAI::isWin) {
        Color textColor{ 1.0f, 1.0f, 1.0f, 1.0f };
        win->Draw(game->viewport.left + window->CenterX(), game->viewport.top + window->CenterY(), Layer::FRONT, 0.8);
        score.str("");
        score << BasicAI::player->score;
        bold->Draw(1280, 380, score.str(), textColor, 0.0f, 0.5f);
    }
}

// -------------------------------------------------------------------------------
