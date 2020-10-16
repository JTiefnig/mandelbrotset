#include "Application.h"
#include "Plot.h"

#include <complex>
#include <iostream>
#include <math.h> 


Application::Application():
    window(sf::VideoMode(1200, 800), "Mandelbrot"), 
    plot(window.getSize())
{
    // add all the possible Actions... YOLO


}


Application::~Application()
{


}

void Application::run()
{
     

    sf::CircleShape shape(10);
    shape.setFillColor(sf::Color(100, 250, 250));

    Zoom za(&window);

    Plot mandelbrot(window.getSize());

    mandelbrot.render();

    // Main LOOP
    while (window.isOpen())
    {
        window.clear(sf::Color::White);

        sf::Event event;
		while (window.pollEvent(event))
		{
            if (event.type == sf::Event::Closed)
				window.close();


            // for each event...
            za.Execute(event);
			
		}




        window.draw(mandelbrot);

        window.draw(za);

		window.display();
    }



}