#include <raylib.h>
#include "game.h"

int main() {
    //game window
    Color darkBlue = {44,44,127,255};
    InitWindow(300,600,"Tetris");
    SetTargetFPS(60);

    Game game = Game();
 
    
    while (WindowShouldClose() == false) {
        
        game.HandleInput();
        BeginDrawing(); // begin de canvas drawiing
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    
    }
    
    CloseWindow();


    
}