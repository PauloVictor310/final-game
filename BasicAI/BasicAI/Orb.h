/**********************************************************************************
// Orb (Arquivo de Cabeçalho)
//
// Criação:     18 Nov 2022
//
// Compilador:  Visual C++ 2022
//
// Descrição:   Orbs do X
//
**********************************************************************************/

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                        // tipos especúŸicos da engine
#include "Object.h"                       // interface de Object
#include "Player.h"

// ---------------------------------------------------------------------------------

class Orb : public Object
{
public:
    uint color;

    Orb(uint c);                          // construtor
    ~Orb();                               // destrutor

    void Update() {};                     // atualização
    void Draw() {};                       // desenho
};

// ---------------------------------------------------------------------------------