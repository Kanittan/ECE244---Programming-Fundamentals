//
//  Triangle.cpp
//  Lab5
//
//  Created by Tarek Abdelrahman on 2020-11-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student: Write the implementation of the class Rectangle here
#include <iostream>
#include <iomanip>
#include "Shape.h"
#include "Triangle.h"
#include <cmath>
        
Triangle::Triangle(string n, float x1, float y1, float x2, float y2, float x3, float y3): Shape(n, 0.0, 0.0)
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->x3 = x3;
    this->y3 = y3;
    x_centre = (x1 + x2 + x3)/3;
    y_centre = (y1 + y2 + y3)/3;
    
}
    
void Triangle::draw() const
{
    // Set floating point printing to fixed point with 2 decimals
    cout << std::fixed;
    cout << std::setprecision(2);
    
    cout << "triangle: " << getName() << " " << getXCentre() << " " << getYCentre()
            << " " << x1 << " " << y1 
            << " " << x2 << " " << y2 
            << " " << x3 << " " << y3
            << " " << computeArea() << endl;
}

float Triangle::computeArea() const
{
    return abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2;
}

Triangle::~Triangle() { }

Shape* Triangle::clone() const
{
    return new Triangle(getName(), x1, y1, x2, y2, x3, y3);
}