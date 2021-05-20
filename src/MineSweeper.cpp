#include "../include/MineSweeper.h"

MineSweeper::MineSweeper()
{
  InitializeVars();
}

void MineSweeper::InitializeVars()
{
   // Add time as the seed for generating randome values.
   srand( time( 0 ) );
   openTiles = 0;
   // Create a window.
   RenderWindow window( VideoMode( LENGTH, WIDTH ), "MineSweeper!");

   Texture texture;
   texture.loadFromFile( IMAGEPATH + "tiles.jpg" );
   Sprite sprite( texture );

   // Setting the UI and populate value grid using random numbers.
   for( int i = 1; i <= 10; ++i )
   {
      for( int j = 1; j <= 10; ++j )
      {
         // Initialize UI grid with greay tiles.
         // 10 means greay tile in tiles.jpg.
         m_UIgrid[i][j] = 10;

         if( rand() % 5 == 0 )
         {
            m_Grid[i][j] = 9;
         }
         else
         {
            m_Grid[i][j] = 0;
         }

      }

   }

   CalculateDistanceFromAllDirections();
   PlayMineSweeper( window, sprite );
}


void MineSweeper::PlayMineSweeper( RenderWindow& window, Sprite& sprite )
{

   while( window.isOpen() )
   {

      // Store x and y axis data.
      Vector2i position = Mouse::getPosition( window );
      int x = position.x / DIMENSIONS;
      int y = position.y / DIMENSIONS;

      MouseEventListener( window, x, y );

      window.clear( Color::White );

      DrawOnUI( window, sprite, x, y );

      window.display();
   }

}

void MineSweeper::CalculateDistanceFromAllDirections()
{

   for( int i = 1; i <= 10; ++i )
   {

      for( int j = 1; j <= 10; ++j )
      {
         int n = 0;

         // Check the current row and current column.
         if( m_Grid[i][j] == 9 )
            continue;

         // Next Row Same Column
         if( m_Grid[i+1][j] == 9 )
            ++n;

         // Same Row Next Column
         if( m_Grid[i][j+1] == 9 )
            ++n;

         // Previous Row Same Column
         if( m_Grid[i-1][j] == 9 )
            ++n;

         // Same Row Previous Column
         if( m_Grid[i][j-1] == 9 )
            ++n;

         // Next Row Next Column
         if( m_Grid[i+1][j+1] == 9 )
            ++n;

         // Previous Row Previous Column
         if( m_Grid[i-1][j-1] == 9 )
            ++n;

         // Previous Row Next Column
         if( m_Grid[i-1][j+1] == 9 )
            ++n;

         // Next Row Previos Previous Column
         if( m_Grid[i+1][j-1] == 9 )
            ++n;

         // Place Numbers among tiles
         m_Grid[i][j] = n;
      }

   }

}

void MineSweeper::MouseEventListener( RenderWindow& window, const int x, const int y )
{

   Event event;

   while( window.pollEvent( event ) )
   {

      if( event.type == Event::Closed )
      {
        window.close();
      }

      if( event.type == Event::MouseButtonPressed )
      {
         if( event.mouseButton.button == Mouse::Left )
         {
            // Open Tile
            m_UIgrid[x][y] = m_Grid[x][y];

            // For each open tile we mark it to assign score.
            openTiles += 1;

            // If user click the bomb, we don't want to mark it
            // to allocate score.
            if( m_UIgrid[x][y] == 9 )
            {
               openTiles -= 1;
            }

         }
         else if( event.mouseButton.button == Mouse::Right )
         {
            // Mark the Tile with a flag.
            // 11 means 11th of square of the titles.jpg.
            m_UIgrid[x][y] = 11;
         }
      }

   }

}

void MineSweeper::DrawOnUI( RenderWindow& window, Sprite& sprite, const int x, const int y )
{

   for( int i = 1; i <= 10; ++i )
   {
      for( int j = 1; j <= 10; ++j )
      {
         if( m_UIgrid[x][y] == 9 )
         {
            m_UIgrid[i][j] = m_Grid[i][j];
         }

         // Insert sprites to the UI.
         sprite.setTextureRect( IntRect( m_UIgrid[i][j] * DIMENSIONS, 0, DIMENSIONS, DIMENSIONS ) );
         sprite.setPosition( i * DIMENSIONS , j * DIMENSIONS);
         window.draw( sprite );

         Font font;
         font.loadFromFile( "fonts/arial.ttf" );
         std::string score = "Score: ";
         std::string scoreInString = std::to_string(CalculateScore());
         score += scoreInString;
         Text text( score, font, 30 );
         text.setPosition( window.getSize().x * 0.09, window.getSize().y - text.getGlobalBounds().height - text.getGlobalBounds().top );
         text.setFillColor( sf::Color::Red );
         window.draw( text );
      }
   }

}

int MineSweeper::CalculateScore()
{
   return openTiles * 10;
}
