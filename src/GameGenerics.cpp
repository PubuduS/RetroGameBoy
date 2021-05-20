#include <unistd.h>
#include <string>
#include "../include/GameGenerics.h"

GameGenerics::GameGenerics()
{

}

void GameGenerics::GameOverScreen( RenderWindow& window )
{
    Texture texture;
    texture.loadFromFile( "images/Arkanoid_Img/gameover.png" );
    Sprite s_GameOver( texture );
    s_GameOver.setPosition( 50, 50 );

    window.clear();
    window.draw( s_GameOver );

    std::string strScore = std::to_string( CalculateScore() );
    std::string textstring = "Score: " + strScore;

    Font font;
    font.loadFromFile( "fonts/arial.ttf" );
    Text text( textstring.c_str(), font, 30 );
    text.setPosition( 100, 250 );
    text.setFillColor( sf::Color::Red );
    window.draw( text );

    window.display();
    sleep(3);
    window.close();

}
