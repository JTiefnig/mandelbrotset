#include<SFML/Graphics.hpp>
#include<SFML/Graphics/RenderTarget.hpp>
#include "Plot.h"



class MouseAction
{

public:
    virtual void Execute(sf::Event& event) =0;

};



class Zoom :public sf::Drawable, public MouseAction
{
public:

    Zoom(sf::RenderWindow* win);

    virtual void Execute(sf::Event& event);


    void doZoom();

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


private:

    enum STATE
    {
        NONE =0,
        ONZOOM,
        AFTERZOOM
    };

    STATE state = STATE::NONE;


    sf::RectangleShape rect;

    sf::RenderWindow* window;
};



class Drag : public sf::Drawable, public MouseAction
{
public:
    Drag(sf::RenderWindow *win, Plot *p);

    virtual void Execute(sf::Event& event);


private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    bool activeDrag = false;

    Plot* plot;

    sf::RenderWindow* window;


};