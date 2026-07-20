#include "colors.h"
#include <vector>

const Color darkGrey = {20, 20, 25, 255};
const Color green  = {46, 204, 113, 255};
const Color red    = {231, 76, 60, 255};
const Color orange = {230, 126, 34, 255};
const Color yellow = {241, 196, 15, 255};
const Color purple = {155, 89, 182, 255};
const Color cyan   = {26, 188, 156, 255};
const Color blue   = {52, 152, 219, 255};
const Color lightBlue = {59, 85, 162, 255};
const Color darkBlue = {44, 44, 127, 255};

std::vector<Color> GetCellColors(){
    
    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};

}