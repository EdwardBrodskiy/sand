#pragma once
#include <SFML\Graphics.hpp>
#include <list>
#include "Manager.h"


class Element {
public:
	static int empty[4];
	static int default_color[4];
	int color[4] = { 255, 255, 255, 255 };
protected:

	std::list<sf::Vector2i> points = {};

	Manager& manager;
public:
	Element(Manager& manager);

	void add(sf::Vector2i pos);

	void permute_all();

	void move(sf::Vector2i start, sf::Vector2i end);
	
protected:
	bool is_me(int index);

	void draw_self(int index);

	void draw(int index, int* color); //TODO: remove

	

	sf::Vector2i next_pos(sf::Vector2i pos);

};