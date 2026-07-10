#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"

int main() 
{
    //game window
    InitWindow(300,600,"Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    //grid.Print();
    LBlock block = LBlock();

    Color darkBlue = {44,44,127,255};
    
    while (WindowShouldClose() == false)
    {
        BeginDrawing(); // begin de canvas drawiing
        ClearBackground(darkBlue);
        grid.Draw();
        block.Draw();
        EndDrawing();
    
    }
    
    CloseWindow();


    
}