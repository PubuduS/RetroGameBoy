#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "GameGenerics.h"

class MineSweeper : public GameGenerics
{

public:
   MineSweeper();

private:

   //! Define the length of the window.
   //! If you want to change this you might need to change the background image too.
   //! Current length and width is match the background image.
   const int LENGTH = 400;

   //! Define the Width of the window.
   const int WIDTH = 400;

   //! Define path where image are located.
   const std::string IMAGEPATH = "images/MineSweeper_Img/";

   //! Define the dimension and spacing between each tiles.
   const int DIMENSIONS = 32;

   //! Define the rows and coloumns of the grids.
   const static int ROWCOLS = 12;

   //! Define the values of the tiles.
   int m_Grid[ROWCOLS][ROWCOLS];

   //! This Holds the UI elements.
   int m_UIgrid[ROWCOLS][ROWCOLS];

   //! Keep the count of open tiles to assign score.
   int openTiles;

   //! Load UI element.
   //! Create a window and initialize sprite.
   //! Initialize UI and data grids.
   void InitializeVars();

   //! Start the game and call other helper functions.
   void PlayMineSweeper( RenderWindow& window, Sprite& sprite );

   //! This will calculate all directions from the current position.
   void CalculateDistanceFromAllDirections();

   //! Handle Right and Left Clicks.
   //! Left Click will open titles.
   //! Right Click will mark the title with flag.
   void MouseEventListener( RenderWindow& window, const int x, const int y );

   //! Draw the UI Element.
   //! Mark the tiles with appopriate sprites.
   void DrawOnUI( RenderWindow& window, Sprite& sprite, const int x, const int y );

   //! Pure virtual function inherited from GameGenerics.h
   //! Each game calculate scores differently and therefore this function need to override in each game according to the game rules.
   virtual int CalculateScore();

};

#endif
