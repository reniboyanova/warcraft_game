#include "Archmage.h"
#include "Defines.h"

Archmage::Archmage(const std::string &name, int maxMana, int manaRegenRate, int manaRegenModifier)
    : Hero(name, maxMana, manaRegenRate), _manaRegenModifier(manaRegenModifier)
{
    _initSpells(ARCHMAGE_BASIC_SPELL_NAME, ARCHMAGE_BASIC_SPELL_MANA_COST,
               ARCHMAGE_ULTIMATE_SPELL_NAME, ARCHMAGE_ULTIMATE_SPELL_MANA_COST);
}

Archmage::~Archmage() = default;

void Archmage::_castUltimateSpell()
{
    bool isSuccess = _tryToCastSpell(ULTIMATE);

    if (isSuccess)
    {
        _regenerateMana();
    }
}

void Archmage::_regenerateMana()
{
    _currMana += _manaRegenRate * _manaRegenModifier;
    if (_currMana > _maxMana)
    {
        _currMana = _maxMana;
    }
}
