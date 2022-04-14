#include "../Headers/main.h"

using namespace sf;

void Circle_Draw_posed (RenderWindow *Window, float x, float y, float R, Color color) {
    CircleShape Circle(R, 50);
    Circle.setFillColor(Color(0,0,0,0) );
    Circle.setOutlineThickness(1);
    Circle.setOutlineColor(color);
    Circle.move(x-R, y-R);
    Window->draw(Circle);
}

void Draw_lighten (RenderWindow *Window, int x, int y, int intensity) {
    int alfa;
    for (int i = intensity; i != 0; i--) {
        alfa = i;
        if (alfa > 255) alfa = 255;
        Circle_Draw_posed(Window, (float) x,(float) y, (float) (intensity-i), Color (255, 255, 255, alfa));
    }
}


void Game_Cicle () {
    ContextSettings settings; settings.antialiasingLevel = 8; int x = 1000, y = 1000;

    RenderWindow Window(VideoMode(x, y), "Chart World", Style::Default, settings);
    Window.setFramerateLimit(60);
    Event event;
    int Mouse_Pos_x = Mouse::getPosition(Window).x;
    int Mouse_Pos_y = Mouse::getPosition(Window).y;

    bool tick = true; int pulse = 0;

    while (Window.isOpen()) {

        while (Window.pollEvent(event)) { if (event.type == Event::Closed) { Window.close(); } }
        Window.clear(Color::Black);

        if (event.type == Event::Resized) {
            Window.setView(View(FloatRect(0, 0, (float) Window.getSize().x, (float) Window.getSize().y)));
        }

        if (event.type == Event::MouseMoved) {
            if ((Mouse_Pos_x != Mouse::getPosition(Window).x) or (Mouse_Pos_y != Mouse::getPosition(Window).y)) {
                pulse++;
            }
            else if (pulse > 0) {
                pulse--;
            }
            Mouse_Pos_x = Mouse::getPosition(Window).x;
            Mouse_Pos_y = Mouse::getPosition(Window).y;

        }

        Draw_lighten (&Window, Mouse_Pos_x, Mouse_Pos_y, pulse);
        /*
        if (pulse == 255) tick = false;
        else if (pulse == 0) tick = true;

        if (tick == true) pulse++;
        else if (tick == false) pulse--;
        */
        Window.display();


    }
}

int main(int argc, char *argv[])
{
    Game_Cicle();

    return 0;
}