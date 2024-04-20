#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class BinaryTreeNode
{
    public:
    struct TreeNode // struct of the nodefor the binary tree
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
    int userAnswer;


    bool guessAnimal(NodePtr nodePtr); // function to guess the animal
    bool makeNewQuestion(NodePtr& nodePtr); // function to make a new question
    bool newRound();
    void readTextFile(NodePtr& nodePtr, std::ifstream& inFile); // function to read the text file
    int  userAnswer();
    void userChoice(NodePtr& nodePtr, std::ofstream& outFile); // function to save the game
    void gameInstructions(); // function to display the game instructions
    void writeTextFile(NodePtr& nodePtr, std::ofstream& outFile); // function to write the text file


    void BinaryTreeNode::gameInstructions() {
        std::cout << "Welcome to the animal guessing game!" << std::endl;
        std::cout << "Choose whether you want to start a new game or load the prior session" << std::endl;
        std::cout << "Think of an animal and I will try to guess it." << std::endl;
        std::cout << "If I can't guess it, you can teach me the animal and I will remember it for next time." << std::endl;
        std::cout << "Please answer the questions with 'yes' or 'no'." << std::endl;
        std::cout << "At the end of the game, you can choose to save the game." << std::endl;
        std::cout << "Let's get started!" << std::endl;
    }






    
}
#endif 