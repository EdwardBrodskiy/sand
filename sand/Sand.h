#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include "Element.h"

class Manager;

class Sand: public Element
{
public:
	static int default_color[4];
	Sand(Manager& manager);
	void permute_all();
private:
	sf::Vector2i next_pos(const sf::Vector2i pos);
};
