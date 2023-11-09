#ifndef HERO_MANAGER_H
#define HERO_MANAGER_H

#include "Hero.h"
#include <vector>
#include <memory>

using collectionOfHeros = std::vector<std::unique_ptr<Hero>>;

class HeroManager
{
private:
    collectionOfHeros _heroes;
    void _fillHeros();

public:
    void heroPerfomance();
};

#endif