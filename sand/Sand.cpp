#include "Sand.h"
#include "Water.h"

int Sand::default_color[4] = { 239, 221, 111, 255 };

Sand::Sand(Manager& manager) : Element(manager)
{
	for (int i = 0; i < 4; i++) {
		color[i] = default_color[i];
	}
}

void Sand::permute_all()
{
	for (auto& pos : points) {
		auto new_pos = this->next_pos(pos);
		pos = new_pos;
	}
}

sf::Vector2i Sand::next_pos(sf::Vector2i pos)
{
	int x_shifts[3] = { 0, 1, -1 };

	sf::Vector2i new_pos = sf::Vector2i(pos.x, pos.y + 1);
	int x_temp = new_pos.x;
	for (int i = 0; i < 3; i++) {
		new_pos.x = x_temp + x_shifts[i];
		if (manager.is_color(manager.vector_to_int(new_pos), empty) || 
			manager.is_color(manager.vector_to_int(new_pos), Water::default_color)) {
			move(pos, new_pos);
			return new_pos;
		}
	}
	return pos;
}


