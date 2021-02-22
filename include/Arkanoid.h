#ifndef ARKANOID_H
#define ARKANOID_H

#include "GameGenerics.h"

class Arkanoid : public GameGenerics
{

   public:
   //!
   //! Default Constructor.
   //! Calls the InitializeVars() function.
   //!
   Arkanoid();
   
   //!
   //! Create Sprites.
   //! Load the Images and set the Sprites.
   //! Creates a block of titles with 100 tiles.
   //! Call PlayArkanoid() function to start the game. 
   //! 
   void InitializeVars();

   
   private:
   
   //! Define the length of the window. 
   //! If you want to change this you might need to change the background image too.
   //! Current length and width is match the background image.
   const int LENGTH = 520;
   
   //! Define the Width of the window. 
   const int WIDTH = 450;
   
   //! Define path where image are located. 
   const std::string IMAGEPATH = "images/Arkanoid_Img/";
   
   //! The number of tiles in the block. Currently, it has 100 tiles.
   int n;
   
   //! Remaining titls.
   int blocksRemain;
   
   //! Player has 3 hearts and once it ran out game will be over.
   //! Remaining lives are multiple of 2. For example, 3 hearts means ( 3 x 2) remainning lives.
   //! Remaining lives get calculated in SetBoundaries() function and it get called two times for each calculation.
   //! This is why remaining live is a multiple of 2.
   int remainingLives;
   
   //! Set true when user lost all the chances. 
   //! This indicate time to display game over screen.
   bool isGameOver;
   
   //! Start the game and call other helper functions. 
   void PlayArkanoid( RenderWindow& window, Sprite& s_Background, Sprite& s_Ball, Sprite& s_Paddle, Sprite& s_GameOver, Sprite* block, Sprite* lives, Texture& texture1 );
   
   //! This will check collisions with the tiles and the ball.
   //! Everytime the ball hit a tile, this record a collision and hide the tile by throwing it far away from the x axis.
   //! The collisions are recorded both x and y axises. 
   void CheckCollisions( float& xAxis, float& xPos, float& yAxis, float& yPos, Sprite* block, const bool isVertical );
   
   //! Set the boundaries so ball will remian inside the window. 
   //! Also, whenever the ball hits outside the paddel ( yAxis == width ), it will penalized the user by reducing one heart.
   //! Call the SetLives() function to remove one heartl.
   void SetBoundaries( float& xAxis, float& xPos, float& yAxis, float& yPos, Sprite* lives );
   
   //! Set the paddle to move right and left by pressing right and left arrow keys.
   void SetControls( Sprite& s_Paddle );
   
   //! Remove a heart whenever user miss the ball and it hit outside the paddle.
   void SetLives( Sprite* lives );
   
   //! Pure virtual function inherited from GameGenerics.h
   //! Each game calculate scores differently and therefore this function need to override in each game according to the game rules.
   virtual int CalculateScore();
   
   //! Pure virtual function inherited from GameGenerics.h
   //! Each game might have different game over screen.
   //! Therefore this function need to override in each game according to the game rules.
   virtual void GameOverScreen( RenderWindow& window, const Sprite& s_GameOver );

};

#endif
