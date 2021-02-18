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
   GameGenerics();    
   virtual int CalculateScore() = 0; 
   virtual void GameOverScreen( RenderWindow& window, const Sprite& s_GameOver ) = 0;
  
};

#endif
