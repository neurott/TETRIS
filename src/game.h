#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <vector>

class Game{
    public:
        Game();
        Grid grid;
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();

    private:
        std::vector<Block> blocks;
};