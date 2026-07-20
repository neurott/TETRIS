#include "game.h"
#include <random>

Game::Game(){
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    isGameOver = false;
    score = 0;
    InitAudioDevice();
    music = LoadMusicStream("Sounds/soundtrack.mp3");
    PlayMusicStream(music);
    rotateSound = LoadSound("Sounds/rotate.mp3");
    clearSound = LoadSound("Sounds/clear.mp3");

}

Game::~Game(){

    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    //acá cierro el audio device
    UnloadMusicStream(music);
    CloseAudioDevice();

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
    currentBlock.Draw(11,11);

    switch(nextBlock.id){
        case 3: //iblock
            nextBlock.Draw(255,290);
            break;
        case 4://oblock
            nextBlock.Draw(255,280);
            break;
        default:
            nextBlock.Draw(270,270);
            break;
    }
    
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
            UpdateScore(0,1);
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

//revisa esto, pq hay un bug.
void Game::RotateBlock(){ 
    if(!isGameOver){
        currentBlock.Rotate();

        if(isBlockOutside() || !BlockFits()){
            currentBlock.UndoRotation();
        }
        else{
            PlaySound(rotateSound);
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
    int rowsCleared = grid.ClearFullRows();
    if(rowsCleared > 0){
        PlaySound(clearSound);
        UpdateScore(rowsCleared, 0);

    }
    
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
    score = 0;
}

void Game::UpdateScore(int linesCleared, int movedDownPoints){

    if(linesCleared > 0){
        score += 100 + (linesCleared - 1) * 200; 
    }

    score += movedDownPoints;    

    //este swtich lo vi poco escalable, imagina elimino 4 líneas, tendría que crear otro case
    // ni q fuera undertalelw
    /*switch(linesCleared){
        case 1:
            score += 100;
            break;
        case 2:
            score += 200;
            break;
        case 3:
            score += 500;
            break;
        default:
            break;
    }*/


}