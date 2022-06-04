#include "maze.h"

Maze::Maze(string fileName)
{
    ifstream inFile(fileName);
    if (inFile.is_open())
    {
        setSize(inFile);
        setExit(inFile);
        mazeArray = new char[mazeWidth * mazeHeight];
        fillMazeArray(inFile);
    }
    else
    {
        cout << "File unable to open" << endl;
        exit(0);
    }
    inFile.close();
}
Maze::~Maze()
{
    delete[] mazeArray;
    mazeArray = NULL;
}

void Maze::fillMazeArray(ifstream& inFile)
{
    int counter = 0;
    string line;
    getline(inFile, line);
    for (int i = 0; i < mazeHeight; i++)
    {
        getline(inFile, line);
        for (int j = 0; j < mazeWidth; j++)
        {
            mazeArray[counter] = line[j];
            counter++;
        }
    }
}
ostream &operator << (ostream &out, const Maze &maze)
{
    int counter = 0;
    for (int i = 0; i < maze.mazeHeight; i++)
    {
        for (int j = 0; j < maze.mazeWidth; j++)
        {
            out << maze.mazeArray[counter];
            counter++;
        }
        out << endl;
    }
    return out;
}
void Maze::setSize(ifstream& inFile)
{
        inFile >> mazeWidth >> mazeHeight;
}
void Maze::setExit(ifstream& inFile)
{
        inFile >> rowExit >> columnExit;
        rowExit += 1; //+1 to Row and Col to convert to my program that doesn't have 0th row, but it starts a row = 1. I revert to 0th row when I print Creature location
        columnExit += 1;
}
int Maze::getIndex(int row, int col) const
{
    if (row == 1) //if 1st row of maze, the 0 through 3 elements will be the same as the long 1d array
        return col - 1;
    return mazeWidth * (row - 1) + (col - 1);
}
int Maze::getWidth() const
{
    return mazeWidth;
}
int Maze::getHeight() const
{
    return mazeHeight;
}
void Maze::MarkAsVisited(int row, int column)
{
    mazeArray[getIndex(row, column)] = '+';
}
void Maze::MarkAsPath(int row, int column)
{
    mazeArray[getIndex(row, column)] = '*';
}
bool Maze::IsVisited(int row, int column) const
{
    if (mazeArray[getIndex(row, column)] == '+')
        return true;
    else
        return false;
}
bool Maze::IsPath(int row, int column) const
{
    if (mazeArray[getIndex(row, column)] == '*')
        return true;
    else
        return false;
}
bool Maze::IsWall(int row, int column) const
{
    if (mazeArray[getIndex(row, column)] == 'x')
        return true;
    else
        return false;
}
bool Maze::IsClear(int row, int column) const
{
    if (mazeArray[getIndex(row, column)] == ' ')
        return true;
    else
        return false;
}
bool Maze::isClearInMaze(int row, int column) const //for the 1st initial Creature position only. Not recursive calls
{
    if (IsClear(row, column) == true && ((0 < row) && (row < getHeight())) && ((0 < column) && (column < getWidth()))) //If position is inside maze and clear
        return true;
    return false;
}
int Maze::getRowExit() const
{
    return rowExit;
}
int Maze::getColumnExit() const
{
    return columnExit;
}