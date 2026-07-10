#pragma once
#include <vector>
#include <raylib.h>

class Grid{
    public:
    //how many ROWS and columns its contains
    Grid();
    void Initialize();
    void Print();    
    void Draw();
    int grid[20][10]; // un array simple con 20 filas y 10 columnas

    private:
    int numRows;
    int numColumns;
    int cellSize;
    std::vector<Color> colors;
    
};

