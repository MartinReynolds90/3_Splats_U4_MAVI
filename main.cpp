#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <cstdlib>
#include <ctime>
#include "iostream"
using namespace std;
using namespace sf;

int main() {
	RenderWindow ventana(VideoMode(800, 600), "Splats");
	Event evento;

	int x = 0;
	int z = 0;
	Sprite puntos_rojos[100];
	Sprite puntos_azules[100];

	while (ventana.isOpen()) {
		while (ventana.pollEvent(evento)) {
			if (evento.type == Event::MouseButtonPressed) {
				if (evento.key.code == Mouse::Left) {
					Sprite punto_rojo;
					Texture rojo;
					rojo.loadFromFile("rcircleg.png");
					punto_rojo.setTexture(rojo);
					puntos_rojos[x] = punto_rojo;
					Vector2f pos;
					pos.x = Mouse::getPosition(ventana).x;
					pos.y = Mouse::getPosition(ventana).y;
					puntos_rojos[x].setPosition(Vector2f(pos.x, pos.y));
					x++;
				}
				if (evento.key.code == Mouse::Right) {
					Sprite punto_azul;
					Texture azul;
					azul.loadFromFile("rcircleb.png");
					punto_azul.setTexture(azul);
					puntos_azules[z] = punto_azul;
					Vector2f pos;
					pos.x = Mouse::getPosition(ventana).x;
					pos.y = Mouse::getPosition(ventana).y;
					puntos_azules[z].setPosition(Vector2f(pos.x, pos.y));
					z++;
				}
			}


		}

		ventana.clear(Color::Magenta);
		for (int i = 0; i < 100; i++) {
			ventana.draw(puntos_rojos[i]);
		}
		for (int i = 0; i < 100; i++) {
			ventana.draw(puntos_azules[i]);
		}
		ventana.display();

	}
		return 0;
	}