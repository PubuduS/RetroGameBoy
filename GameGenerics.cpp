#include <unistd.h>
#include "include/GameGenerics.h"

GameGenerics::GameGenerics()
{

}

void GameGenerics::GameOverScreen( RenderWindow& window, const Sprite& s_GameOver )
{

    window.clear();
    window.draw( s_GameOver );

    std::string strScore = std::to_string( CalculateScore() );
    std::string textstring = "Score: " + strScore;

    Font font;
    font.loadFromFile( "fonts/arial.ttf" );
    Text text( textstring.c_str(), font, 30 );
    text.setPosition( 100, 300 );
    text.setColor( sf::Color::Red );
    window.draw( text );

    window.display();
    sleep(3);
    window.close();

}
