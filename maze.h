//Nathan Koplitz
//HW3
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;

class Maze
{
private:
    char* mazeArray; //make a 1d array that represents a 2d
    int mazeWidth;
    int mazeHeight;
    int columnExit;
    int rowExit;
public:
    explicit Maze(string fileName);
    ~Maze();
    friend ostream &operator<<(ostream &out, const Maze &maze);
    bool IsClear(int row, int column) const; //Returns T/F if there is a SPACE " " in current position
    bool IsWall(int row, int column) const; //Returns T/F if X (wall) is in current position
    bool IsPath(int row, int column) const; //Returns T/F if * is in current position
    bool IsVisited(int row, int column) const; //Returns T/F if + is in current position
    bool isClearInMaze(int row, int column) const; //returns T/F if current Position is inside maze AND Clear. Only on 1st solve call

    void MarkAsPath(int row, int column); //marks the current location with *  (correct path to finish)
    void MarkAsVisited(int row, int column); //marks the current location with + (incorrect path to finish)
    void setSize(ifstream &inFile); //Sets the maze Width and height
    void setExit(ifstream &inFile); //Sets the exit column and row coordinate
    void fillMazeArray(ifstream &inFile); //Fills the array with X's (walls) representing the maze

    int getWidth() const; //returns maze width
    int getHeight() const; //returns maze height
    int getRowExit() const;//returns Y coordinate of exit
    int getColumnExit() const;//returns X Coordinate of exit
    int getIndex(int row, int col) const; //converts (row, col) to index in 1d array that is implemented to represent the maze
};