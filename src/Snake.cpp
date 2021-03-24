#include "../include/Snake.h"

Snake::Snake() : m_direction(0), m_SnakeLength(4), m_Score(0), m_IsGameOver(false)
{
    InitializeVars();
}

void Snake::InitializeVars()
{
    RenderWindow window( VideoMode( WIDTH, HEIGHT ), "Snake Game!" );

    Texture texture1;
    Texture texture2;

    texture1.loadFromFile( "images/Snake_Img/white.png" );
    texture2.loadFromFile( "images/Snake_Img/red.png" );

    Sprite sprite1( texture1 );
    Sprite sprite2( texture2 );

    m_MyFruit.x = 10;
    m_MyFruit.y = 10;

    PlaySnake( window, sprite1, sprite2 );
}

int Snake::CalculateScore()
{
    const int score = m_Score;
    return score;
}

void Snake::MoveSnake()
{
    for( int i = m_SnakeLength; i > 0; i-- )
    {
        m_MySnake[i].x = m_MySnake[i-1].x;
        m_MySnake[i].y = m_MySnake[i-1].y;
    }

    MoveToThisDirection();
    GrowUponEat();
    BoundaryControl();
    GameOverLogic();

}

void Snake::GameOverLogic()
{
    for( int i = 1; i < m_SnakeLength; i++)
    {
        if( ( m_MySnake[0].x == m_MySnake[i].x ) && ( m_MySnake[0].y == m_MySnake[i].y ) )
        {
            m_IsGameOver = true;
        }
    }
}

void Snake::GrowUponEat()
{
    if( ( m_MySnake[0].x == m_MyFruit.x ) && ( m_MySnake[0].y == m_MyFruit.y ) )
    {
        m_SnakeLength++;
        m_Score += 100;
        m_MyFruit.x = rand() % N;
        m_MyFruit.y = rand() % M;
    }
}

void Snake::BoundaryControl()
{
    if( m_MySnake[0].x > N )
    {
        m_MySnake[0].x = 0;
    }

    if( m_MySnake[0].x < 0 )
    {
        m_MySnake[0].x = N;
    }

    if( m_MySnake[0].y > M )
    {
        m_MySnake[0].y = 0;
    }

    if( m_MySnake[0].y < 0 )
    {
        m_MySnake[0].y = M;
    }
}

void Snake::MoveToThisDirection()
{

    if( m_direction == 0 )
    {
        m_MySnake[0].y += 1;
    }
    else if( m_direction == 1 )
    {
        m_MySnake[0].x -= 1;
    }
    else if( m_direction == 2 )
    {
        m_MySnake[0].x += 1;
    }
    else
    {
        m_MySnake[0].y -= 1;
    }


}

void Snake::KeyControls()
{
    if( Keyboard::isKeyPressed( Keyboard::Left ) )
    {
        m_direction = 1;
    }

    if( Keyboard::isKeyPressed( Keyboard::Right ) )
    {
        m_direction = 2;
    }

    if( Keyboard::isKeyPressed( Keyboard::Up ) )
    {
        m_direction = 3;
    }

    if( Keyboard::isKeyPressed( Keyboard::Down ) )
    {
        m_direction = 0;
    }
}

void Snake::DrawSprites( RenderWindow& window, Sprite& sprite1, Sprite& sprite2 )
{
    //Draw
    window.clear();

    for( int i = 0; i < N; i++ )
    {
        for( int j = 0; j < M; j++ )
        {
            sprite1.setPosition( ( i * SIZE ), ( j * SIZE ) );
            window.draw( sprite1 );
        }
    }

    for( int i = 0; i < m_SnakeLength; i++)
    {
        sprite2.setPosition( ( m_MySnake[i].x * SIZE ), ( m_MySnake[i].y * SIZE) );
        window.draw( sprite2 );
    }

    sprite2.setPosition( ( m_MyFruit.x * SIZE ), (m_MyFruit.y * SIZE) );
    window.draw( sprite2 );


}

void Snake::PlaySnake( RenderWindow& window, Sprite& sprite1, Sprite& sprite2 )
{
    srand( time( 0 ) );
    Clock clock;
    float timer = 0;
    float delay = 0.1;

    while( window.isOpen() )
    {

        const float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event event;

        while( window.pollEvent( event ) )
        {
            if( event.type == Event::Closed )
            {
                window.close();
            }
        }

        if( m_IsGameOver != true )
        {
            KeyControls();

            if( timer > delay )
            {
                timer = 0;
                MoveSnake();
            }

            DrawSprites( window, sprite1, sprite2 );
            window.display();
        }
        else
        {
          //Draw GameOver Screen
          GameOverScreen( window );
        }


    }


}
