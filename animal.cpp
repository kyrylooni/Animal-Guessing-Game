#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "animal.h"

using namespace std;

void BinaryTreeNode::gameInstructions() {
  
   std::cout << "Choose whether you want to start a new game or load the prior session" << std::endl;
   std::cout << "Think of an animal and I will try to guess it." << std::endl;
   std::cout << "If I can't guess it, you can teach me the animal and I will remember it for next time." << std::endl;
   std::cout << "Please answer the questions with 'yes' or 'no'." << std::endl;
   std::cout << "At the end of the game, you can choose to save the game." << std::endl;
   std::cout << "Let's get started!" << std::endl;
}


// Function to read the tree from the text file
void BinaryTreeNode::readTextFile(NodePtr& nodePtr, std::ifstream& inFile) {

    std::string input;

    getline(inFile, input);

    // If the input is not equal to "*" and the file is not at the end

    if(input != "*" && !inFile.eof()) {
        // Create a new node and store the input in the node and read the left and right nodes        
        nodePtr = new TreeNode;
        nodePtr->guessedAnimalorQuestion = input;
        readTextFile(nodePtr->left, inFile);
        readTextFile(nodePtr->right, inFile);
    }

    else {
        nodePtr = NULL;
    }

}

void BinaryTreeNode::userChoice(NodePtr &nodePtr, NodePtr &currentPtr) {
    currentPtr = nodePtr;

    // Check for leaf node
    if (currentPtr->left == NULL && currentPtr->right == NULL) {
        return; // This is a leaf node, no further action needed
    }

    cout << currentPtr->guessedAnimalorQuestion << endl; // Ask question
    usersChoice = userAnswer(); // Get user answer

    // Navigate the tree based on user input
    if (usersChoice == 1) { // "yes" - move to left
        if (currentPtr->left != NULL) {
            userChoice(currentPtr->left, currentPtr); // Recur left
        }
    } else if (usersChoice == 0) { // "no" - move to right
        if (currentPtr->right != NULL) {
            userChoice(currentPtr->right, currentPtr); // Recur right
        }
    } else {
        cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
        userChoice(nodePtr, currentPtr); // Repeat with same node
    }
}




// Function guesses animal at the leaf node
bool BinaryTreeNode::guessAnimal(NodePtr nodePtr) {
    cout << "Are you pretending to be a(n) " << nodePtr->guessedAnimalorQuestion << "?" << endl;
    decideAnimal = userAnswer();

    if (decideAnimal == 0) {
        return false;
    } 
    else {
        if (decideAnimal == 1) {
            return true;
        }
        else {
            cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
            guessAnimal(nodePtr);
            return -1;
        }  
    }
}

 void BinaryTreeNode::makeNewQuestion(NodePtr& nodePtr) {
    cout << "What animal were you thinking of?" << endl;

    getline(cin, newAnswer);
    cin.clear();

    while (newAnswer == "")
    {
        cout << "Invalid input. Please enter the animal you were thinking of." << endl;
        getline(cin, newAnswer);
        cin.clear();
    }

    cout << "I shoul've known that. Help me learn more about a(n) " << newAnswer << endl;
    cout << "Please enter a question that is true for a(n) " << newAnswer << " and false for a(n) " << nodePtr->guessedAnimalorQuestion << endl;
    
    getline(cin, newQuestion);
    cin.clear();

    while (newQuestion == "")
    {
        cout << "Invalid input. Please enter a question that is true for a(n) " << newAnswer << " and false for a(n) " << nodePtr->guessedAnimalorQuestion << endl;
        getline(cin, newAnswer);
        cin.clear();
    }
    NodePtr left = new TreeNode;

    left->guessedAnimalorQuestion = newAnswer;
    left->left = NULL;
    left->right = NULL;

    NodePtr right = new TreeNode;

    right->guessedAnimalorQuestion = nodePtr->guessedAnimalorQuestion;
    right->left = NULL;
    right->right = NULL;

    nodePtr->guessedAnimalorQuestion = newQuestion;
    nodePtr->left = left;
    nodePtr->right = right;

    return;
    

 }



bool BinaryTreeNode::newRound() {

    cout << endl;
    cout << "Great round!" << endl; 
    cout << endl;
    cout << "Would you like to play again (yes/no)" << endl; 
    cin >> input;
    cin.ignore();


    // if user wants to play again  
    if (input == "yes") {
        return true;
    }
    // user does not want to play again 
    else if (input == "no") 
    {
        return false;
    }

    // validate
    else{
        cout << "Invalid answer. " << endl;
        newRound();
        return -1;
    }
}

void BinaryTreeNode::writeTextFile(NodePtr nodePtr, ofstream& outFile) {

    // ptr is null enter * when null
    if (nodePtr == NULL) {
        outFile << "*" << endl;
    }    
    else {
        outFile << nodePtr->guessedAnimalorQuestion << endl;
        writeTextFile(nodePtr->left, outFile);
        writeTextFile(nodePtr->right, outFile);
    }    
}
    // user answer function
    // called when we need to get yes or no from the user. Trues are equal to 1 
    // and falses are equal to 0
    // -1 is returned if the user enters an invalid input
int BinaryTreeNode::userAnswer() {
    cin >> input;
    cin.ignore();

    if (input == "yes") {
        return 1;
    } 
    else if (input == "no") {
        return 0;
    } 
    else {
        cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
        return -1;
    }

}
