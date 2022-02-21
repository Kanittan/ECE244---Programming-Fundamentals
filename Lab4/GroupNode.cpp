//
//  GroupNode.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the GroupNode class below
#include "GroupNode.h"
    
    // Construct when creating a "NEW" GroupNode called "some_Name" (Syntax: ptr = new GroupNode name;)
    GroupNode::GroupNode(string n)                   // sets group name to n and makes myShapeList point to a new ShapeList; sets next to nullptr
    {
        name = n; // Sets Group Name to "n"
        setShapeList(NULL);    // makes myShapeList point to a new ShapeList (Continue 2nd Line)
                               // Which new ShapeList is INITIALLY set to "NULL";
        setNext(nullptr);      // Becareful with "NULL" and "nullptr" usage
        
    }
    
    GroupNode::~GroupNode()                          // deletes the myShapeList list
    {
        // 1.) MUST Move ALL the ShapeNodes in ShapeList are added at the END of the pool's ShapeList (pool = 1st default GroupNode)
        // NOT SURE if we do the OPERATION 1.) above HERE OR in the GroupList.cpp file???
//        delete myShapeList;
        
    }
    
    string GroupNode::getName() const                // returns group name
    {
        return name;
    }

    ShapeList* GroupNode::getShapeList() const       // returns myShapeList
    {
        return myShapeList;
    }

    void GroupNode::setShapeList(ShapeList* ptr)     // sets myShapeList to ptr
    {
        myShapeList = ptr;
    }

    GroupNode* GroupNode::getNext() const            // returns next
    {
        return next; // next of "GroupNode" (NOT of myShapelist linked list for ShapeNode)
    }

    void GroupNode::setNext(GroupNode* ptr)          // sets next to ptr
    {
        next = ptr;
    }

    void GroupNode::print() const                    // prints the GroupNode
    {
        myShapeList->print();
    }

