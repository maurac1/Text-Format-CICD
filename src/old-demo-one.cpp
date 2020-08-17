/* Title: demo-successful.cpp
   Date: 8/3/2020
   Author: ASSET
   Purpose: Successful demo program
*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>


int main(void)
{
  //print greeting
  std::cout << "Welcome to the ASSET demo!" << std::endl;

  bool quit = false;
  do
    {
      std::cout << std::endl;
      
      //print menu
      std::cout << "Would you like to:" << std::endl;
      std::cout << "1. Query the database" << std::endl << "2. Insert into the database" << std::endl;
      std::cout << "3. Quit" << std::endl;

      int inputValue;
      std::cin >> inputValue;

      if(inputValue == 3)
	{
	  quit = true;
	}
      else if(inputValue < 1 || inputValue > 3)
	{
	  std::cout << "That number is not valid, try again." << std::endl;
	}
      else if(inputValue == 1)
	{
	  //perform query here
	  std::cout << "Performing Query" << std::endl;
	}
      else if(inputValue == 2)
	{
	  std::string str;
	  std::string last;
	  std::string first;
	  
	  //get first name
	  std::cout << "First name: ";
	  std::cin.ignore();
	  getline(std::cin, str);
	  first = str;
	  
	  //get last name
	  std::cout << "Last name: ";
	  getline(std::cin, str);
	  last = str;
	  	  
	  /*-----------------------------
	   | TEST - TO BE DELETED        |
            -----------------------------
	  */
	  std::cout << first << std::endl;
	  std::cout << last << std::endl;
	  
	  //perform insertion here
	  std::cout << "Performing Insertion" << std::endl;
	}

      
  
    }while(!quit);
  std::cout << "Goodbye!" << std::endl;

  
}
