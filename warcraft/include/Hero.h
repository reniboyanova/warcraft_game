#ifndef HERO_H
#define HERO_H

#include "Spell.h"
#include <string>
#include <vector>

#define MAX_SPELLS 2

using collectionOf = std::vector<Spell>;

class Hero
{
protected:
    std::string _name;
    int _maxMana;
    int _currMana;
    int _manaRegenRate;
    Spell _spells[MAX_SPELLS];

    void _initSpells(const std::string &basicSpellName, int basicSpellCost,
                     const std::string &ultimateSpellName, int ultimateSpellCost);

    void _castSpellSuccess(const std::string &spellName, int spellCost);
    void _castSpellFail(const std::string &spellName);
    bool _tryToCastSpell(int spellType);

    virtual void _castBasicSpell();
    virtual void _castUltimateSpell();
    virtual void _regenerateMana();

public:
    Hero(const std::string &name, int maxMana, int manaRegenRate);
    virtual ~Hero();

    void performAction(int actionType);
};

#endif
