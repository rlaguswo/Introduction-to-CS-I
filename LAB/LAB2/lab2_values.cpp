/**********************************************************
 ** Program: lab2_values.cpp
 ** Authors: Hyunjae Kim, An Nguyen, Dylan Lefor
 ** Date: 4/6/2020
 ** Description: Calculate min/max values.
 ***********************************************************/

#include <iostream> 
#include <cmath> 
using namespace std; 

int main() {

  int n_bits = 0; /* Number of bits to use for calculation.
		   * Initialize to 0 before the user input. */
  cout << "Enter the number of bits: ";
  cin >> n_bits;
  


  int max_int = pow(2 ,  n_bits-1)-1;
  int min_int = pow(-2,  n_bits-1);
  int max_unsigned_int =pow(2, n_bits);
  /* Write your code here to calculate and print: */
  cout << "Minimum signed value: " <<-min_int << endl;  /* 1) Minimum signed value that can be stored in b bits */
  cout << "Maximum signed value: " << max_int << endl; /* 2) Maximum signed value that can be stored in b bits */
  cout << "Maximum unsigned value: " <<-- max_unsigned_int <<endl; /* 3) Maximum unsigned value that can be stored in b bits */
  return 0;
} 
