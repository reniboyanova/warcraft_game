#include "DeathKnight.h"
#include "Defines.h"

DeathKnight::DeathKnight(
    const std::string &name, int maxMana, int manaRegenRate)
    : Hero(name, maxMana, manaRegenRate)
{
    _initSpells(DEATH_KNIGHT_BASIC_SPELL_NAME, DEATH_KNIGHT_BASIC_SPELL_MANA_COST,
               DEATH_KNIGHT_ULTIMATE_SPELL_NAME, DEATH_KNIGHT_ULTIMATE_SPELL_MANA_COST);
}

DeathKnight::~DeathKnight() = default;

void DeathKnight::_castUltimateSpell()
{
    bool isSuccess = _tryToCastSpell(ULTIMATE);

    if (isSuccess)
    {
        _castSpellSuccess(_spells[BASIC].spellName, 0);
    }
}
