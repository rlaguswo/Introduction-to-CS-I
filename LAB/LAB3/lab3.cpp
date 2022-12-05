/*************************************************************************************************
* Program: lab3.cpp
 * Author:  Hyunjae Kim,Brendan Michael Baldocchi, Chapman Kuykendall,  Sabine Michele Vanderkooi
 * Date: 04/14/2020
 * Description: This program pints out message multiple times and name reversely.
 ************************************************************************************************/


#include <iostream>
#include <string>
using namespace std;
int main(){
int number_times;
int i;
cout << "How many times would you like to see my message? ";
cin >> number_times;
if(number_times<0)return 1;
for(i=0;i<number_times;i++){
 cout << "My name is Hyunjae Kim." << endl;
}
cout << "Please enter your name: ";
string name;
cin >> name;
for(i= name.length()-1;i>=0;i--){
	cout << name[i];
}

cout << " " << endl;
return 0;
}
