#ifndef PLOT
#define PLOT


#include <SFML/Graphics.hpp>







// plot of the Mandelbrot set...

class Plot : public sf::Drawable
{
public: 

    Plot(sf::Vector2u size)
        :Plot(size.x, size.y)
    {}

    Plot(unsigned int x, unsigned int y)
        :size_x(x), size_y(y)
    {
        // überleg ma uns no
        pixelMatrix.resize(x*y*4);
        texture.create(size_x, size_y);
    }

    void render();

    sf::Vector2f transform(sf::Vector2u position);
    sf::Vector2u inverseTransform(sf::Vector2f coordinates);

private:

    const unsigned int size_x, size_y;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    std::vector<sf::Uint8> pixelMatrix;

    void putpixel(unsigned int x, unsigned int y, const sf::Color& col);

    sf::Color ColorGradient(int val, int base);

    sf::Vector2f min;
    sf::Vector2f max;

    sf::Texture texture;

    unsigned int x, y;
    sf::Sprite sprite;
};

#endif