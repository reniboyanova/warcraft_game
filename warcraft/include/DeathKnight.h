#ifndef DEATH_KNIGHT_H
#define DEATH_KNIGHT_H

#include "Hero.h"

class DeathKnight : public Hero
{
protected:
    void _castUltimateSpell() override;
    
public:
    DeathKnight(const std::string &name, int maxMana, int manaRegenRate);
    ~DeathKnight() override;
};

#endif