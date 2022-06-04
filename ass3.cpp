#include <cassert>
#include "maze.h"
#include "creature.h"

void test1() //testing Print functions works
{
    Maze maze("maze1.txt");
    Creature cr1(4, 4);
    stringstream ss;
    ss << cr1;
    assert(ss.str() == "C(4, 4)");

    Creature dog1(2, 4);
    ss.str("");
    ss << dog1;
    assert(ss.str() == "C(2, 4)");
}

void test2() //testing creature can return X when no exit is present
{
    Maze maze2("mazeNoExit1.txt");
    Creature cr2(4, 4);
    stringstream ss;
    ss << cr2.Solve(maze2);
    assert(ss.str() == "X"); 

    //testing if Creature initial position INVALID results in X
    Maze maze3("maze2.txt");
    Creature creatureWrongPos(22, 21);
    ss.str("");
    ss << creatureWrongPos.Solve(maze3);
    assert(ss.str() == "X");
}
void test3() //testing if creature can actually find the maze Exit
{
    Maze maze4("maze2.txt");
    Creature creatureCorrect(3, 1);
    stringstream ss;
    creatureCorrect.Solve(maze4);
    ss << creatureCorrect;
    assert(ss.str() == "C(6, 2)");
    assert(maze4.IsVisited(4, 6) == true); //TESTING the IsVisited method to check if there a '+' there
}

void test4() //testing if FinalPath prints the correct NWSE directions
{
    Maze maze5("maze1.txt");
    Creature bloodHound(4, 4);
    stringstream ss;
    ss << bloodHound.Solve(maze5);
    assert(ss.str() == "NNNN");
}

void test5() //testing the creature's path and that he's leaving *'s
{
    Maze maze6("maze1.txt");
    Creature cr4(4, 4);
    cr4.Solve(maze6);
    assert(maze6.IsPath(3, 5) == true); //testing the path

    //BELOW** Testing that a wall is 'X'
    assert(maze6.IsWall(2, 2) == true); //there should be a wall here
    assert(maze6.IsWall(4, 5) == false); //there should be a * here, NOT A WALL
}
void testAll()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}
int main()
{
    testAll();
    cout << "Done; Passed All Tests!" << endl;
    return 0;
}