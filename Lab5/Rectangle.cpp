//
//  Rectangle.cpp
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student: Write the implementation of the class here

#include <iostream>
#include <iomanip>
#include "Shape.h"
#include "Rectangle.h"
#include <cmath>
        
Rectangle::Rectangle(string n, float x_cen, float y_cen, float width, float height): Shape(n, x_cen, y_cen)
{
    this->width = width;
    this->height = height;
    
}
    
void Rectangle::draw() const
{
    // Set floating point printing to fixed point with 2 decimals
    cout << std::fixed;
    cout << std::setprecision(2);
    
    cout << "rectangle: " << getName() << " " << getXCentre() << " " << getYCentre()
            << " " << width << " " << height 
            << " " << computeArea() << endl;
}

float Rectangle::computeArea() const
{
    return width * height;
}

Rectangle::~Rectangle() { }

Shape* Rectangle::clone() const
{
    return new Rectangle(getName(), getXCentre(), getYCentre(), width, height);
}
