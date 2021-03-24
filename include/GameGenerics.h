#ifndef GAMEGENERICS_H
#define GAMEGENERICS_H

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

using namespace sf;

namespace choices
{

 enum GAME { UNKNOWN, TETRIS, ARKANOID, SNAKE };

}

class GameGenerics
{

   private:

   protected:

   //! Display a game over screen at the end of the game alone with user's score.
   //! Currently, every game has the same game over screen.
   //! If each and every game needs a different screen, it might be a good idea to
   //! make it a pure virtual function.
   void GameOverScreen( RenderWindow& window );

   public:

   //! Default Constructor for GameGenerics.
   //! This is a abstract class and you cannot instantiate this class.
   GameGenerics();

   //! Pure virtual function inherited from GameGenerics.h
   //! Each game calculate scores differently and therefore this function need to override in each game according to the game rules.
   virtual int CalculateScore() = 0;


};

#endif
