#include "Hero.h"
#include "Defines.h"
#include <iostream>

Hero::Hero(const std::string &name, int maxMana, int manaRegenRate)
    : _name(name), _maxMana(maxMana), _currMana(maxMana), _manaRegenRate(manaRegenRate)
{
}

Hero::~Hero() = default;

void Hero::_initSpells(const std::string &basicSpellName, int basicSpellCost,
                       const std::string &ultimateSpellName, int ultimateSpellCost)
{
    _spells[BASIC] = {basicSpellName, basicSpellCost};
    _spells[ULTIMATE] = {ultimateSpellName, ultimateSpellCost};
}

void Hero::_castSpellSuccess(const std::string &spellName, int spellCost)
{
    std::cout << _name << " casted " << spellName
              << " for " << spellCost << " mana" << std::endl;
}

void Hero::_castSpellFail(const std::string &spellName)
{
    std::cout << _name << " - not enough mana to cast "
              << spellName << std::endl;
}

bool Hero::_tryToCastSpell(int spellType)
{
    Spell &spell = _spells[spellType];
    if (spell.manaCost > _currMana)
    {
        _castSpellFail(spell.spellName);
        return false;
    }

    _currMana -= spell.manaCost;
    _castSpellSuccess(spell.spellName, spell.manaCost);
    return true;
}

void Hero::_castBasicSpell()
{
    _tryToCastSpell(BASIC);
}

void Hero::_castUltimateSpell()
{
    _tryToCastSpell(ULTIMATE);
}

void Hero::_regenerateMana()
{
    _currMana += _manaRegenRate;
    if (_currMana > _maxMana)
    {
        _currMana = _maxMana;
    }
}

void Hero::performAction(int actionType)
{
    switch (actionType)
    {
    case CAST_BASIC_SPELL:
        _castBasicSpell();
        break;
    case CAST_ULTIMATE_SPELL:
        _castUltimateSpell();
        break;
    case REGENERATE_MANA:
        _regenerateMana();
        break;
    default:
        break;
    }
}