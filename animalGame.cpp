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
    string newGameFile = "ORIGINAL_FILE.txt"; // original file for the game
    string fileName; // file name for the game file

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
        inFile.open(newGameFile);
    
        //If program can't open the file
        if(!inFile.is_open()) {
            cout << newGameFile << " could not be opened. Exiting...." << endl;
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
        cin >> continueGame;
        cin.ignore();

        inFile.open(continueGame);

        //If program can't open the file
        if(!inFile.is_open()) {
            cout << continueGame << " could not be opened. Exiting...." << endl;
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

    // play game as long as the user wants to continue. After each round, 
    // either win or lose, the user is asked if they want to continue

do {
    // if the user wants to play the game
    cout << "NEW ROUND!" << endl;
    cout << "LET'S PLAY THE GAME!" << endl;
    cout << "**********************" << endl;

    // start the game
    newTree.userChoice(nodePtr, currentPtr);

    if (newTree.guessAnimal(currentPtr)== true) {
        cout << "I guessed the animal!" << endl;
        cout << "I win!" << endl;
    }
    else {
        cout << "I couldn't guess the animal!" << endl;
        cout << "You win!" << endl;
        newTree.makeNewQuestion(currentPtr);
    }

    // ask the user if they want to play again
    playAgain = newTree.newRound();

    } while(playAgain == true);

    // if the user wants to save the game
    cout << "I would like to save the game this game for future." << endl; 
    cout << "What would you like to name the file?" << endl;
    cout << "Please enter the file name followed by a '.txt': " << endl;
    cin >> fileName;

    // empty value for the file name
    while(fileName == "") {
        cout << "Invalid input. Please enter the file name followed by a '.txt': " << endl;
        cin >> fileName;
    }

    // open the file to write the game
    outFile.open(fileName);
    newTree.writeTextFile(nodePtr, outFile);
    outFile.close();
    

    cout << "Thank you for playing the game!" << endl;
    cout << "Please come back and play again!" << endl;

    return 0;
}
    

    

