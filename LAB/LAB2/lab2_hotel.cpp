/**********************************************************
 ** Program: lab2_hotel.cpp
 ** Authors: Both partners’ names
 ** Date: 4/6/2020
 ** Description: Assign a guest to a random hotel floor.
 ***********************************************************/

#include <iostream> 
#include <cstdlib> /* include to allow rand() to be used */ 
#include <ctime>
using namespace std; 

int main() {
  int hotel_floor; /* variable to hold a random integer */
  srand(time(NULL));
  hotel_floor = rand(); 
  cout << hotel_floor%6 << endl;
  if(hotel_floor%6 == 0){
   cout << " You are assigned to the ground floor." << endl;
  
  } 
  else if(hotel_floor%6 == 1 || hotel_floor%6 == 3, hotel_floor%6 ==5){
		    
		  cout << " You are assigned to an odd floor." << endl;
		  
		  
		  
		  }
		  
  else {
          cout << "You are assigned to an even floor" << endl; 

		  }







  

  return 0;
}
