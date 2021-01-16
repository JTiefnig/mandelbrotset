#ifndef PLOT
#define PLOT


#include <SFML/Graphics.hpp>


template<typename T>
struct Rect
{
    T X1, X2, Y1, Y2;

    Rect(T x1, T y1, T x2, T y2)
    :X1(x1), X2(x2), Y1(y1), Y2(y2)
    {}

    Rect(){}
};


// plot of the Mandelbrot set...

class Plot : public sf::Drawable
{
public: 

    Plot(sf::Vector2u size)
        :Plot(size.x, size.y)
    {
        min.x = -2;
        min.y = -1;
        max.x = 1;
        max.y = 1;
    }

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

    void SetArea(float x1, float y1, float x2, float y2);

private:

    const unsigned int size_x, size_y;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    std::vector<sf::Uint8> pixelMatrix;

    void putpixel(unsigned int x, unsigned int y, const sf::Color& col);

    sf::Color ColorGradient(float val, float base);

    sf::Vector2f min;
    sf::Vector2f max;

    sf::Texture texture;

    unsigned int x, y;
    sf::Sprite sprite;
};

#endif