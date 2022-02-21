//
//  ShapeList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the ShapeList class below
#include "ShapeList.h"

    ShapeList::ShapeList()                        // sets head to nullptr
    {
        head = nullptr;
    }
    
    
//    ShapeList::~ShapeList()                       // deletes all list nodes starting
//                                        // with head plus associated Shapes
//    {
//        // Set next of the last shapeNode of the shapeList of 1st GroupNode EQUAL to the head of the shapeList of the GroupNode we want to delete.
//        
//    }
    
    
    ShapeNode* ShapeList::getHead() const         // returns the head pointer
    {
        return head;
    }
    
    
    void ShapeList::setHead(ShapeNode* ptr)       // sets the head pointer to ptr
    {
        head = ptr;
    }
    
    //QUESTION: How do I know what the name of the shapeNode is?
    ShapeNode* ShapeList::find(string name) const // finds a shape node with the specified shape name
                                        // returns a pointer to the node if found, otherwise
                                        // returns nullptr if the node is not found
    {
        ShapeNode* tempShapeNode = getHead();
        while(tempShapeNode != NULL)
        {
            if(tempShapeNode->getShape()->getName() == name)
            {
                break;
            }
            tempShapeNode = tempShapeNode->getNext();
        }
        
        if(tempShapeNode->getShape()->getName() == name)
        {
            return tempShapeNode;
        }
        else
        {
            return nullptr;
        }
        
    }
    
    
    void ShapeList::insert(ShapeNode* s)          // inserts the node pointed to by s at the end
                                        // of the list; s should never be nullptr
    
    {
        //Check for Case #1: Empty List
        if(getHead() == NULL)
        {
            setHead(s);
            s->setNext(NULL);
        }

        // Check for Case#2: Non-Empty List
        else
        {
            ShapeNode* tempptr = getHead();  //No need class.getHead() inside the member functions

            while(tempptr->getNext() != NULL) //NOTE: getNex() is a public member function in GroupNode.h
            {
            tempptr = tempptr->getNext();
            }

            tempptr->setNext(s); // Insert the new node "s" at the tail of the Linked List called "GroupList"
            s->setNext(NULL); // KEY: Usage of setNext() public member function from GroupNode.
        }
    }
    
    ShapeNode* ShapeList::remove(string name)     // removes the node with the shape called name
                                        // returns a pointer to the removed node or
                                        // nullptr is a node with name does not exist
    {
        if(head == NULL)
        {
            return head;
        }
        
        ShapeNode* tempptr1 = getHead();
        ShapeNode* tempptr2 = NULL;
        ShapeNode* tempptr3 = NULL;
    
        while(tempptr1 != NULL)
        {
            if(tempptr1->getShape()->getName() == name)
            {
                break;
            }
            tempptr2 = tempptr1;
            tempptr1 = tempptr1->getNext();
        }
        
        // CASE#2:
        if(tempptr1 == NULL)
        {
            return tempptr1;
        }
        
        // CASE#3: Delete Head Node (1st Node)
        if(tempptr1 == getHead())
        {
//            setHead(getHead()->getNext());
            tempptr3 = tempptr1;
            delete tempptr1;
            return tempptr3;
        }
        
        tempptr3 = tempptr1;
        tempptr2->setNext(tempptr1->getNext());
        delete tempptr1;
        return tempptr3;
    }
    
    void ShapeList::print() const                 // prints the list
    {
//        (tempShapeNode->getShape()->getName() == name)
                
        ShapeNode *tempShapeNode = head;
        
        while(tempShapeNode != NULL)
        {
            tempShapeNode->print();
            tempShapeNode = tempShapeNode->getNext();
        }
    }



