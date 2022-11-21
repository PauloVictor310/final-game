/**********************************************************************************
// BasicAI (Código Fonte)
// 
// Criação:     23 Out 2012
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Demonstração de todas as IAs

//
**********************************************************************************/

#include "Resources.h"
#include "BasicAI.h"
#include "Engine.h"    
#include "Delay.h"
#include "Wall.h"
#include "Orb.h"
#include "Home.h"
#include "GameOver.h"
#include "Etther.h"
#include "Win.h"

// ------------------------------------------------------------------------------
Player * BasicAI::player  = nullptr;
Audio  * BasicAI::audio   = nullptr;
Scene  * BasicAI::scene   = nullptr;
bool     BasicAI::viewHUD = false;
Image  * BasicAI::blue    = nullptr;
Image  * BasicAI::green   = nullptr;
Image  * BasicAI::magenta = nullptr;
Image  * BasicAI::orange  = nullptr;

// ------------------------------------------------------------------------------

void BasicAI::Init() 
{
    // cria sistema de áudio
    audio = new Audio();
    audio->Add(START, "Resources/Start.wav");
    audio->Add(THEME, "Resources/New/withoutfear.wav");
    audio->Add(FIRE, "Resources/Fire.wav", 2);
    audio->Add(HITWALL, "Resources/Hitwall.wav", 5);
    audio->Add(EXPLODE, "Resources/Explode.wav", 3);
    audio->Add(ORANGE, "Resources/Orange.wav", 1);
    audio->Add(MAGENTA, "Resources/Magenta.wav", 2);
    audio->Add(BLUE, "Resources/Blue.wav", 2);
    audio->Add(GREEN, "Resources/Green.wav", 2);

    // ajusta volumes
    audio->Volume(START, 0.30f);
    audio->Volume(THEME, 0.60f);
    audio->Volume(FIRE, 0.10f);
    audio->Volume(EXPLODE, 0.15f);
    audio->Volume(ORANGE, 0.90f);
    audio->Volume(MAGENTA, 0.40f);
    audio->Volume(BLUE, 0.20f);
    audio->Volume(GREEN, 0.75f);

    // carrega imagens das geometrias
    blue    = new Image("Resources/New/enemy_1.png");
    green   = new Image("Resources/New/enemy_2.png");
    magenta = new Image("Resources/New/enemy_3.png");
    orange  = new Image("Resources/New/enemy_4.png");

    // carrega/incializa objetos
    backg   = new Background("Resources/New/state1.png");
    player  = new Player();
    scene   = new Scene();  
    hud     = new Hud();

    // adiciona objetos na cena
    scene->Add(player, MOVING);
    scene->Add(new Delay(), STATIC);

    // ----------------------
    // Posição das paredes
    // ----------------------
    Wall* wall;
    wall = new Wall(-453, -12, 453, 12);
    wall->color = PRED;
    wall->MoveTo(451, 1567);
    scene->Add(wall, STATIC);

    wall = new Wall(-220, -12, 220, 12);
    wall->color = PRED;
    wall->MoveTo(220, 1871);
    scene->Add(wall, STATIC);

    wall = new Wall(-212, -12, 212, 12);
    wall->color = PBLUE;
    wall->MoveTo(652, 1871);
    scene->Add(wall, STATIC);

    wall = new Wall(-12, -287, 12, 287);
    wall->color = PRED;
    wall->MoveTo(891, 1873);
    scene->Add(wall, STATIC);

    wall = new Wall(-642, -12, 642, 12);
    wall->color = PYELLOW;
    wall->MoveTo(642, 1276);
    scene->Add(wall, STATIC);

    wall = new Wall(-401, -12, 401, 12);
    wall->color = PYELLOW;
    wall->MoveTo(1730, 1276);
    scene->Add(wall, STATIC);

    wall = new Wall(-528, -12, 528, 12);
    wall->color = PYELLOW;
    wall->MoveTo(754, 1026);
    scene->Add(wall, STATIC);

    wall = new Wall(-516, -12, 516, 12);
    wall->color = PYELLOW;
    wall->MoveTo(516, 814);
    scene->Add(wall, STATIC);

    wall = new Wall(-528, -12, 528, 12);
    wall->color = PYELLOW;
    wall->MoveTo(754, 625);
    scene->Add(wall, STATIC);

    wall = new Wall(-516, -12, 516, 12);
    wall->color = PYELLOW;
    wall->MoveTo(516, 439);
    scene->Add(wall, STATIC);

    wall = new Wall(-12, -513, 12, 513);
    wall->color = PYELLOW;
    wall->MoveTo(1309, 513);
    scene->Add(wall, STATIC);

    wall = new Wall(-12, -125, 12, 125);
    wall->color = PRED;
    wall->MoveTo(1309, 1152);
    scene->Add(wall, STATIC);

    wall = new Wall(-12, -441, 12, 441);
    wall->color = PBLUE;
    wall->MoveTo(1306, 1719);
    scene->Add(wall, STATIC);

    wall = new Wall(-418, -12, 418, 12);
    wall->color = PRED;
    wall->MoveTo(1745, 1872);
    scene->Add(wall, STATIC);

    wall = new Wall(-418, -12, 418, 12);
    wall->color = PRED;
    wall->MoveTo(1745, 1568);
    scene->Add(wall, STATIC);

    wall = new Wall(-12, -313, 12, 313);
    wall->color = PRED;
    wall->MoveTo(2149, 950);
    scene->Add(wall, STATIC);

    wall = new Wall(-307, -12, 307, 12);
    wall->color = PYELLOW;
    wall->MoveTo(1823, 624);
    scene->Add(wall, STATIC);

    wall = new Wall(-94, -12, 94, 12);
    wall->color = PBLUE;
    wall->MoveTo(1420, 624);
    scene->Add(wall, STATIC);
    
    wall = new Wall(-593, -12, 593, 12);
    wall->color = PYELLOW;
    wall->MoveTo(2723, 624);
    scene->Add(wall, STATIC);

    wall = new Wall(-12, -443, 12, 443);
    wall->color = PYELLOW;
    wall->MoveTo(2487, 1718);
    scene->Add(wall, STATIC);

    wall = new Wall(-199, -11, 199, 11);
    wall->color = PRED;
    wall->MoveTo(2701, 1829);
    scene->Add(wall, STATIC);

    wall = new Wall(-199, -11, 199, 11);
    wall->color = PRED;
    wall->MoveTo(3120, 1563);
    scene->Add(wall, STATIC);

    wall = new Wall(-145, -12, 145, 12);
    wall->color = PBLUE;
    wall->MoveTo(3174, 1255);
    scene->Add(wall, STATIC);

    wall = new Wall(-276, -12, 276, 12);
    wall->color = PRED;
    wall->MoveTo(2753, 1255);
    scene->Add(wall, STATIC);

    wall = new Wall(-276, -12, 276, 12);
    wall->color = PRED;
    wall->MoveTo(2753, 872);
    scene->Add(wall, STATIC);

    wall = new Wall(-12, -177, 12, 177);
    wall->color = PRED;
    wall->MoveTo(2488, 1063);
    scene->Add(wall, STATIC);

    wall = new Wall(-12, -177, 12, 177);
    wall->color = PRED;
    wall->MoveTo(3013, 1063);
    scene->Add(wall, STATIC);

    wall = new Wall(-11, -103, 11, 103);
    wall->color = PRED;
    wall->MoveTo(3332, 2057);
    scene->Add(wall, STATIC);

    wall = new Wall(-12, -860, 12, 860);
    wall->color = PYELLOW;
    wall->MoveTo(3332, 1095);
    scene->Add(wall, STATIC);

    wall = new Wall(-11, -118, 11, 118);
    wall->color = PBLUE;
    wall->MoveTo(3332, 118);
    scene->Add(wall, STATIC);

    wall = new Wall(-246, -12, 246, 12);
    wall->color = PRED;
    wall->MoveTo(3594, 1791);
    scene->Add(wall, STATIC);

    wall = new Wall(-246, -12, 246, 12);
    wall->color = PRED;
    wall->MoveTo(3594, 1114);
    scene->Add(wall, STATIC);

    wall = new Wall(-246, -12, 246, 12);
    wall->color = PRED;
    wall->MoveTo(3594, 438);
    scene->Add(wall, STATIC);

    wall = new Wall(-246, -12, 246, 12);
    wall->color = PBLUE;
    wall->MoveTo(3594, 792);
    scene->Add(wall, STATIC);

    wall = new Wall(-246, -12, 246, 12);
    wall->color = PBLUE;
    wall->MoveTo(3594, 1444);
    scene->Add(wall, STATIC);

    wall = new Wall(3136, 31, 3151, 44, 2959, 215, 2774, 64, 2583, 219,
                    2404, 57, 2228, 221, 2051, 59, 1877, 222, 1700, 58, 
                    1524, 223, 1509, 207, 1698, 27, 1878, 188, 2051, 25, 
                    2232, 189, 2403, 26, 2584, 188, 2774, 32, 2957, 186);
    wall->color = PRED;
    scene->Add(wall, STATIC);

    wall = new Wall(3136, 390, 3151, 403, 2959, 574, 2774, 423, 2583, 578,
                    2404, 416, 2228, 580, 2051, 418, 1877, 581, 1700, 417,
                    1524, 582, 1509, 566, 1698, 386, 1878, 547, 2051, 384,
                    2232, 548, 2403, 385, 2584, 547, 2774, 391, 2957, 545);
    wall->color = PRED;
    scene->Add(wall, STATIC);
    // ------------------------------------------------------------------------------

    // posiciona as orbs
    Orb* orb;
    orb = new Orb(PRED);
    orb->MoveTo(107, 2026);
    scene->Add(orb, STATIC);

    orb = new Orb(PBLUE);
    orb->MoveTo(1097, 1929);
    scene->Add(orb, STATIC);

    orb = new Orb(PRED);
    orb->MoveTo(1473, 1202);
    scene->Add(orb, STATIC);

    orb = new Orb(PRED);
    orb->MoveTo(3052, 2036);
    scene->Add(orb, STATIC);

    orb = new Orb(PBLUE);
    orb->MoveTo(3760, 1556);
    scene->Add(orb, STATIC);

    orb = new Orb(PRED);
    orb->MoveTo(3436, 1234);
    scene->Add(orb, STATIC);

    orb = new Orb(PBLUE);
    orb->MoveTo(3774, 872);
    scene->Add(orb, STATIC);

    orb = new Orb(PRED);
    orb->MoveTo(3408, 528);
    scene->Add(orb, STATIC);

    orb = new Orb(PBLUE);
    orb->MoveTo(3732, 126);
    scene->Add(orb, STATIC);

    orb = new Orb(PYELLOW);
    orb->MoveTo(430, 128);
    scene->Add(orb, STATIC);

    // ----------------------
    // inicializa a viewport
    // ----------------------

    // calcula posição para manter viewport centralizada
    float difx = (game->Width() - window->Width()) / 2.0f;
    float dify = (game->Height() - window->Height()) / 2.0f;

    // inicializa viewport para o centro do mundo
    viewport.left = 0.0f + difx;
    viewport.right = viewport.left + window->Width();
    viewport.top = 0.0f + dify;
    viewport.bottom = viewport.top + window->Height();
}

// ------------------------------------------------------------------------------

void BasicAI::Update()
{
    // sai com o pressionamento da tecla ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza cena e calcula colisões
    scene->Update();
    scene->CollisionDetection();

    // ---------------------------------------------------
    // atualiza a viewport
    // ---------------------------------------------------

    viewport.left   = player->X() - window->CenterX();
    viewport.right  = player->X() + window->CenterX();
    viewport.top    = player->Y() - window->CenterY();
    viewport.bottom = player->Y() + window->CenterY();
            
    if (viewport.left < 0)
    {
        viewport.left  = 0;
        viewport.right = window->Width();
    }
    else if (viewport.right > game->Width())
    {  
        viewport.left  = game->Width() - window->Width();
         viewport.right = game->Width();
    }
                  
    if (viewport.top < 0)
    {
        viewport.top  = 0;
        viewport.bottom = window->Height();
    }
    else if (viewport.bottom > game->Height())
    {
        viewport.top = game->Height() - window->Height();
        viewport.bottom = game->Height();
    }

    // ---------------------------------------------------

    // atualiza o painel de informações
    hud->Update();

    // ativa ou desativa a bounding box
    if (window->KeyPress('B'))
        viewBBox = !viewBBox;

    // ativa ou desativa o heads up display
    if (window->KeyPress('H'))
        viewHUD = !viewHUD;

    // passa para tela de game over
    if (window->KeyPress('N'))
        Etther::NextLevel<GameOver>();

    // passa para tela de vitoria
    if (window->KeyPress('M'))
        Etther::NextLevel<Win>();
} 

// ------------------------------------------------------------------------------

void BasicAI::Draw()
{
    // desenha pano de fundo
    backg->Draw(viewport);

    // desenha a cena
    scene->Draw();

    // desenha o painel de informações
    if (viewHUD)
        hud->Draw();

    // desenha bounding box
    if (viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void BasicAI::Finalize()
{
    delete audio;
    delete hud;
    delete scene;
    delete backg;

    delete blue;
    delete green;
    delete magenta;
    delete orange;
}
// ----------------------------------------------------------------------------