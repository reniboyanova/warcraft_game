#ifndef ARCHMAGE_H
#define ARCHMAGE_H

#include "Hero.h"

class Archmage : public Hero
{
private:
    int _manaRegenModifier;

protected:
    void _castUltimateSpell() override;
    void _regenerateMana() override;

public:
    Archmage(const std::string &name, int maxMana,
             int manaRegenRate, int manaRegenModifier);
    ~Archmage() override;
};

#endif