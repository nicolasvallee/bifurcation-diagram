#include "SFML/Graphics.hpp"

const int PLOT_HEIGHT = 8000;
const int PLOT_WIDTH = 16000;

void makePlot(sf::VertexArray drawing)
{
    sf::RenderTexture screen;
    screen.create(PLOT_WIDTH, PLOT_HEIGHT);
    screen.clear(sf::Color::White);

    screen.draw(drawing);
    screen.display();

    sf::Texture texture = screen.getTexture();

    sf::Image plot = texture.copyToImage();
    //std::string name = get_file_name();x
    plot.saveToFile("myPlot.png");
}


sf::VertexArray function()
{
    double a = 3.4;
    double b = 4;

    sf::VertexArray diagram(sf::Points);

    for(int i = 0; i < PLOT_WIDTH; i++)
    {
        double r = a + (b - a) * i / PLOT_WIDTH;

        double pop = 0.5;

        for(int day = 0; day < 1000; day++)
        {
            pop = r * pop * (1.0 - pop);

            if(day >= 100)
            {
                diagram.append(sf::Vertex(sf::Vector2f(i, PLOT_HEIGHT * (1 - pop)), sf::Color::Black));
            }

        }
    }
        
    return diagram;
}

int main()
{
    makePlot(function());
}

