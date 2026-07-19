#include <raylib.h>
#include "game.h"
#include "colors.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval){

    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval){
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() {
    //game window
    InitWindow(500,620,"Tetris"); 
    SetTargetFPS(60);

    Game game = Game();
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    while (!WindowShouldClose()) {
        
        game.HandleInput();
        
        if(EventTriggered(0.2)){
            game.MoveBlockDown();
        }
        BeginDrawing(); // begin de canvas drawing
            ClearBackground(darkBlue);
            DrawTextEx(font,"Score", {365,15},38,2, WHITE);
            DrawTextEx(font,"Next", {370,175},38,2, WHITE);
            if(game.isGameOver){

                DrawTextEx(font,"GAME OVER", {320,450},38,2, WHITE);
            }
            DrawRectangleRounded({320,55,170,60}, 0.3, 6, lightBlue);
            DrawRectangleRounded({320,215,170,180}, 0.3, 6, lightBlue);
            game.Draw();


        EndDrawing();
    
    }
    
    CloseWindow();


    
}