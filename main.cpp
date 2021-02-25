#include "include/Tetris.h"
#include "include/Arkanoid.h"
#include "include/Snake.h"

namespace choices
{

 enum GAME { UNKNOWN, TETRIS, ARKANOID, SNAKE };

}


void DisplayMenu();

int main()
{

    DisplayMenu();

    int choice = 0;
    std::cin>>choice;

    const choices::GAME selected = static_cast<choices::GAME>(choice);

    switch( selected )
    {
        case choices::TETRIS:
        {
            Tetris myTetris;
            myTetris.PlayTetris();
            break;
        }
        case choices::ARKANOID:
        {
            Arkanoid myArkanoid;
            break;
        }
        case choices::SNAKE:
        {
            Snake mySnake;
            break;
        }
        default:
        {
            std::cout<<" Invalid choice "<<std::endl;
            break;
        }
    }

    return 0;
}

void DisplayMenu()
{
    std::cout<<"Please Select a Game"<<std::endl;
    std::cout<<"Press 1 to Play Tetris."<<std::endl;
    std::cout<<"Press 2 to Play Arkanoid."<<std::endl;
    std::cout<<"Press 3 to Play Snake."<<std::endl;
}
