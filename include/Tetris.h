#ifndef TETRIS_H
#define TETRIS_H
#include "GameGenerics.h"

class Tetris : public GameGenerics
{

   private:

   //! Define width of a rectangle
   static const int M = 20;

   //! Define length of a rectangle.
   static const int N = 10;

   //! Define a 10 x 20 rectangle.
   //! This is use as the background for the game.
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

   //! Define 7 x 4 rectangle[ 7 rows, 4 coloumns]
   //! This defines the shapes.
   //! For example, these are the following shapes.
   //! 1,3,5,7,  -> denotes I
   //! 2,4,5,7,  -> denotes Z
   //! 3,5,4,6,  -> denotes S
   //! 3,5,4,7,  -> denotes T
   //! 2,3,5,7,  -> denotes L
   //! 3,5,7,6,  -> denotes J
   //! 2,3,4,5,  -> denotes O
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

   //! Denotes x and y points.
   struct Point
   {
      int x, y;
   };

   //! Use to move shapes
   Point a[4];

   //! Keep a backup.
   Point b[4];

   //!
   //! Check the boundaries.
   //!
   bool Check();

   //! Move shapes horizontally.
   void MoveTile( const int position = 0 );

   //! Allow user to rotate shapes.
   void RotateTile( const bool rotate = false );

   //! Move shapes down for each tick.
   float MoveDownTilePerClick( float timer, const float delay,  int& colorNum );

   //! Reduce line upon completion.
   void CheckLines();

   //! Draw UI and shapes.
   void Draw( Sprite& sprite, Sprite& background, Sprite& frame, RenderWindow& window, const int& colorNum );

   // Event Handler.
   void EventHandler( bool& rotate, int& dx, RenderWindow& window );

   //! Pure virtual function inherited from GameGenerics.h
   //! Each game calculate scores differently and therefore this function need to override in each game according to the game rules.
   virtual int CalculateScore();

   public:
   //! Default constructor.
   //! Used to intialize arrays.
   Tetris();

   //! Play Tetris Game.
   void PlayTetris();


};

#endif
