/**********************************************************************************
// Win (Arquivo de Cabe�alho)
//
// Cria��o:     14 Fev 2013
// Atualiza��o: 27 Set 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Fim do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "Win.h"
#include "Etther.h"
#include "Home.h"

// ----------------------------------------------------------------------

void Win::Init()
{
    title = new Sprite("Resources/New/levelwin.png");
}

// ----------------------------------------------------------------------

void Win::Update()
{
    if (window->KeyPress(VK_ESCAPE) || window->KeyPress(VK_RETURN))
        Etther::NextLevel<Home>();
}

// ----------------------------------------------------------------------

void Win::Draw()
{
    title->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ----------------------------------------------------------------------

void Win::Finalize()
{
    delete title;
}

// ----------------------------------------------------------------------

