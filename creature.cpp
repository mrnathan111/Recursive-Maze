#include "creature.h"

Creature::Creature(int row, int col)
{
    curCol = col + 1; //-1 to convert to 1st row = 1 and not 1st row = 0th row. 
    curRow = row + 1;
}
ostream &operator<<(ostream &out, const Creature &creature)
{
    out << "C(" << creature.curRow - 1 << ", " << creature.curCol - 1 << ")"; //-1 to convert from 1st row = row[1] to 1st row = row[0], same for Col
    return out;
}

string Creature::Solve(Maze &maze)
{
    if (counter == 0 && maze.isClearInMaze(curRow, curCol) == true) //if 1st Solve() call && creature is IN maze empty space
        {
            maze.MarkAsPath(curRow, curCol);
            counter++;
        }
    if (((0 < curRow) && (curRow < maze.getHeight())) == false || ((0 < curCol) && (curCol < maze.getWidth())) == false) //if NOT IN MAZE
    {
        return "X"; 
    }
    if (goNorth(maze) == true || goEast(maze) == true || goSouth(maze) == true || goWest(maze) == true) //if Craeture found Exit
    {
        maze.MarkAsPath(curRow, curCol);
        return FinalPath;
    }
    else //couldn't find the exit
    {
        return "X";
    }
    return "X";
}

bool Creature::goNorth(Maze &maze)
{
    curRow -= 1; //move North
    if (maze.IsWall(curRow, curCol) == true) //IF you are in a wall, reset and bounce back
    {
        curRow += 1;
        return false;
    }
    if (curRow == maze.getRowExit() && curCol == maze.getColumnExit()) //if new position is EXIT
    {
        FinalPath += 'N'; //add direction to FinalPath and return true
        return true;
    }
    else if (maze.IsClear(curRow, curCol) == false) //If it's a +, reset and bounce back
    {
        curRow += 1;
        return false;
    }
    else //If new position is NOT exit, IS clear
    {
        maze.MarkAsPath(curRow, curCol);
        FinalPath += 'N';
        if (Solve(maze) == FinalPath)
        {
            return true;
        }
        else
        {
            maze.MarkAsVisited(curRow, curCol); //Place a +
            curRow += 1; //reset
            FinalPath.pop_back(); //Remove the direction added
            return false; //bounce back
        }
    }
    return false;
}

bool Creature::goEast(Maze &maze)
{
    curCol += 1; //move East
    if (maze.IsWall(curRow, curCol) == true)
    {
        curCol -= 1;
        return false;
    }
    if (curRow == maze.getRowExit() && curCol == maze.getColumnExit()) //if new position is EXIT
    {
        FinalPath += 'E';
        return true;
    }
    else if (maze.IsClear(curRow, curCol) == false)
    {
        curCol -= 1;
        return false;
    }
    else
    {
        maze.MarkAsPath(curRow, curCol);
        FinalPath += 'E';
        if (Solve(maze) == FinalPath)
        {
            return true;
        }
        else
        {
            maze.MarkAsVisited(curRow, curCol);
            curCol -= 1; //reset
            FinalPath.pop_back();
            return false;
        }
    }
    return false;
}

bool Creature::goSouth(Maze &maze)
{
    curRow += 1; //move South
    if (maze.IsWall(curRow, curCol) == true)
    {
        curRow -= 1;
        return false;
    }
    if (curRow == maze.getRowExit() && curCol == maze.getColumnExit()) //if new position is EXIT
    {
        FinalPath += 'S';
        return true;
    }
    else if (maze.IsClear(curRow, curCol) == false)
    {
        curRow -= 1;
        return false;
    }
    else
    {
        maze.MarkAsPath(curRow, curCol);
        FinalPath += 'S';
        if (Solve(maze) == FinalPath)
        {
            return true;
        }
        else
        {
            maze.MarkAsVisited(curRow, curCol);
            curRow -= 1; //reset
            FinalPath.pop_back();
            return false;
        }
    }
    return false;
}
bool Creature::goWest(Maze &maze)
{
    curCol -= 1; //move West
    if (maze.IsWall(curRow, curCol) == true)
    {
        curCol += 1;
        return false;
    }
    if (curRow == maze.getRowExit() && curCol == maze.getColumnExit()) //if new position is EXIT
    {
        FinalPath += 'W';
        return true;
    }
    else if (maze.IsClear(curRow, curCol) == false)
    {
        curCol += 1;
        return false;
    }
    else //If NOT EXIT, and IS CLEAR
    {
        maze.MarkAsPath(curRow, curCol);
        FinalPath += 'W';
        if (Solve(maze) == FinalPath)
        {
            return true;
        }
        else
        {
            maze.MarkAsVisited(curRow, curCol);
            curCol += 1; //reset
            return false;
        }
    }
    return false;
}

int Creature::getXEnt()
{
    return curCol;
}

int Creature::getYEnt()
{
    return curRow;
}