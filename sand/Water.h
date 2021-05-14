#pragma once
#include "Element.h"



class Water : public Element
{
public:
	static int default_color[4];
	Water(Manager& manager);
	void permute_all();
private:
	sf::Vector2i next_pos(const sf::Vector2i pos);
};

