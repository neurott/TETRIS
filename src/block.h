#pragma once

#include <vector>
#include <map>
#include "position.h"
#include "colors.h"


//tetromino
/*Clase para representar una pieza de tetris:
   I,J,L,O,S,T,Z */
class Block{
    public:
        Block();
        void Draw(int offsetX, int offsetY);
        //Desde donde empieza a dibujar la ventana
        void Move(int rows, int columns);
        /*Mueve el bloque_
        recibe cuántas filas y cuántas columnas sumarle a SU posición actual
        (puede ser negativo, para mover de arriba/izquierda)*/
        std::vector<Position> GetCellPositions();
        /*Retorna una lista de Position -> 4 celdas q usa el bloque en ese momento,
        cuando ya se le aplicó la rotación y la posición ACTUAL (no las q estan guardadas en cells)*/
        void Rotate();
        //Avanza al estado de rotación
        void UndoRotation();
        //DESHACE EL ESTADO DE ROTACIÓN, RETROCE EL ESTADO ROTACIÓN
        int id;
        //q tipo de pieza es (1-7)
        std::map<int, std::vector<Position>> cells; 
        //recibe el estado de rotación  y una lista de posiciones.
    private:
        int cellSize;
        //pixeles de cada celda
        int rotationState;
        //ESTADO DE ROTACIÓN ACTUAL (0 A 3)
        std::vector<Color> colors;
        //lista de colores
        int rowOffset;
        //cuanto se ha movido el bloque en filas desdes su poición origianl (move() le va sumando)
        int columnOffset;
};