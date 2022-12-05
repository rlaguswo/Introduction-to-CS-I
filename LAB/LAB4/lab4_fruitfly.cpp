/*************************************************************************************************************************************************
 * Program: lab4_fruitfly.cpp
 * Author: Hyunjae Kim
 * Date: 04/21/2020
 * Description: This program asks the user to enter the numbers of the flies and find out which jar has the most flies and the least flies.
 * Test cases: 1. 1 2 3 4 5 
 * 				2. 1 9 8 3 6
 * 				3. 9 2 5 6 7 
 * ***********************************************************************************************************************************************/

#include <iostream>
using namespace std;
int main(){
int jar[5];
int number1=0;
int number2=0;
int the_most;
int the_least;
cout << "Hello! Scientist! You have 5 jars to fill with fruit flies." << endl;
for(int i = 0; i<5;i++){
	cout << "How many fruit flies would you like in jar " << i << ": ";
	cin >> jar [i];
}
cout << "Numbers of fruit flies per jar: " << endl;
for(int i = 0;i<5;i++){
	cout << "jar " << i << jar[i] << endl;

} 
the_least = jar[0];
the_most = jar[0];
for(int i = 0; i <5 ; i++){
	if(the_most < jar[i]){
		the_most = jar[i];
		number1 = i;
	}
	if(the_least > jar[i]){
		the_least = jar[i];
		number2 = i;
	}
	
}
if(the_least == 1){
	cout << "The jar with the most fruit flies: jar  " << number1 <<  " ("  <<the_most << " flies)" << endl;
	cout << "The jar with the least fruit flies: jar  " << number2  <<" ("  << the_least << " fly)" << endl;
}
else{
	cout << "The jar with the most fruit flies: jar " << number1 << " (" << the_most << "flies)" << endl;
	cout << "The jar with the least fruit flies: jar " << number2 << " (" << the_least << "flies)" << endl;

}
return 0;
}
