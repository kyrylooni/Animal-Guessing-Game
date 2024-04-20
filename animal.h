#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class BinaryTreeNode
{
    public:
    struct TreeNode // struct of the node for the binary tree
    {
        std::string guessedAnimalorQuestion; // string for the animal or question
        TreeNode* left; // left node -> yes
        TreeNode* right; // right node -> no
    };

    typedef TreeNode* NodePtr; // typedef for the node pointer (allias for the node pointer)

    std::string input;
    std::string answer;
    std::string question;
    int decideAnimal;
    int usersChoice;


    bool guessAnimal(NodePtr nodePtr); // function to guess the animal
    bool makeNewQuestion(NodePtr& nodePtr); // function to make a new question
    bool newRound();
    void readTextFile(NodePtr& nodePtr, std::ifstream& inFile); // function to read the text file
    int  userAnswer();
    void userChoice(NodePtr& nodePtr, NodePtr& currentPtr); 
    void gameInstructions(); // function to display the game instructions
    void writeTextFile(NodePtr nodePtr, std::ofstream& outFile); // function to write the text file
};

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
void BinaryTreeNode::userChoice(TreeNode&)












#endif 