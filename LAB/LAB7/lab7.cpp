/****************************************************************************************************************
 * Program: lab7.cpp
 * Author: Hyunjae Kim
 * Date: 05/12/2020
 * Description: This program reads the user's input and prints out the result by using string and dynamic array.
 * **************************************************************************************************************/


#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
int* grades(int num){
	srand(time(NULL));
	int* grade = new int[num];
	for(int i = 0;i<num;i++){
		 grade[i] = rand()%31+70;
	}


return grade;
}


int main(){
	int classes = 0;
	float star = 0;
	char* my_str = new char[21];
	cout << "Please enter a string(<=20): ";
	cin.getline(my_str,21);

	for(int i=0;i<strlen(my_str);i++){
		if(my_str[i] == '*')
			star++;
	}

	cout << "String Length: " << strlen(my_str)  << endl;
	cout << "Star Factor: " << star << endl;
	cout << "Percentage: " <<(star/strlen(my_str))*100 << endl;
	
	delete [] my_str;
	my_str = NULL;

	cout << "How many classes are you taking? ";
	cin >> classes;
	int* class_grade = grades(classes);
	for(int i=0;i<classes;i++){
		cout << "Your grade in class " << i+1 << " is " << class_grade[i] << "." << endl;
	}
	
	delete [] class_grade;
	class_grade = NULL;
return 0;
}
