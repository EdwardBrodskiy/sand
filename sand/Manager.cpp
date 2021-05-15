#include "Manager.h"

#include "Sand.h"
#include "Water.h"



Manager::Manager(int width, int height, sf::Uint8* canvas)
{
	this->canvas = canvas;
	this->width = width;
	this->height = height;

	elements.insert(std::make_pair("base", new Element(*this)));
	elements.insert(std::make_pair("sand", new Sand(*this)));
	elements.insert(std::make_pair("water", new Water(*this)));
}

void Manager::permute_all()
{
	((Sand*)(elements.find("sand")->second))->permute_all();
	((Water*)(elements.find("water")->second))->permute_all();
}

int Manager::vector_to_int(sf::Vector2i pos)
{
	return pos.x + pos.y * width;
}

int* Manager::get_color_at(int index)
{
	static int* color = new int[4];

	for (int i = 0; i < 4; i++) {
		color[i] = canvas[index * 4 + i];
	}
	return color;
}

Element* Manager::who_is(int index)
{
	if (is_color(index, Element::default_color)) {
		return elements.find("base")->second;
	}
	else if (is_color(index, Sand::default_color)) {
		return elements.find("sand")->second;
	}
	else if (is_color(index, Water::default_color)) {
		return elements.find("sand")->second;
	}
	throw NotKnownElementException();
}

bool Manager::is_valid_pos(sf::Vector2i pos)
{
	return pos.x >= 0 && pos.y >= 0 && pos.x < width && pos.y < height;
}

bool Manager::is_color(int index, int* color)
{
	for (int i = 0; i < 4; i++) {
		if (canvas[index * 4 + i] != color[i]) {
			return false;
		}
	}
	return true;
}
