
#include <SFML/Graphics.hpp>
#include "Plot.h"
#include "MouseAction.h"
#include <thread>
#include <vector>




class Application
{
public:

    Application();
    
    ~Application();

    void run();



private:
//space for variables
    std::vector<MouseAction*> actions;
    
    sf::RenderWindow window;
    Plot plot;

    

};