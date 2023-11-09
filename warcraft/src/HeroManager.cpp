#include "HeroManager.h"
#include "Archmage.h"
#include "DeathKnight.h"
#include "DrawRanger.h"
#include <iostream>

void HeroManager::_fillHeros()
{
    std::string name;
    int maxMana = 0;
    int baseManaRegenRate = 0;
    int manaRegenModifier = 0;

    std::cin >> name >> maxMana >> baseManaRegenRate >> manaRegenModifier;
    _heroes.emplace_back(std::make_unique<Archmage>(name, maxMana, baseManaRegenRate, manaRegenModifier));

    std::cin >> name >> maxMana >> baseManaRegenRate;
    _heroes.emplace_back(std::make_unique<DeathKnight>(name, maxMana, baseManaRegenRate));

    std::cin >> name >> maxMana >> baseManaRegenRate;
    _heroes.emplace_back(std::make_unique<DrawRanger>(name, maxMana, baseManaRegenRate));
}

void HeroManager::heroPerfomance()
{
    _fillHeros();
    int commandsCount = 0;
    int currAction = 0;
    std::cin >> commandsCount;

    for (int i = 0; i < commandsCount; ++i)
    {
        std::cin >> currAction;
        if (currAction > REGENERATE_MANA)
        {
            std::cout << INVALID_ACTION_EXCEPTION << std::endl;
            std::cout << std::endl;
            throw 1;
        }

        for (auto &hero : _heroes)
        {
            hero->performAction(currAction);
        }
    }
}