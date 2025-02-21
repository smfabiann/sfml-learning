#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

constexpr unsigned int WIDTH = 1600u;
constexpr unsigned int HEIGHT = 900u;
const unsigned int FPS = 60;

class BolitaConGravedad : public sf::CircleShape {
private:
    const int masa = 1;
    const sf::Vector2f aceleracion = {0, 1};
    sf::Vector2f velocidad = {0, 0};
    /*sf::Vector2f peso = aceleracion();*/
public:
    BolitaConGravedad(float diametro) : sf::CircleShape(diametro) {};
    
    /* gets */
    sf::Vector2f getVelocidad() { return velocidad; }
    int getMasa() { return masa; }

    /* sets */
    void setVelocidad(sf::Vector2f v) { velocidad = v; };

    void update() {
        if (getPosition().y > HEIGHT - getRadius()) {
            velocidad = {-velocidad.x, -velocidad.y};
            setPosition({ getPosition().x, HEIGHT - getRadius() });
        }
        velocidad += aceleracion;
        setPosition(getPosition() + velocidad);
    }
};

BolitaConGravedad spawnearBolita(const sf::Vector2f& position) {
    const float tamano = 26.0f;
    BolitaConGravedad circulo(tamano);
    circulo.setOrigin({ tamano / 2, tamano / 2 });
    circulo.setFillColor(sf::Color::Magenta);
    circulo.setPosition(position);
    return circulo;
}

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({WIDTH, HEIGHT}), "wEKO");
    window.setFramerateLimit(60);

    /* almacen de bolitas */
    std::vector<BolitaConGravedad> bolitas;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            
        }
        window.clear();

        /* aqui se dibujan weas */
        // obtiene posicion del mouse qlo
        
        sf::Vector2f mouse_position(sf::Mouse::getPosition(window));
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            bolitas.push_back(spawnearBolita(mouse_position));
        }
        
        // diguja las bolitas
        for (BolitaConGravedad& i: bolitas) {
            window.draw(i);
        }

        // encargado de la gravedad
        for (BolitaConGravedad& i : bolitas) {
            i.update();
        }

        window.display();
    }
}
