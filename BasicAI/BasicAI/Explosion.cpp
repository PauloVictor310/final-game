/**********************************************************************************
// Explosion (C�digo Fonte)
// 
// Cria��o:     17 Mar 2013
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Efeito de explos�o usando sistema de part��ulas
//
**********************************************************************************/

#include "BasicAI.h"
#include "Explosion.h"
#include "Random.h"
#include "Hud.h"

// ---------------------------------------------------------------------------------

Explosion::Explosion(float pX, float pY)
{
    // n�mero aleat�rio entre 0 e 1
    RandF color{ 0, 1 };

    // configura emissor de part��ulas
    Generator explosion;
    explosion.imgFile   = "Resources/Explo.png";    // arquivo de imagem
    explosion.angle     = 0.0f;                     // dire��o da explos�o
    explosion.spread    = 360.0f;                   // espalhamento em graus
    explosion.lifetime  = 1.5f;                     // tempo de vida em segundos
    explosion.frequency = 0.000f;                   // tempo entre gera��o de novas part��ulas
    explosion.percentToDim = 0.8f;                  // desaparece ap�s 60% da vida
    explosion.minSpeed  = 25.0f;                    // velocidade m��ima das part��ulas
    explosion.maxSpeed  = 250.0f;                   // velocidade m�xima das part��ulas
    explosion.color.r   = color.Rand();             // cor da part��ula entre 0 e 1
    explosion.color.g   = color.Rand();             // cor da part��ula entre 0 e 1
    explosion.color.b   = color.Rand();             // cor da part��ula entre 0 e 1
    explosion.color.a   = 1.0f;                     // transpar�ncia da part��ula

    // cria sistema de part��ulas
    sparks = new Particles(explosion);

    // gera 50 part��ulas na posi��o indicada
    sparks->Generate(pX, pY, 50);
    type = EXPLOSION;

    // incrementa contagem de part��ulas
    Hud::particles += 50;
}

// ---------------------------------------------------------------------------------

Explosion::~Explosion()
{
    delete sparks;

    // decrementa contagem de part��ulas
    Hud::particles -= 50;
}

// -------------------------------------------------------------------------------

void Explosion::Update()
{
    // atualiza posi��o de cada part��ula
    sparks->Update(gameTime);

    // remove da cena quando todas as part��ulas est�o inativas
    if (sparks->Inactive())
        BasicAI::scene->Delete();
}

// -------------------------------------------------------------------------------