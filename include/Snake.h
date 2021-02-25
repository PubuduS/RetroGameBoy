#ifndef SNAKE_H
#define SNAKE_H

#include "GameGenerics.h"

class Snake : public GameGenerics
{

    private:

    //! Define length with 30 squares
    const int N = 30;

    //! Define height with 30 squares
    const int M = 20;

    //! Define space between each square
    const int SIZE = 16;

    //! Define width of the window.
    const int WIDTH = SIZE * N;

    //! Define height of the window.
    const int HEIGHT = SIZE * M;

    //! Direction of the snake.
    int m_direction;

    //! Length of the snake.
    int m_SnakeLength;

    //! Track game score.
    int m_Score;

    //! Track when game is over or not.
    bool m_IsGameOver;

    //! Structure to holds x and y cordinates of the snake when it
    //! move across the grid.
    struct SnakeStrct
    {
        int x;
        int y;
    };

    //! Structure to holds x and y cordinates of the fruit.
    struct Fruit
    {
        int x;
        int y;
    };

    //! Holds x and y cordinates of the snake when it
    //! move across the grid.
    Fruit m_MyFruit;

    //! Holds x and y cordinates of the fruit.
    SnakeStrct m_MySnake[100];

    //!
    //! Create Sprites.
    //! Load the Images and set the Sprites.
    //! Call PlaySnake() function to start the game.
    //!
    void InitializeVars();

    //! Move Snake across the grid per Tick.
    void MoveSnake();

    //! Set the direction to move the snake.
    //! 0 indicates down.
    //! 3 indicates up.
    //! 1 indicates left.
    //! 2 indicate right.
    void MoveToThisDirection();

    //! If snake cross the boundary of the window
    //! make it reappear on the opposite side of the window.
    void BoundaryControl();

    //! Whenever snake eats a fruit make it grow by 1 square.
    void GrowUponEat();

    //! Allow user to control snake by using arrow keys.
    void KeyControls();

    //! Draw sprites on the window.
    void DrawSprites( RenderWindow& window, Sprite& sprite1, Sprite& sprite2 );

    //! Whenever snake tries to eat itself game is over.
    void GameOverLogic();

    //! Start the game.
    void PlaySnake( RenderWindow& window, Sprite& sprite1, Sprite& sprite2 );


    public:

    //! Default Constructor.
    //! initialize variables.
    Snake();

    //! Pure virtual function inherited from GameGenerics.h
    //! Each game calculate scores differently and therefore this function need to override in each game according to the game rules.
    virtual int CalculateScore();


};
#endif // SNAKE_H
