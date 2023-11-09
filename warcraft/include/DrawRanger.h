#ifndef DRAW_RANGER_H
#define DRAW_RANGER_H

#include "Hero.h"
#include "Defines.h"

class DrawRanger : public Hero
{
protected:
    void _castBasicSpell() override;

public:
    DrawRanger(const std::string &name, int maxMana, int manaRegenRate);
    ~DrawRanger() override;
};

#endif
