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
            
            

            std::complex<float> c(fx, fy);
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





sf::Vector2f Plot::transform(sf::Vector2u position)
{

    float rangeX = ;
    float ragneY = ;


    float fx = ((3.0f*position.x/size_x))-2.0f;
    float fy = ((2.0f*position.y/size_y))-1.0f;

    return sf::Vector2f();
}


sf::Vector2u Plot::inverseTransform(sf::Vector2f coordinates)
{


}