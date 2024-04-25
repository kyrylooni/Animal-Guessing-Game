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
    void makeNewQuestion(NodePtr& nodePtr); // function to make a new question
    bool newRound();
    void readTextFile(NodePtr& nodePtr, std::ifstream& inFile); // function to read the text file
    int  userAnswer(); // function to get the user's answer "yes" or "no"
    void userChoice(NodePtr& nodePtr, NodePtr& currentPtr); /// function to navigate the tree based on the user's input
    void gameInstructions(); // function to display the game instructions
    void writeTextFile(NodePtr nodePtr, std::ofstream& outFile); // function to write the text file
};

#endif 