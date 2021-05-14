#pragma once
#include "Element.h"
#include "Sand.h"
#include "Water.h"

class Manager
{
public:
	int width;
	int height;

	std::map<std::string, Element*> elements;

	sf::Uint8* canvas;
private:
public:
	Manager(int width, int height, sf::Uint8* canvas);

	void permute_all();

	bool is_valid_pos(sf::Vector2i pos);

	bool is_color(int index, int* color);

	int vector_to_int(sf::Vector2i pos);

	int* get_color_at(int index);

	Element who_is(int index);
};

