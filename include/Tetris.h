#ifndef TETRIS_H
#define TETRIS_H
#include "GameGenerics.h"

class Tetris : public GameGenerics
{

   private:
   
   static const int M = 20;
   static const int N = 10;
   
   int field[M][N];
   
   //    __ __
   //   | 0| 1|
   //   |__|__|
   //   | 2| 3|
   //   |__|__|
   //   | 4| 5|
   //   |__|__|
   //   | 6| 7|
   //   |__|__|
   const int figures[7][4] = 
   {
      1,3,5,7, // I
      2,4,5,7, // Z
      3,5,4,6, // S
      3,5,4,7, // T
      2,3,5,7, // L
      3,5,7,6, // J
      2,3,4,5, // O
   
   };
   
   struct Point
   {
      int x, y;
   };
   
   Point a[4];
   Point b[4];  
   
   //!
   //!... Check ...
   //!
   bool Check();
   void MoveTile( const int position = 0 );
   void RotateTile( const bool rotate = false );
   float MoveDownTilePerClick( float timer, const float delay,  int& colorNum );
   void CheckLines();
   void Draw( Sprite& sprite, Sprite& background, Sprite& frame, RenderWindow& window, const int& colorNum );
   void EventHandler( bool& rotate, int& dx, RenderWindow& window );
   virtual int CalculateScore();
   virtual void GameOverScreen( RenderWindow& window, const Sprite& s_GameOver );
   
   public:
   Tetris();   
   void PlayTetris();
  

};

#endif
