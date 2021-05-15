#include "Element.h"

#include "Manager.h"

int Element::empty[4] = { 0, 0, 0, 0 };

int Element::default_color[4] = { 255, 255, 255, 255 };

Element::Element(Manager& manager) : manager(manager)
{
	
}

void Element::add(sf::Vector2i pos)
{
	if (!manager.is_valid_pos(pos)) {
		return;
	}
	int index = manager.vector_to_int(pos);
	if (is_me(index) || manager.is_color(index, Element::default_color)) {
		return;
	}
	draw_self(index);
	points.push_front(pos);
}

void Element::permute_all()
{
	for (auto& pos : points) {
		auto new_pos = this->next_pos(pos);
		pos = new_pos;
	}
}

void Element::move(sf::Vector2i start, sf::Vector2i end)
{
	int index_at_end = manager.vector_to_int(end);
	try {
		Element* other_element = manager.who_is(index_at_end);
		other_element->add(start);
	}
	catch(NotKnownElementException e){
		draw(manager.vector_to_int(start), Element::empty);
	}
	

	
	add(end);
}

bool Element::is_me(int index)
{
	return manager.is_color(index, color);
}

void Element::draw_self(int index)
{
	draw(index, color);
}


void Element::draw(int index, int* color)
{
	for (int i = 0; i < 4; i++) {
		manager.canvas[index * 4 + i] = color[i];
	}
}

sf::Vector2i Element::next_pos(sf::Vector2i pos)
{
	
	return pos;
}
