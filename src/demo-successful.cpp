/* File: demo-successful.cpp
   Author: ASSET
   Date: 8/5/2020
   Purpose: This program reads in a .JSON file and prints it to a formatted .txt file
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

int main(void)
{
 
  ifstream file("contacts.csv");
 
  string value;
  string contacts[2][4];
  int first = 0;
  int last = 1;
  //bool even = true;
  int rowNum = 0;

  while(file.good())
    {
      getline(file, value, '\n');
      
      string delimiter = ",";
      string firstName  = value.substr(0, value.find(delimiter));
      string lastName = value.substr((value.find(delimiter)+1), value.length()-1);
      
      contacts[first][rowNum] = firstName;
      contacts[last][rowNum] = lastName;
      
      rowNum++;
      
    }
  
  ofstream myfile;
  myfile.open("contacts.txt");
  for(int i = 0; i < 4; i++)
    {
      int personNum = i + 1;
      myfile << "Person " << to_string(personNum) << ":" << endl << flush;

      string newFirst = contacts[first][i];
      newFirst = newFirst.substr(0, (newFirst.length()));
      myfile << "First name: " << newFirst << endl << flush;
      
      string newLast = contacts[last][i];
      newLast = newLast.substr(0, newLast.length());
      myfile << "Last name: " << newLast << endl << flush;

      myfile << endl;
      //cout << contacts[first][i] << endl;
      //cout << contacts[last][i] << endl;
    }
  myfile.close();


  
}
