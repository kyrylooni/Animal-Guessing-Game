#include "animal.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

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

// User deciedes how to navigate the tree left or right based on the user's input "yes" or "no" accordingly
void BinaryTreeNode::userChoice(NodePtr &nodePtr, NodePtr &currentPtr) {

    currentPtr = nodePtr;

    // if there is no left or right node
    if(currentPtr->left == NULL && currentPtr->right == NULL)
        return;
    
    else {
        // ask the question and get the user's input
        std::cout << currentPtr->guessedAnimalorQuestion << std::endl;
        usersChoice = userAnswer();
    
        // if the user's input is "no" / right node
        if(usersChoice == 0) {
        userChoice(nodePtr->right, currentPtr);
    }
    // if the user's input is "yes" / left node
   else {
        if (usersChoice == 1) {
            userChoice(nodePtr->left, currentPtr);
        }
        else {
            std::cout << "Invalid input. Please enter 'yes' or 'no'." << std::endl;
            userChoice(nodePtr, currentPtr);
        }
        }
    }
}

// Function guesses animal at the leaf node
bool BinaryTreeNode::guessAnimal(NodePtr nodePtr) {

    // if user is animal at this leaf node 
    cout << "Is the animal " << nodePtr->guessedAnimalorQuestion << "?" << std::endl;
    decideAnimal = userAnswer();

    //wrong guess
    if(decideAnimal == 0) {
        return false;
    }
    // correct guess
    else {
        if (decideAnimal == 1) {
            std::cout << "I guessed the animal correctly!" << std::endl;
            return true;
        }
        else {
            std::cout << "Invalid input. Please enter 'yes' or 'no'." << std::endl;
            guessAnimal(nodePtr);
            return -1;
        }
    }

}
 // Function to make a new question
void BinaryTreeNode::makeNewQuestion(NodePtr& nodePtr) {

    // get the animal from the user 
    std::cout << "What is the animal you were pretending to be?" << std::endl;
    getline(cin, answer);
    cin.clear();

    // if user input is not empty
    while(answer == "") {
        std::cout << "Invalid input. Please enter the animal you were pretending to be." << std::endl;
        getline(cin, answer);
        cin.clear();
    }
     // GET FROM A "YES" QUESTION FROM THE ANIMAL ABOVE
    std::cout << "I should've known that! Help me learn  " << answer << std::endl;
    std::cout << "Please enter a question that is true for " << answer << " and false for " << nodePtr->guessedAnimalorQuestion << std::endl;


    getline(cin, question);
    cin.clear();

    // if user input is not empty
    while(question == "") {
        std::cout << "Invalid input. Please enter a question that is true for " << answer << " and false for " << nodePtr->guessedAnimalorQuestion << std::endl;
        getline(cin, question);
        cin.clear();
    }

    TreeNode* left = new TreeNode;

    left->guessedAnimalorQuestion = answer;
    left->left = NULL;
    left->right = NULL;

    TreeNode* right = new TreeNode;
    right->guessedAnimalorQuestion = nodePtr->guessedAnimalorQuestion;
    right->left = NULL;
    right->right = NULL;

    nodePtr->guessedAnimalorQuestion = question;
    nodePtr->left = left;
    nodePtr->right = right;

}

void BinaryTreeNode::writeTextFile(NodePtr nodePtr, ofstream& outFile) {

    // ptr is null enter * when null
    if (nodePtr == NULL) {
        outFile << "*'" << endl;
    }    
    else {
        outFile << nodePtr->guessedAnimalorQuestion << endl;
        writeTextFile(nodePtr->left, outFile);
        writeTextFile(nodePtr->right, outFile);
    }
        



}