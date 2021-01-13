#include "Plot.h"
#include <SFML/Graphics/Sprite.hpp>
#include <math.h>
#include <complex>
#include <iostream>

void Plot::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

    target.draw(sprite, states);


    auto col = sf::Color::White;
    int precision =5;

    for(int x=0; x<precision; x++)
    {

    }
    
}


void Plot::putpixel(unsigned int x, unsigned int y, const sf::Color& col)
{
    pixelMatrix[((y*size_x)+x)*4] = col.r;
    pixelMatrix[((y*size_x)+x)*4+1] = col.g;
    pixelMatrix[((y*size_x)+x)*4+2] = col.b;
    pixelMatrix[((y*size_x)+x)*4+3] = col.a;
}




void Plot::render()  
{
    int maxiter=20;

    int sx = (int)size_x;
    int sy = (int)size_y;

    for(int x=0; x<sx; x++)
    {
        for(int y=0; y<sy; y++)
        {
            
            auto coo = transform(sf::Vector2u(x, y));

            std::complex<float> c(coo.x, coo.y);
            std::complex<float> z;


            int n =maxiter;
            
            for(; n>0; n--)
            {

                z = std::pow(z,2) + c;

                if(std::abs(z) > 4)
                {
                    break;
                }

            }
        
            putpixel(x, y, ColorGradient(n, maxiter));
        }
    }

    texture.update(pixelMatrix.data());

    sprite.setTexture(texture, true);


}


sf::Color Plot::ColorGradient(int val, int base) // base is reference value
{
    if(val<0 || base < 0 || val > base)
        return sf::Color::Black;

    float k = 1.0f*(base-val)/base;

    uint8_t r = (uint8_t)255*k;
    uint8_t g = (uint8_t)255*(1-pow(2*k-1,2));
    uint8_t b = (uint8_t)255*(pow(2*k-1, 3)+1)/2;
    uint8_t a = (uint8_t)255*(pow(2*k-1,2)/2+0.5);

    return sf::Color(r, g, b, a);
}




// Transforms a point on the screen to the set coordinate system
sf::Vector2f Plot::transform(sf::Vector2u position)
{
    float rangeX = max.x - min.x;
    float rangeY = max.y - min.y;

    float fx = ((position.x)*rangeX)/size_x + min.x;
    float fy = (((size_y-position.y))*rangeY)/size_y + min.y;

    return sf::Vector2f(fx, fy);
}


sf::Vector2u Plot::inverseTransform(sf::Vector2f coordinates)
{
    // todo

}

void Plot::SetArea(float x1, float y1, float x2, float y2)
{
    if(x1 < x2)
    {
        min.x = x1;
        max.x = x2;
    }else
    {
        min.x = x2;
        max.x = x1;
    }
    
    if(y1 < y2)
    {
        min.y = y1;
        max.y = y2;
    }else
    {
        min.y = y2;
        max.y = y1;
    }
    


}