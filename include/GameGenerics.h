#ifndef GAMEGENERICS_H
#define GAMEGENERICS_H

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

using namespace sf;

class GameGenerics
{

   private:
   
   protected:   
   
   public:
   
   //! Default Constructor for GameGenerics.
   //! This is a abstract class and you cannot instantiate this class.
   GameGenerics();
   
   //! Pure virtual function inherited from GameGenerics.h
   //! Each game calculate scores differently and therefore this function need to override in each game according to the game rules. 
   virtual int CalculateScore() = 0;
   
   //! Pure virtual function inherited from GameGenerics.h
   //! Each game might have different game over screen.
   //! Therefore this function need to override in each game according to the game rules.
   virtual void GameOverScreen( RenderWindow& window, const Sprite& s_GameOver ) = 0;
  
};

#endif
