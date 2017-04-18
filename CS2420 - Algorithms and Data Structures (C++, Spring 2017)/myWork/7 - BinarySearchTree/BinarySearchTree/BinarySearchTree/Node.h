//
//  Node.cpp
//  Binary Tree C++
//
//  Created by Max on 3/9/17.
//  Copyright © 2017 Max Nelson. All rights reserved.
//

#include <stdio.h>

struct Node
{
    int data;
    Node* left;
    Node* right;
    
    //Postcondition: Node data is initialized
    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
