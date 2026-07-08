#include <raylib.h>

int main() 
{

    //game window
    InitWindow(300,600,"Tetris");
    SetTargetFPS(60);


    Color darkBlue = {44,44,127,255};
    
    while (WindowShouldClose() == false)
    {
        BeginDrawing(); // begin de canvas drawiing
        ClearBackground(darkBlue);
        EndDrawing();
    
    }
    




    CloseWindow();


    
}