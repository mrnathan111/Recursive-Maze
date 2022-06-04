//Nathan Koplitz
//HW3
#pragma once
#include "maze.h"

class Creature
{
private:
    int counter = 0; //Checks if this is the first Solve() called. If so, place a * and check if valid
    string FinalPath;//NWSE string to return from solve()
    int curCol; //which column (X-Axis)
    int curRow; //which row (Y-Axis)
public:
    Creature(int row, int col);
    int getXEnt();
    int getYEnt();
    string Solve(Maze &maze); //returns NEEWSN  directions to solve maze
    bool move(const int direction, Maze &maze);
    bool goNorth(Maze &maze);
    bool goEast(Maze &maze);
    bool goSouth(Maze &maze);
    bool goWest(Maze &maze);
    friend ostream &operator<<(ostream &out, const Creature &creature); //prints out creature location ex) C(7,3)
};