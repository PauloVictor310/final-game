/**********************************************************************************
// Explosion (Código Fonte)
// 
// Criação:     17 Mar 2013
// Atualização: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descrição:   Efeito de explosão usando sistema de partú€ulas
//
**********************************************************************************/

#include "BasicAI.h"
#include "Explosion.h"
#include "Random.h"
#include "Hud.h"

// ---------------------------------------------------------------------------------

Explosion::Explosion(float pX, float pY)
{
    // número aleatório entre 0 e 1
    RandF color{ 0, 1 };

    // configura emissor de partú€ulas
    Generator explosion;
    explosion.imgFile   = "Resources/New/particles/scorch_f.png";    // arquivo de imagem
    explosion.angle     = 0.0f;                     // direção da explosão
    explosion.spread    = 360.0f;                   // espalhamento em graus
    explosion.lifetime  = 1.5f;                     // tempo de vida em segundos
    explosion.frequency = 0.000f;                   // tempo entre geração de novas partú€ulas
    explosion.percentToDim = 0.8f;                  // desaparece após 60% da vida
    explosion.minSpeed  = 25.0f;                    // velocidade mú‹ima das partú€ulas
    explosion.maxSpeed  = 250.0f;                   // velocidade máxima das partú€ulas
    explosion.color.r   = color.Rand();             // cor da partú€ula entre 0 e 1
    explosion.color.g   = color.Rand();             // cor da partú€ula entre 0 e 1
    explosion.color.b   = color.Rand();             // cor da partú€ula entre 0 e 1
    explosion.color.a   = 1.0f;                     // transparência da partú€ula

    // cria sistema de partú€ulas
    sparks = new Particles(explosion);

    // gera 50 partú€ulas na posição indicada
    sparks->Generate(pX, pY, 50);
    type = EXPLOSION;

    // incrementa contagem de partú€ulas
    Hud::particles += 50;
}

// ---------------------------------------------------------------------------------

Explosion::~Explosion()
{
    delete sparks;

    // decrementa contagem de partú€ulas
    Hud::particles -= 50;
}

// -------------------------------------------------------------------------------

void Explosion::Update()
{
    // atualiza posição de cada partú€ula
    sparks->Update(gameTime);

    // remove da cena quando todas as partú€ulas estão inativas
    if (sparks->Inactive())
        BasicAI::scene->Delete();
}

// -------------------------------------------------------------------------------