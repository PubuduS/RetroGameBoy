#include "include/Tetris.h"

Tetris::Tetris()
{
   
   for( int row = 0; row < M; row++ )
   {
      for( int col = 0; col < N; col++ )
      {
         field[row][col] = 0;
      }
   }
   
   // Initialize struct array
   for( int i = 0; i < 4; i++ )
   {
      a[i].x = 0;
      a[i].y = 0;
      b[i].x = 0;
      b[i].y = 0;
   }

}

void Tetris::PlayTetris()
{   
   srand( time(0) );
   RenderWindow window( VideoMode( 320, 480 ), "The Game!" );
   
   // Load Tiles
   Texture texture1;
   Texture texture2;
   Texture texture3;
   texture1.loadFromFile( "images/tiles.png" );
   texture2.loadFromFile("images/background.png");
   texture3.loadFromFile("images/frame.png");
   
   Sprite sprite( texture1 ); 
   Sprite background( texture2 );
   Sprite frame( texture3 );
   sprite.setTextureRect( IntRect( 0, 0, 18, 18 ) );   
   
   int dx = 0;
   bool rotate = false;
   int colorNum = 1;  
   float timer = 0;
   float delay = 0.3;
   
   Clock clock;
   
   // Window Form
   while( window.isOpen() )
   {
   
      float time = clock.getElapsedTime().asSeconds();
      clock.restart();
      timer += time;
      
      EventHandler( rotate, dx, window );
      
      if( Keyboard::isKeyPressed( Keyboard::Down ) )
      {
         delay = 0.05; 
      }
      
      MoveTile( dx );
      
      RotateTile( rotate );
      
      timer = MoveDownTilePerClick( timer, delay, colorNum );
      
      CheckLines();
            
      dx = 0; 
      rotate = false;
      delay = 0.3;
      
      Draw( sprite, background, frame, window, colorNum );
      
   }
}

void Tetris::EventHandler( bool& rotate, int& dx, RenderWindow& window )
{
    Event event;
      
    while( window.pollEvent( event ) )
    {
       if( event.type == Event::Closed )
       {         
          window.close();
       }
            
       if( event.type == Event::KeyPressed )
       {
          if( event.key.code == Keyboard::Up )
          {
             rotate = true;
          }
          else if( event.key.code == Keyboard::Left )
          {
             dx = -1;
          }
          else if( event.key.code == Keyboard::Right )
          {
             dx = 1;
          }
       }
    }
}

bool Tetris::Check()
{

   for( int i = 0; i < 4; i++)
   {
      if( ( a[i].x < 0 ) || ( a[i].x >= N ) || ( a[i].y >= M ) )
      {         
         return false;
      }
      else if( field[ a[i].y ][ a[i].x ] )
      {         
         return false;
      }
      
   }
   return true;
}

void Tetris::MoveTile( const int position )
{
    // Move
    for( int i = 0; i < 4; i++)
    {
       b[i] = a[i];
       a[i].x += position;
    }
     
    if( !Check() )
    {
       for( int i = 0; i < 4; i++ )
       {
          a[i] = b[i];         
       }
    }
}

void Tetris::RotateTile( const bool rotate )
{
    // Roatate
    if( rotate )
    {
       // Center of rotation
       Point point =  a[1];
       for( int i = 0; i < 4; i++)
       {
          const int x = a[i].y - point.y;
          const int y = a[i].x - point.x;
          a[i].x = point.x - x;
          a[i].y = point.y + y;
       }
         
       if( !Check() )
       {
          for( int i = 0; i < 4; i++ )
          {
             a[i] = b[i];         
          }
       }
         
    }

}

float Tetris::MoveDownTilePerClick( float timer, const float delay, int& colorNum )
{
    // Move 1 down per Tick
    if( timer > delay )
    {
       for( int i = 0; i < 4; i++ )
       {
          a[i].y += 1;            
       }
         
       if( !Check() )
       {
          for( int i = 0; i < 4; i++)
          {
             field[ b[i].y ][ b[i].x ] = colorNum;
          }
            
          colorNum = 1 + rand() % 7;          
          int n = rand() % 7;
          for( int i = 0; i < 4; i++ )
          {
             a[i].x = figures[n][i] % 2;
             a[i].y = figures[n][i] / 2;
          }
            
       }
         
       timer = 0;
    }
   
    return timer;
}

void Tetris::CheckLines()
{

    // Check lines
    int k = M-1;
    for (int i = M-1; i > 0; i--)
    {
        int count = 0;
        for ( int j = 0; j < N; j++ )
        {
            if ( field[i][j] != 0 ) 
            {                     
               count++;                            
            }         

            field[k][j] = field[i][j];            
                    
        }       

        if ( count < N )
        { 
           k--;           
        }
    }

}

int Tetris::CalculateScore()
{
   int score = 0;
   // Need to be Implemented.
   return score;
}

void Tetris::GameOverScreen( RenderWindow& window, const Sprite& s_GameOver )
{
   //This function is not implemented yet.
   std::cout<<" I have nothing to do "<<std::endl;
}

void Tetris::Draw( Sprite& sprite, Sprite& background, Sprite& frame, RenderWindow& window, const int& colorNum )
 {
     // Draw
    window.clear( Color::White );
    window.draw( background );
      
    for( int i = 0; i < M; i++ )
    {
       for( int j = 0; j < N; j++ )
       {
          if( field[i][j] == 0 )
          {
             continue;
          }
          sprite.setTextureRect( IntRect( field[i][j]*18, 0, 18, 18 ) );
          sprite.setPosition( j * 18, i * 18);
          
          // Offset
          sprite.move( 28, 31 ); 
          window.draw( sprite );
       }
    }
      
    for( int i = 0;  i < 4; i++ )
    {
       sprite.setTextureRect( IntRect( colorNum*18, 0, 18, 18 ) );
       sprite.setPosition( a[i].x * 18, a[i].y * 18 ); 
       
       // Offset
       sprite.move( 28, 31 ); 
       window.draw( sprite );    
    }
    
    
    Font font; 
    font.loadFromFile( "fonts/arial.ttf" );   
    Text text( "Score:", font, 30 );
    text.setPosition( window.getSize().x*0.09, window.getSize().y - text.getGlobalBounds().height - text.getGlobalBounds().top );
    text.setColor( sf::Color::Red );
    window.draw( text );  
    
    window.draw( frame );
    window.display();  
 }
