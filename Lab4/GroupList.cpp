//
//  GroupList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the GroupList class below
#include "GroupList.h"
//#include "GroupNode.h"
GroupList::GroupList()
{
    head = nullptr;
}


//GroupList::~GroupList()
//{
//    GroupNode* tempptr = head;
//    
//    ShapeNode* tempShapeNode = NULL;
//    
//    if(getHead() == NULL)
//    {
//        setHead(s);
//        s->setNext(NULL);
//    }
//    
//    // Check for Case#2: Non-Empty List
//    else
//    {
//        GroupNode* tempptr = getHead();  //No need class.getHead() inside the member functions
//        
//        while(tempptr->getNext() != NULL) //NOTE: getNex() is a public member function in GroupNode.h
//        {
//        tempptr = tempptr->getNext();
//        }
//    
//        tempptr->setNext(s); // Insert the new node "s" at the tail of the Linked List called "GroupList"
//        s->setNext(NULL); // KEY: Usage of setNext() public member function from GroupNode.
//    }
//    
//    ////
//    
//    head->getShapeList()->getHead()->setNext(tempptr->getShapeList()->getHead()); 
//                
//    delete GroupNode;
//}


GroupNode* GroupList::getHead() const
{
    return head;
}


void GroupList::setHead(GroupNode* ptr)
{
    head = ptr;
}


void GroupList::insert(GroupNode* s)
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
        GroupNode* tempptr = getHead();  //No need class.getHead() inside the member functions
        
        while(tempptr->getNext() != NULL) //NOTE: getNex() is a public member function in GroupNode.h
        {
        tempptr = tempptr->getNext();
        }
    
        tempptr->setNext(s); // Insert the new node "s" at the tail of the Linked List called "GroupList"
        s->setNext(NULL); // KEY: Usage of setNext() public member function from GroupNode.
    }
    
}

// Delete Group:

// WARNING: NO RETURN STATEMENT (Type os GroupNode * (Pointer to class)) NOT SURE HOW/WHAT I have to return.

// 1.) MUST Move ALL the ShapeNodes in ShapeList are added at the END of the pool's ShapeList (pool = 1st default GroupNode)
GroupNode* GroupList::remove(string name)
{
    GroupNode* tempptr1 = getHead();
    GroupNode* tempptr2 = NULL;
    GroupNode* tempptr3 = head; //For finding the LAST Shape Node of Head.
    ShapeNode* tempptr4 = tempptr3->getShapeList()->getHead();
    
    // PART 1: To get the LAST ShapeNode of the 1st GroupNode
    while(tempptr4->getNext() != NULL)
    {
        tempptr4 = tempptr4->getNext();
    }
    
    while(tempptr1 != NULL)
    {
        if(tempptr1->getName() == name)
        {
            break;
        }
        tempptr2 = tempptr1;
        tempptr1 = tempptr1->getNext();
    }
    
    // CASE#2: Delete Head Node (1st Node)
//    if(tempptr1 == getHead())
//    {
//        setHead(getHead()->getNext());
//        delete tempptr1;
//    }
    
    tempptr2->setNext(tempptr1->getNext());
    
    //// tempptr3 FROM PART 1 ABOVE ////
//    head->getShapeList()->getHead()->setNext(tempptr1->getShapeList()->getHead());
    tempptr4->setNext(tempptr1->getShapeList()->getHead());
    
    delete tempptr1; //Free the memory(?)
    
    
    ///// BELOW: Insert the ShapeList of the "Deleted GroupNode" at the end of "pool GroupNode" /////
    // NOT SURE if we do the OPERATION 1.) above HERE OR in the GroupList.cpp file???
}


// Prints the List: 1 GroupNode at a time
void GroupList::print() const
{
    GroupNode* tempptr = getHead();  //No need class.getHead() inside the member functions
    
    
    while(tempptr != NULL) //NOTE: getNex() is a public member function in GroupNode.h
    {
        tempptr->print();
        tempptr = tempptr->getNext();
    }
    
}




