#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <vector>

class Game{
    public:
        Game();
        ~Game(); 
        void Draw();
        void HandleInput();
        void MoveBlockDown();
        //void MoveBlockUp();
        bool isGameOver;
        Music music;    
        //Music soundtrack;
        int score;
        

    private:
        void MoveBlockLeft();
        void MoveBlockRight();
        std::vector<Block> GetAllBlocks();
        Grid grid;
        Block GetRandomBlock();
        bool isBlockOutside();
        bool BlockFits();
        void RotateBlock();
        void HardDrop();
        void LockBlock();
        void Reset();
        void UpdateScore(int linesCleared, int movedDownPoints);
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        Sound rotateSound; 
        Sound clearSound;
        Sound hardDropSound;
        Sound moveSound;
        Sound gameOverSound;

        
};