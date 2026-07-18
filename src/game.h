#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <vector>

class Game{
    public:
        Game();
        Grid grid;
        Block GetRandomBlock();
        void Draw();
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        void MoveBlockUp();
        std::vector<Block> GetAllBlocks();
        
        private:
        bool isBlockOutside();
        bool BlockFits();
        void RotateBlock();
        void LockBlock();
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        
};