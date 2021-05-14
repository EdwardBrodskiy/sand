#include "Manager.h"

struct NotKnownElementException : public std::exception {
	const char* what() const throw () {
		return "Not known Element";
	}
};

Manager::Manager(int width, int height, sf::Uint8* canvas)
{
	this->canvas = canvas;
	this->width = width;
	this->height = height;

	std::map<std::string, Element> elements = {
		{'base', new Element(this)},
	{'sand', new Sand(this)},
	{'wate',new Water(this)}
	};
}

void Manager::permute_all()
{
	water.permute_all();
	sand.permute_all();
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

Element Manager::who_is(int index)
{
	if (is_color(index, Element::default_color)) {
		return base;
	}
	else if (is_color(index, Sand::default_color)) {
		return sand;
	}
	else if (is_color(index, Water::default_color)) {
		return water;
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
