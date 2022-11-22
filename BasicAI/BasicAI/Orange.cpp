/**********************************************************************************
// Orange (C�digo Fonte)
// 
// Cria��o:     05 Ago 2019
// Atualiza��o: 11 Nov 2021
// Compilador:  Visual C++ 2019
//
// Descri��o:   Objeto faz movimento retil��eo
//
**********************************************************************************/

#include "BasicAI.h"
#include "Orange.h"
#include "Random.h" 
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Orange::Orange(float pX, float pY, float ang)
{
    // enemy_4

    sprite = new Sprite(BasicAI::orange);

    // ajusta o vetor velocidade
    speed.RotateTo(ang);
    speed.ScaleTo(400);
    RotateTo(-speed.Angle());

    BBox(new Rect(-45, -55, 45, 55));
    Rotate(90.0f);
    Scale(0.6f);

    MoveTo(pX, pY);
    ScaleTo(0.6f);
    type = ORANGE;

    // configura��o do emissor de part��ulas
    Generator emitter;
    emitter.imgFile = "Resources/New/particles/magic_4f.png";    // arquivo de imagem
    emitter.angle = speed.Angle() + 180;        // �ngulo base do emissor
    emitter.spread = 5;                         // espalhamento em graus
    emitter.lifetime = 0.4f;                    // tempo de vida em segundos
    emitter.frequency = 0.010f;                 // tempo entre gera��o de novas part��ulas
    emitter.percentToDim = 0.8f;                // desaparece ap�s 60% da vida
    emitter.minSpeed = 100.0f;                  // velocidade m��ima das part��ulas
    emitter.maxSpeed = 200.0f;                  // velocidade m�xima das part��ulas
    emitter.color.r = 1.0f;                     // componente Red da part��ula 
    emitter.color.g = 0.5;                      // componente Green da part��ula 
    emitter.color.b = 0.0f;                     // componente Blue da part��ula 
    emitter.color.a = 1.0f;                     // transpar�ncia da part��ula

    // cria sistema de part��ulas
    tail = new Particles(emitter);
    tailCount = 0;

    // incrementa contagem
    ++Hud::oranges;
}

// ---------------------------------------------------------------------------------

Orange::~Orange()
{
    delete sprite;
    delete tail;

    // decrementa contagem
    Hud::particles -= tailCount;
    --Hud::oranges;
}

// -------------------------------------------------------------------------------

void Orange::OnCollision(Object * obj)
{
    if (obj->Type() == MISSILE)
    {
        BasicAI::player->score+=11;
        BasicAI::scene->Delete(obj, STATIC);
        BasicAI::scene->Delete(this, MOVING);
        BasicAI::scene->Add(new Explosion(x, y), STATIC);
        BasicAI::audio->Play(EXPLODE);        
    }
}

// -------------------------------------------------------------------------------

void Orange::Update()
{
    // movimenta objeto pelo seu vetor velocidade
    Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);

    // ajusta �ngulo do vetor na dire��o oposta
    if (x < 50 || y < 50 || x > game->Width() - 50 || y > game->Height() - 50)
    {
        Rotate(180);
        speed.Rotate(180);        
        Translate(speed.XComponent() * gameTime, -speed.YComponent() * gameTime);
    }

    // atualiza calda da nave
    tail->Config().angle = speed.Angle();
    tail->Generate(x - 10 * cos(speed.Radians()), y + 10 * sin(speed.Radians()));
    tail->Update(gameTime);

    Hud::particles -= tailCount;
    tailCount = tail->Size();
    Hud::particles += tailCount;
}

// ---------------------------------------------------------------------------------

void Orange::Draw()
{
    sprite->Draw(x, y, Layer::LOWER, scale, rotation);
    tail->Draw(Layer::LOWER, 1.0f);
}

// -------------------------------------------------------------------------------