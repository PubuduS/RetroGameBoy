#include <string>
#include "../include/Arkanoid.h"

Arkanoid::Arkanoid() : n( 0 ), blocksRemain( 0 ), remainingLives( 8 ), isGameOver( false )
{
   InitializeVars();
}

void Arkanoid::InitializeVars()
{
   RenderWindow window( VideoMode( LENGTH, WIDTH ), "Arkanoid Game!" );
   window.setFramerateLimit( 60 );

   Texture texture1;
   Texture texture2;
   Texture texture3;
   Texture texture4;
   Texture texture5;

   texture1.loadFromFile( IMAGEPATH+"block01.png" );
   texture2.loadFromFile( IMAGEPATH+"background.jpg" );
   texture3.loadFromFile( IMAGEPATH+"ball.png" );
   texture4.loadFromFile( IMAGEPATH+"paddle.png" );
   texture5.loadFromFile( IMAGEPATH+"Heart.png" );

   Sprite s_Background( texture2 );
   Sprite s_Ball( texture3 );
   Sprite s_Paddle( texture4 );
   Sprite s_Lives( texture5 );

   s_Paddle.setPosition( 300, 440 );
   s_Ball.setPosition( 300, 300 );

   Sprite block[1000];
   Sprite lives[3];

   for( int i = 0; i < 3; i++ )
   {
      lives[i].setTexture( texture5 );
      lives[i].setPosition( i * 24, 0 );
   }

   for( int i = 1; i <= 10; i++)
   {
      for( int j = 1; j <= 10; j++)
      {
         block[n].setTexture( texture1 );
         block[n].setPosition( i * 43, j * 20 );
         n++;
      }
   }

   blocksRemain = n;

   PlayArkanoid( window, s_Background, s_Ball, s_Paddle, block, lives, texture1 );
}

void Arkanoid::CheckCollisions( float& xAxis, float& xPos, float& yAxis, float& yPos, Sprite* block, const bool isVertical = false )
{
   for ( int i = 0; i < n; i++ )
   {
       if ( FloatRect( xAxis + 3, yAxis + 3, 6, 6).intersects( block[i].getGlobalBounds() ) )
       {
           block[i].setPosition( -100, 0 );
           blocksRemain--;

           if( isVertical == true )
           {
               yPos = -yPos;
           }
           else
           {
               xPos = -xPos;
           }

       }
   }
}

void Arkanoid::SetBoundaries( float& xAxis, float& xPos, float& yAxis, float& yPos, Sprite* lives )
{
    if ( ( xAxis < 0 ) || ( xAxis > LENGTH ) )
    {
        xPos = -xPos;
    }

    if ( ( yAxis < 0 ) || ( yAxis > WIDTH ) )
    {
        yPos = -yPos;
    }

    if( yAxis == WIDTH )
    {
      remainingLives--;
      SetLives( lives );
    }

}

void Arkanoid::SetControls( Sprite& s_Paddle )
{
      if ( Keyboard::isKeyPressed( Keyboard::Right ) )
      {
         s_Paddle.move( 6, 0 );
      }

      if ( Keyboard::isKeyPressed( Keyboard::Left ) )
      {
         s_Paddle.move( -6, 0 );
      }
}

void Arkanoid::SetLives( Sprite* lives )
{
    if( remainingLives == 6 )
    {
        lives[2].setPosition( -100, 0 );
    }
    else if( remainingLives == 4 )
    {
        lives[1].setPosition( -100, 0 );
    }
    else if( remainingLives == 2 )
    {
        lives[0].setPosition( -100, 0 );
    }
    else if( remainingLives == 0 )
    {
        isGameOver = true;
    }
}

int Arkanoid::CalculateScore()
{
   int score = 0;
   const int eliminatedBlocks = ( n - blocksRemain );
   const int eliminatedBlocksScore = ( eliminatedBlocks * 100 );

   int heartBonus = 0;

    if( remainingLives == 6 )
    {
        heartBonus = 6000;
    }
    else if( remainingLives == 4 )
    {
        heartBonus = 4000;
    }
    else if( remainingLives == 2 )
    {
        heartBonus = 2000;
    }
    else if( remainingLives == 0 )
    {
        heartBonus = 0;
    }

   score = ( eliminatedBlocksScore + heartBonus );

   return score;
}

void Arkanoid::PlayArkanoid( RenderWindow& window, Sprite& s_Background, Sprite& s_Ball, Sprite& s_Paddle, Sprite* block, Sprite* lives, Texture& texture1 )
{

   srand( time( 0 ) );
   float xPos = 6;
   float yPos = 5;
   float xAxis = 300;
   float yAxis = 300;

   while ( window.isOpen() )
   {
      Event event;
      while (window.pollEvent( event ) )
      {
        if ( event.type == Event::Closed )
        {
            window.close();
        }

      }

      if( isGameOver != true )
      {

         xAxis += xPos;
         CheckCollisions( xAxis, xPos, yAxis, yPos, block, false);

         yAxis += yPos;
         CheckCollisions( xAxis, xPos, yAxis, yPos, block, true);

         SetBoundaries( xAxis, xPos, yAxis, yPos, lives );

         SetControls( s_Paddle );

         // Make ball bounce on the Paddle.
         if ( FloatRect( xAxis, yAxis, 12, 12 ).intersects( s_Paddle.getGlobalBounds() ) )
         {
            yPos = -( rand() % 5 + 2 );
         }

         // Make the ball moving.
         s_Ball.setPosition( xAxis, yAxis );

         // Draw Sprites
         window.clear();
         window.draw( s_Background );
         window.draw( s_Ball );
         window.draw( s_Paddle );

         for ( int i = 0; i < n; i++)
         {
            if( i < 3)
            {
               window.draw( lives[i] );
            }
            window.draw( block[i] );
         }

         window.display();

      }
      else
      {
          //Draw Sprites
          GameOverScreen( window );
      }

   }

}
