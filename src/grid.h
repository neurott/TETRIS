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
    // este metdoo va a ver si la posición de la cell esta afuera del grid
    bool isCellOutside(int row, int column);
    bool isCellEmpty(int row, int column);
    int ClearFullRows();
    int grid[20][10]; // un array simple con 20 filas y 10 columnas

    private:
    bool isRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
    int numRows;
    int numColumns;
    int cellSize;
    std::vector<Color> colors;
    
};

