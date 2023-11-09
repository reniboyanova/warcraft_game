#include "DrawRanger.h"

DrawRanger::DrawRanger(
    const std::string &name, int maxMana, int manaRegenRate)
    : Hero(name, maxMana, manaRegenRate)
{
    _initSpells(DRAW_RANGER_BASIC_SPELL_NAME, DRAW_RANGER_BASIC_SPELL_MANA_COST,
                DRAW_RANGER_ULTIMATE_SPELL_NAME, DRAW_RANGER_ULTIMATE_SPELL_MANA_COST);
}

DrawRanger::~DrawRanger() = default;

void DrawRanger::_castBasicSpell()
{
    bool isSuccess = _tryToCastSpell(BASIC);

    if (isSuccess)
    {
        _castSpellSuccess(_spells[BASIC].spellName, 0);
    }
}
