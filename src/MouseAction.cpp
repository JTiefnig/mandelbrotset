#include "MouseAction.h"
#include <iostream>


Zoom::Zoom(sf::RenderWindow* win)
    :window(win)
{
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(2);
    rect.setFillColor(sf::Color::Transparent);
}

void Zoom::Execute(sf::Event& event)
{
    switch (this->state)
    {
    case STATE::NONE:
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            auto pos = sf::Mouse::getPosition(*window);
            rect.setPosition(sf::Vector2f(pos));
            state = STATE::ONZOOM;
        }
        break;
    case STATE::ONZOOM:

        if (event.type == sf::Event::MouseMoved)
			{
                auto size = sf::Vector2f(sf::Mouse::getPosition(*window)) - rect.getPosition();
                rect.setSize(size);
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
                state=STATE::AFTERZOOM;
			}


        break;
    case STATE::AFTERZOOM:

            rect.setSize(sf::Vector2f());
            state=STATE::NONE;
            // do the zoom action in plot
            doZoom();//lol
        break;
    
    default:
        break;
    }
}



void Zoom::doZoom()
{
    std::cout << "did zoom function" << std::endl;

}

void Zoom::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(rect, states);
}



Drag::Drag(sf::RenderWindow *win, Plot *p):
    window(win), plot(p)
{

}

void Drag::Execute(sf::Event& event)
{
    if(!activeDrag)
    {
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
        {
            auto pos = sf::Mouse::getPosition(*window);
            activeDrag=true;
        }

    }else
    {
        if (event.type == sf::Event::MouseMoved)
        {
            auto pos = sf::Mouse::getPosition(*window);

        }
        if(event.type == sf::Event::MouseButtonReleased)
        {
            // re-render

            activeDrag=false;
        }   
    }
    

}



void Drag::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{



}