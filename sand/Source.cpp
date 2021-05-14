#include <iostream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include "Manager.h"

int height = 1080;
int width = 1920;

int stroke = 20;

int main() {

	sf::RenderWindow window(sf::VideoMode(width, height), "Noise", sf::Style::Fullscreen);

	// Object used to put the image on screen
	sf::Texture texture;
	sf::Sprite sprite;
	texture.create(width, height);
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	sf::Vector2i mouse_pos;

	sf::Uint8* pixels = new sf::Uint8[width * height * 4];

	for (int i = 0; i < width * height * 4; i++) {
		pixels[i] = 0;
	}

	Manager manager(width, height, pixels);
	
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (y == 0 || x == 0 || y == height - 1 || x == width - 1) {
				//manager.base.add(sf::Vector2i(x, y));
			}
			
		}
	}

	

	while (window.isOpen()) {

		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
			}

		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			mouse_pos = sf::Mouse::getPosition(window);
			
			for (int x = mouse_pos.x - stroke; x < mouse_pos.x + stroke; x++) {
				for (int y = mouse_pos.y - stroke; y < mouse_pos.y + stroke; y++) {
					//manager.sand.add(sf::Vector2i(x, y));
				}
			}
			;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			mouse_pos = sf::Mouse::getPosition(window);

			for (int x = mouse_pos.x - stroke; x < mouse_pos.x + stroke; x++) {
				for (int y = mouse_pos.y - stroke; y < mouse_pos.y + stroke; y++) {
					//manager.water.add(sf::Vector2i(x, y));
				}
			}
			;
		}

		manager.permute_all();
	
		window.clear(sf::Color::Black);

		texture.update(pixels);

		window.draw(sprite);



		window.display();
	}


}

