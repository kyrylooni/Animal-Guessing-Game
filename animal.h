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

}


#endif