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

    cout << "       ***************************************************            " << endl;    
    cout << "       *               ANIMAL GUESSING GAME              *            " << endl;
    cout << "       ***************************************************            " << endl;    
    cout << endl;
    
    newTree.gameInstructions();
    cout << endl;

    cout << "---------NEW GAME OR LOAD GAME---------" << endl;
    cout << "1. Start a new game" << endl;
    cout << "2. Load the prior session (an existing file must be present)" << endl;
    cout << "1 or 2: ";
    cin >> userAnswer;

    // check if valid input
    while(userAnswer != 1 && userAnswer != 2) {
        cout << "Invalid input. Please enter 1 or 2: ";
        cin >> userAnswer;
        // clear the input buffer
        cin.clear();
        // ignore the rest of the input until the new line character
        cin.ignore(10000, '\n');
    }
    
    // If user wants to start a new game
    if(userAnswer == 1) {
        inFile.open(fileName);
    
        //If program can't open the file
        if(!inFile.is_open()) {
            cout << fileName << " could not be opened. Exiting...." << endl;
            return 0;
        }
        else{
            cout << "File opened successfully. Game is loaded!" << endl;   
        }
    }
    // load the previous game from the file
    else if (userAnswer == 2) 
    {
        cout << "What is the name of the file you would like to load for your saved game?" << endl;
        cout << "Loading the previous game..." << endl;
        cin >> fileName;
        cin.ignore();

        inFile.open(fileName);

        //If program can't open the file
        if(!inFile.is_open()) {
            cout << fileName << " could not be opened. Exiting...." << endl;
            return 0;
        }
        else{
            cout << "File opened successfully. Game is loaded!" << endl;  
            cout << "Press enter to continue!" << endl; 
        }
    }
    
    // after the file is opened, read the file into the tree
    newTree.readTextFile(nodePtr, inFile);
    inFile.close();
    cin.ignore(10000, '\n');



    

}