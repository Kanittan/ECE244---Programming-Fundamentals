//
//  parser.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"
#include "ShapeNode.h"
#include "GroupNode.h"
#include "ShapeList.h"
#include "GroupList.h"

// This is a pointer to the groups list
// The list itself must be allocated
GroupList* gList;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here
int findName(Shape **shapesArray, string name, int shapeCount); //NOT SURE IF ARGUMENT IS CORRECT //Return "index i" of array, that is the object that has the inducated name. ELSE Return -1 if NO match NAME inside every index of array (in every object) were found.
bool nameValid(string name);
 bool nameNotExist(Shape **shapesArray, string name, int shapeCount);
bool shapeTypeValid(string type);
bool checkValidArgument(double a);
bool checkValidValue(double a, string argType);
bool checkCircle(string type, double x_loc, double y_loc);


int main() {
    // Create the groups list
    gList = new GroupList();
    
    // Create the pool group (Default Group) and add it to the group list
    GroupNode* poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS-1]);
    gList->insert(poolGroup); // inserts the node  pointed to by pointer "poolGroup" at the end of the list "gList"
    
    // int shapeNum; // ALREADY DECLARED AS "max_shapes"
    string line;
    string command;
    
    string name = ""; //Here TO BELOW - Code I included
    string type = "";
    double double_max_shapes;
    double loc_x = 1;
    double loc_y = 1;
    double size_x = 1;
    double size_y = 1;
    double angle = 0; // BELOW
    char c; //For cin.get() command
    char temp; // Already initialized to NULL.
    int *countPtr;
    double *maxShapePtr;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream newLineStream (line);
        
        name = ""; //Here TO BELOW - Code I included
        type = "";
        loc_x = 1;
        loc_y = 1;
        size_x = 1;
        size_y = 1;
        angle = 0; // BELOW
        
        string a;
        string newLine = "";
//        string commandString;
        int count = 0;
        int i = 0;
        bool isError = false;
        
        while(newLineStream >> a) //Everytime we add 1 String into a
        {
          i++;
          if(i == 1)
          {
            command = a;
          }
          
          if(i>1)
          {
            newLine += (a + " ");
          }
          
          count++;
        }
        countPtr = &count;
        
        
        stringstream lineStream (newLine);
        
//        cout << "count: " << count << endl;
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
//        lineStream >> command; //GIVEN THIS LINE BY DEFAULT
        
        
        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        
        // 1st Priority: ERROR#1: INVALID COMMAND (1st Word entered DOES NOT MATCH one of the valid commands)
        if(!((command == "maxShapes") || (command == "create") || (command == "move") || (command == "rotate") || (command == "draw") || (command == "delete")))
        {
          cout << "Error: invalid command" << endl;
        }


        else if(command == "maxShapes")
        {
          shapeCount = 0;  //Initialize/ Re-initialize shapeCount to 0 everytime maxShapec command is prompted.
          //// ABOVE IS NEWLY ADDDED ////
          
          lineStream >> double_max_shapes;
          
          if((lineStream.fail() == true) || (checkValidArgument(double_max_shapes)==false))
          {
              isError = true;
          }
          
                  // Count Number of argument (For ERROR#8: Too many argument and ERROR#9: Too few argument
          
          //Priority#2: ERROR#2: CHECK FOR INVALID ARGUMENT

          // if((lineStream.fail() == true) && (lineStream.peek() == '.') && (shapeNumValid(max_shapes) == false))
          // {
          //   cout << "invalid argument";
          // }
          
          if(isError == true)
          {
            // 2nd Priority: Error#2: Invalid Argument
            cout << "Error: invalid argument" << endl;
          }
          
          else if(*countPtr > 2 )
          {
              cout << "Error: too many arguments" << endl;
          }
          
          else if(*countPtr < 2)
          {
              cout << "Error: too few arguments" << endl;
          }
          else
          {
              cout << "New database: max shapes is " << (int)double_max_shapes << endl;
           // Valid Input: Input is Integer
//            Shape **shapesArray = new Shape *[(int)double_max_shapes];
              shapesArray = new Shape*[(int)double_max_shapes];
              
              maxShapePtr = &double_max_shapes;
//             for (int i=0; i < (int)double_max_shapes; ++i)
//             {
//               shapesArray[i] = new Shape("","",0,0,0,0);
//             }
          }
          
        }


        else if(command == "create")
        {
          lineStream >> name;
          if((lineStream.fail() == true) && (1 < *countPtr))
          {
//              cout << "ERROR 1" << endl;
              isError = true;
              
          }
          
          lineStream >> type;
          if((lineStream.fail() == true) && (2 < *countPtr))
          {
//              cout << "ERROR 2" << endl;
              isError = true;
          }
          
          lineStream >> loc_x;
          if(((lineStream.fail() == true) || (checkValidArgument(loc_x)== false)) && (3 < *countPtr))
          {
//              cout << "ERROR 3" << endl;
              isError = true;
          }
          
          lineStream >> loc_y;
          
          if(((lineStream.fail() == true) || (checkValidArgument(loc_y)== false)) && (4 < *countPtr))
          {
//              cout << "ERROR 4" << endl;
              isError = true;
          }
          
          lineStream>> size_x;
          if(((lineStream.fail() == true) || (checkValidArgument(size_x)== false)) && (5 < *countPtr))
          {
//              cout << "ERROR 5" << endl;
              isError = true;
          }
          
          lineStream>> size_y;
          if(((lineStream.fail() == true) || (checkValidArgument(size_y)== false)) && (6 < *countPtr))
          {
//              cout << "ERROR 6" << endl;
              isError = true;
          }
          

          // CHECK ERROR FOR ERROR#3:INVALID SHAPE NAME, ERROR#4:SHAPE NAME ALREADY EXISTS
          
          if(shapeCount >= *maxShapePtr)
          {
              cout << "Error: shape array is full" << endl;
          }
          
          // CHECK ERROR#2: Invalid Argument
          else if(isError == true)
          {
            cout << "Error: invalid argument" << endl;
          }
          
          // CHECKS ERROR#3:Invalid Shape Name
          else if(nameValid(name) == false)
          {
              cout << "Error: invalid shape name" << endl;
          }
          
          // ERROR#4:Shape Name Exists
          else if((name!= "") && (nameNotExist(shapesArray, name, shapeCount) == false))
          {
              cout << "Error: shape " << name << " exists" << endl;
          }

          // CHECK ERROR#6: Invalid Shape Type
          else if((type != "") && shapeTypeValid(type) == false)
          {
            cout << "Error: invalid shape type" << endl;
          }

          // CHECK ERROR#7: Invalid Value
          else if((checkValidValue(loc_x, "location_x")==false) || (checkValidValue(loc_y, "location_y")==false) || (checkValidValue(size_x, "size_x")==false) || (checkValidValue(size_y, "size_y")==false) || (checkCircle(type, size_x, size_y)==false))
          {
            cout << "Error: invalid value" << endl;
          }
          
          // CHECK ERROR#7: Too Many Arguments
          else if(*countPtr > 7 )
          {
              cout << "Error: too many arguments" << endl;
          }
          
          // CHECK ERROR#8: Too Few Arguments
          else if(*countPtr < 7)
          {
              cout << "Error: too few arguments" << endl;
          }
          
          else
          {
              cout << "Created " << name << ": " << type << " " << loc_x << " " << loc_y << " " << size_x << " " << size_y << endl;

            // Shape shapesArray[i];
            shapesArray[shapeCount] = new Shape(name,type,loc_x,size_x,loc_y,size_y);
            // shapesArray[shapeCount]->setName(name);
            // shapesArray[shapeCount]->setType(type);
            // shapesArray[shapeCount]->setXlocation(loc_x);
            // shapesArray[shapeCount]->setYlocation(loc_y);
            // shapesArray[shapeCount]->setXsize(size_x);
            // shapesArray[shapeCount]->setYsize(size_y);

            shapeCount++;
          }
          
        }

      else if(command == "move")
      {
        lineStream >> name;
        if((lineStream.fail() == true) && (1 < *countPtr))
        {
//          cout << "ERROR 1" << endl;
            isError = true;       
        }
        
        lineStream >> loc_x;
        if(((lineStream.fail() == true) || (checkValidArgument(loc_x)== false)) && (2 < *countPtr))
        {
//          cout << "ERROR 3" << endl;
            isError = true;
        }
        
        lineStream >> loc_y;
        if(((lineStream.fail() == true) || (checkValidArgument(loc_y)== false)) && (3 < *countPtr))
        {
//          cout << "ERROR 3" << endl;
            isError = true;
        }
        
        int findNameIndex = findName(shapesArray, name, shapeCount);
        
        // CHECK ERROR#2: Invalid Argument
        if(isError == true)
        {
          cout << "Error: invalid argument" << endl;
        }
        
        // CHECKS ERROR#3:Invalid Shape Name
        else if(nameValid(name) == false)
        {
            cout << "Error: invalid shape name" << endl;
        }
        
        // CHECK ERROR#5: Shape Name NOT FOUND
        else if(findNameIndex == -1)
        {
          cout << "Error: shape " << name << " not found" << endl;
//          cin.ignore(10000, '\n');
//          continue;
        }
        
        // CHECK ERROR#7: Invalid Value
        else if((checkValidValue(loc_x, "location_x")==false) || (checkValidValue(loc_y, "location_y")==false))
        {
          cout << "Error: invalid value" << endl;
        }
        
        // CHECK ERROR#7: Too Many Arguments
        else if(*countPtr > 4 )
        {
            cout << "Error: too many arguments" << endl;
        }
          
        // CHECK ERROR#8: Too Few Arguments
        else if(*countPtr < 4)
        {
            cout << "Error: too few arguments" << endl;
        }
        
        else
        {
          cout << "Moved " << name << " to " << loc_x << " " << loc_y << endl;
          shapesArray[findNameIndex]->setXlocation(loc_x);

          shapesArray[findNameIndex]->setYlocation(loc_y);
        }
      }

      else if(command == "rotate")
      {
        
        lineStream >> name;
        
        if((lineStream.fail() == true) && (1 < *countPtr))
        {
//          cout << "ERROR 3" << endl;
            isError = true;
        }
        
        lineStream >> angle;
        if(((lineStream.fail() == true) || (checkValidArgument(angle)== false)) && (2 < *countPtr))
        {
//          cout << "ERROR 3" << endl;
            isError = true;
        }
        
        int findNameIndex = findName(shapesArray, name, shapeCount);
        // CHECK ERROR#2: Invalid Argument
        if(isError == true)
        {
          cout << "Error: invalid argument" << endl;
        }
        
        // CHECKS ERROR#3:Invalid Shape Name
        else if(nameValid(name) == false)
        {
            cout << "Error: invalid shape name" << endl;
        }
        
        // CHECK ERROR#5: Shape Name NOT FOUND
        else if(findNameIndex == -1) // Means Name NOT FOUND
        {
          cout << "Error: shape " << name << " not found" << endl;
        }
        
        // CHECK ERROR#7: Invalid Value
        else if(checkValidValue(angle, "rotate")==false)
        {
          cout << "Error: invalid value" << endl;
        }
        
        // CHECK ERROR#8: Too Many Arguments
        else if(*countPtr > 3 )
        {
            cout << "Error: too many arguments" << endl;
        }
          
        // CHECK ERROR#9: Too Few Arguments
        else if(*countPtr < 3)
        {
            cout << "Error: too few arguments" << endl;
        }
        else
        {
          cout << "Rotated " << name << " by " << angle << " degrees" << endl;
          shapesArray[findNameIndex]->setRotate(angle);
        }
        
      }

      else if(command == "draw")
      {
        lineStream >> name;
        
        if((lineStream.fail() == true) && (1 < *countPtr))
        {
//          cout << "ERROR 3" << endl;
            isError = true;
        }
        
        if(name == "all")
        {
          if(isError == true)
          {
              cout << "Error: invalid argument" << endl;
          }
          
          // CHECK ERROR#8: Too Many Arguments
          else if(*countPtr > 2 )
          {
              cout << "Error: too many arguments" << endl;
          }
          
          // CHECK ERROR#9: Too Few Arguments
          else if(*countPtr < 2)
          {
              cout << "Error: too few arguments" << endl;
          }
          else
          {
            cout << "Drew all shapes" << endl;
            int i=0; 
            while(i<shapeCount)
            {
                if(shapesArray[i] != nullptr)
                {
                  shapesArray[i]->draw();
                  i++;
                }
                else
                {
                    i++;
                }
            }
          }
          
        }
        else // name == specific name that exists // Draw Individual Name
        {
          int findNameIndex = findName(shapesArray, name, shapeCount);
          
          // CHECK ERROR#2: Invalid Argument
          if((isError == true) || (checkValidArgument(angle)==false))
          {
            cout << "Error: invalid argument" << endl;
          }
          
          // CHECKS ERROR#3:Invalid Shape Name (Check if name is a Reserved word or a Shape Type)
          else if(nameValid(name) == false)
          {
            cout << "Error: invalid shape name" << endl;
          }
          
          // ERROR#5: SHAPE NAME NOT FOUND
          else if(findNameIndex == -1) // Means Name NOT FOUND
          {
            cout << "Error: shape " << name << " not found" << endl;
          }
          
          // CHECK ERROR#8: Too Many Arguments
          else if(*countPtr > 2 )
          {
              cout << "Error: too many arguments" << endl;
          }
          
          // CHECK ERROR#9: Too Few Arguments
          else if(*countPtr < 2)
          {
              cout << "Error: too few arguments" << endl;
          }
          
          else
          {
            cout << "Drew ";
            shapesArray[findNameIndex]->draw();
          }
          
        }
      }
      
      else if(command == "delete")
      {
          lineStream >> name;
          if((lineStream.fail() == true) && (1 < *countPtr))
          {
//          cout << "ERROR 3" << endl;
            isError = true;
          }
          
          if(name == "all")
          {
            if(isError == true)
            {
              cout << "Error: invalid argument" << endl;
            }
          
            // CHECK ERROR#8: Too Many Arguments
            else if(*countPtr > 2 )
            {
              cout << "Error: too many arguments" << endl;
            }
          
            // CHECK ERROR#9: Too Few Arguments
            else if(*countPtr < 2)
            {
              cout << "Error: too few arguments" << endl;
            }
            else
            {
              cout << "Deleted: all shapes" << endl;
              
              int i=0; 
              while(i<shapeCount)
              {
                  if(shapesArray[i] != nullptr)
                  {
                    delete shapesArray[i];
                    shapesArray[i] = NULL;
                    i++;
                  }
                  else
                  {
                      i++;
                  }

              }
            }
//              for(int i=0 ; i<shapeCount; i++)
//              {
//                  delete shapesArray[i];
//                  shapesArray[i] = NULL;
//                  
//                  
//              }
//                  delete [] shapesArray;
//                  shapesArray = nullptr;
          }
          else //Delete individual name
          {
              int findNameIndex = findName(shapesArray, name, shapeCount);
              
              // CHECK ERROR#2: Invalid Argument
              if((isError == true) || (checkValidArgument(angle)==false))
              {
                cout << "Error: invalid argument" << endl;
              }
              
              // CHECKS ERROR#3:Invalid Shape Name
              else if(nameValid(name) == false)
              {
                cout << "Error: invalid shape name" << endl;
              }
          
              // ERROR#5: SHAPE NAME NOT FOUND
              else if(findNameIndex == -1) // Means Name NOT FOUND
              {
                cout << "Error: shape " << name << " not found" << endl;
              }
              
              // CHECK ERROR#8: Too Many Arguments
              else if(*countPtr > 2)
              {
                cout << "Error: too many arguments" << endl;
              }
          
              // CHECK ERROR#9: Too Few Arguments
              else if(*countPtr < 2)
              {
                cout << "Error: too few arguments" << endl;
              }
              
              else
              {
                  cout << "Deleted shape " << name << endl;
                  delete shapesArray[findNameIndex];
                  shapesArray[findNameIndex] = NULL;
                  
//                  delete [] shapesArray;
//                  shapesArray = nullptr;
              }
          }
      }
        
        
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}
        
        

