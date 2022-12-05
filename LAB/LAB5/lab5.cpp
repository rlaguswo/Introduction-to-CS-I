/*********************************************************************************
 * Program: lab5.cpp
 * Date: 04/28/2020
 * Author: Hyunjae Kim 
 * Description: This program asks the user to enter a number and return by adding 10. 
 * 				 Moreover, this passes the value as a reference.
 * 				 This program calculates the sum of the array, and modifies array.
 * ******************************************************************************/

#include <iostream>
using namespace std;

/************************************************************************************
 * Function: plus_10_value
 * Description: return a number with adding 10
 * Parameters: int n
 * Test Cases: 10 -> 20
 *             100 -> 110
 *             1 -> 11
 * *********************************************************************************/

int plus_10_value(int n){

return n+10;
}

void plus_10_ref(int& n){
  n = n+10;
}

int tally(int array[],int n_items){
	int sum =0;
	for(int i = 0; i<n_items;i++){
		sum += array[i];
	}
	cout << sum << endl;
}

void inc_each_element_by_one(int array[],int n_items){
	for(int i=0;i < n_items; i++){
		/*cout << ++array[i] << " ";*/
		array[i] = array[i]+1;
		cout << array[i] << " ";
	}


}
int main(){
int number;
int number2;
int array1[] = {1,2,3,4,5};  /*sum = 15*/
int array2[] = {2,4,6,8,10}; /*sum = 30*/
int array3[] = {1,3,5,7,9};  /*sum = 25*/ 
int array4[] = {9,19,29,39,49}; /*sum = 145*/
cout << "Enter an integer: ";
cin >> number;

number = plus_10_value(number);

cout << "Your number plus 10 is " << number << endl;

plus_10_ref(number);
cout << number << endl;
cout << endl;

tally(array1,5);
tally(array2,5);
tally(array3,5);
cout << endl;
for(int i = 0;i<5;i++){
	cout << array4[i] << " ";
}
cout << endl;
inc_each_element_by_one(array4,5);
cout << endl;

return 0;
}
