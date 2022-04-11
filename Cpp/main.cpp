#include "../Headers/main.h"

using namespace sf;

void Circle_Draw (RenderWindow *Win, float R, int red, int blue, int green, int alpha) {
    CircleShape Circle(R, 50);
    Circle.setFillColor(Color(red, green, blue, alpha));
    Circle.move((Win->getSize().x)/2.0-R, (Win->getSize().y)/2.0-R);
    //cout << Circle.getOrigin().x << " " << Circle.getOrigin().y << endl;
    Win->draw(Circle);
}

void Set_Pixel (RenderWindow *Win, int x, int y, Color color) {
    RectangleShape pixel;
    pixel.setSize(Vector2f(1, 1));
    pixel.setFillColor(color);
    pixel.setPosition((float) x, (float) y);
    Win ->draw(pixel);
}

void Game_Cicle () {
    ContextSettings settings; settings.antialiasingLevel = 8; int x = 100, y = 600;

    RenderWindow Window(VideoMode(x, y), "Chart World", Style::Default, settings);
    Window.setFramerateLimit(60);
    Event event;

    while (Window.isOpen()) {

        while (Window.pollEvent(event)) { if (event.type == Event::Closed) { Window.close(); } }
        Window.clear(Color::Black);

        if (Keyboard::isKeyPressed(Keyboard::D)) {
            Window.setSize(Vector2u(Window.getSize().x+20, Window.getSize().y));
            Window.setView(View(FloatRect(0, 0, Window.getSize().x, Window.getSize().y)));
        }
        else if (Keyboard::isKeyPressed(Keyboard::A)) {
            Window.setSize(Vector2u(Window.getSize().x-20, Window.getSize().y));
            Window.setView(View(FloatRect(0, 0, Window.getSize().x, Window.getSize().y)));
        }
        else if (Keyboard::isKeyPressed(Keyboard::W)) {
            Window.setSize(Vector2u(Window.getSize().x, Window.getSize().y-20));
            Window.setView(View(FloatRect(0, 0, Window.getSize().x, Window.getSize().y)));
        }
        else if (Keyboard::isKeyPressed(Keyboard::S)) {
            Window.setSize(Vector2u(Window.getSize().x, Window.getSize().y+20));
            Window.setView(View(FloatRect(0, 0, Window.getSize().x, Window.getSize().y)));
        }
        cout << Window.getSize().x << " " << Window.getSize().y << " <---" << endl;

        Circle_Draw (&Window, 100, 255, 255, 255, 255);
        //Circle_Draw (&Window, 4, 255, 0, 0, 255);
        //Set_Pixel(&Window, Window.getSize().x/2, Window.getSize().y/2, Color (255, 0, 0, 255));


        Window.display();
    }
}

int main(int argc, char *argv[])
{
    Game_Cicle();

    return 0;
}