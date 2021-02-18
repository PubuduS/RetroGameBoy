#ifndef ARKANOID_H
#define ARKANOID_H

#include "GameGenerics.h"

class Arkanoid : public GameGenerics
{

   public:
   Arkanoid();   
   void InitializeVars();

   
   private:
   const int LENGTH = 520;
   const int WIDTH = 450;
   const std::string IMAGEPATH = "images/Arkanoid_Img/";
   int n;
   int blocksRemain;
   int remainingLives;
   bool isGameOver;
   
   void PlayArkanoid( RenderWindow& window, Sprite& s_Background, Sprite& s_Ball, Sprite& s_Paddle, Sprite& s_GameOver, Sprite* block, Sprite* lives, Texture& texture1 );
   void CheckCollisions( float& xAxis, float& xPos, float& yAxis, float& yPos, Sprite* block, const bool isVertical );
   void SetBoundaries( float& xAxis, float& xPos, float& yAxis, float& yPos, Sprite* lives );
   void SetControls( Sprite& s_Paddle );
   void SetLives( Sprite* lives );
   virtual int CalculateScore();
   virtual void GameOverScreen( RenderWindow& window, const Sprite& s_GameOver );

};

#endif
