#include <SFML/Graphics.hpp>
#include <iostream>

constexpr unsigned int WIDTH = 1600u;
constexpr unsigned int HEIGHT = 900u;

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({WIDTH, HEIGHT}), "wEKO");
    window.setFramerateLimit(75);

    // un rectangulo
    sf::RectangleShape rectanguloqlo;
    rectanguloqlo.setSize(sf::Vector2f(50, 50));
    rectanguloqlo.setOrigin({rectanguloqlo.getSize().x / 2, rectanguloqlo.getSize().y / 2});
    rectanguloqlo.setFillColor(sf::Color::Red);

    /* obstaculos */
    const unsigned int pared_altura = 300;
    const unsigned int pared_anchura = 20;
    sf::RectangleShape pared;
    pared.setSize(sf::Vector2f(pared_anchura, pared_altura));
    pared.setOrigin({ pared_anchura/2, pared_altura/2});
    pared.setPosition({ WIDTH / 2, HEIGHT / 2 });

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        // limpia las weas anteriores
        window.clear();

        // obtiene posicion del mouse qlo
        sf::Vector2i position = sf::Mouse::getPosition(window);

        // DIBUJAR WEAS
        rectanguloqlo.setPosition({(float) position.x, (float) position.y});
        sf::Vector2f cordenadas_rectanguloqlo = rectanguloqlo.getPosition();

        window.draw(rectanguloqlo);
        
        window.draw(pared);

        // muestra las weas que hay que mostrar
        window.display();
    }
}
