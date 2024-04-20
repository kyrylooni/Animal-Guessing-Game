#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "animal.h"

using namespace std;

int main() {
    BinaryTreeNode::NodePtr nodePtr;
    BinaryTreeNode::NodePtr currentPtr;
    BinaryTreeNode newTree;

    // If user wants to play again after the user has guessed the animal
    bool playAgain = true;
    ifstream inFile; // loading the game file to read the animals and questions
    int userAnswer; // user decides to start a new game or load the game
    ofstream outFile; // saving the game file
    string continueGame; // user decides to continue the game or not
    string fileName = "animalGame.txt"; // file name for the game file
    




}