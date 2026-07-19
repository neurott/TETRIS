#include "game.h"
#include <random>

Game::Game(){
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    isGameOver = false;

}

Block Game::GetRandomBlock(){

    if(blocks.empty()){
                blocks = GetAllBlocks();
    }

    int randomIndex = rand() % blocks.size();

    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);

    return block;

}


std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw(){
    grid.Draw();
    currentBlock.Draw();
    
}

void Game::HandleInput(){
    
    int keyPressed = GetKeyPressed();
    if(isGameOver && keyPressed != 0){
        
        isGameOver = false;
        Reset();
    }
    
    switch(keyPressed){
        case KEY_LEFT:
        MoveBlockLeft();
        break;
        case KEY_RIGHT:
        MoveBlockRight();
        break;
        case KEY_DOWN:
        MoveBlockDown();
        break;
        case KEY_UP:
        RotateBlock();
        break;

    }
    
}

void Game::MoveBlockLeft(){

    if(!isGameOver){
        currentBlock.Move(0,-1);
        
        if(isBlockOutside() || !BlockFits()){
            currentBlock.Move(0,1);
        }
    }
    
}

void Game::MoveBlockRight(){

    if(!isGameOver){
        currentBlock.Move(0, 1);
        
        if(isBlockOutside() || !BlockFits()){
            currentBlock.Move(0,-1);
        }
    }
    
}
void Game::MoveBlockDown(){

    if(!isGameOver){

        currentBlock.Move(1, 0);
        
        if(isBlockOutside() || !BlockFits()){
            currentBlock.Move(-1,0);
            LockBlock();
        }
    }
    
    
    
}

void Game::RotateBlock(){ 
    if(!isGameOver){
        currentBlock.Rotate();

        if(isBlockOutside() || !BlockFits()){
            currentBlock.UndoRotation();
        }
    }
}

bool Game::isBlockOutside(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    
    for(Position item : tiles){
        if(grid.isCellOutside(item.row, item.column)){
            return true;
        }
        
    }
    return false;
}


void Game::LockBlock(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item : tiles){
        grid.grid[item.row][item.column] = currentBlock.id;
        
    }
    currentBlock = nextBlock;
    //si no encaja el bloque de ninguna manera gameove
    //despues el gameover va en todos los métodos q permiten q se mueva el bloque
    if(!BlockFits()){
        isGameOver = true;
    }
    
    nextBlock = GetRandomBlock();
    
    grid.ClearFullRows();
    
}

bool Game::BlockFits(){
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles){
        if(!grid.isCellEmpty(item.row, item.column)){
            return false;
            
        }
    }
    return true;
        
}

void Game::Reset(){
    grid.Initialize();

    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}
