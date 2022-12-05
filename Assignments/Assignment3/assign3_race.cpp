/**********************************************************************************************************************
 * Program: assign3_race.cpp
 * Author: Hyunjae Kim
 * Date: 05/04/2020
 * Description: This program allows player to decide the minimum speed, maximum speed, and the length of the race course.
 * 				 Then the program prints out each racer's speed randomly between minimum speed and maximum speed.
 * 				 After this, the program prints out the winner of the race, and the average speed of the racers.
 * ********************************************************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

/**********************************************************************************************************************
 * Function: speed_time(string array[],int array2[],inta,int m,int n,float L)
 * Description: This function prints out the number of the racers and the speed of each racer.
 * Parameters: string array[], int array2[],int a, int m, int n, float array3[]
 * Return: Return car names, speed of the car, and finish time.
 * *******************************************************************************************************************/
void speed_time(string array[], int array2[], int a, int m, int n ,float array3[]){
	
	for(int i = 0;i < a;i++){
		cout << "Car " << i+1 <<" " << array[i] <<": " << array2[i] << "km/h, finishes in " << array3[i] << "minutes.\n" << endl; 
	}
	return;
}

/******************************************************************************************************************
 * Function: winner_plus_speed_average(string array1[], int array2[],int a)
 * Description: This function finds the winner of the race and the average speed of the racers.
 * Parameters: string array1[], int array2[], int a
 * Return: Return the name of the champion and the average speed of the race.
 * ***************************************************************************************************************/
void winner_plus_speed_average(string array1[], int array2[], int a){
	int champion = 0, champion2 = 0 ;
	float sum = 0;
	for(int i = 0;i < a;i++){
		if(array2[i] > array2[champion]){
			champion = i;
		}
		sum += array2[i];
	}
	if(champion+1 < a){
		for(int i = champion+1;i < a;i++){
			if(array2[i] > array2[champion2])
				champion2 = i;
			}	
	}
	if( (array2[champion2] == array2[champion]) && (champion2 > champion) ){ /*If the champion of the race is more than one,it prints out two champions.*/
		cout << "The Champion of the race is " << array1[champion] << " and " << array1[champion2] << "!\n" << endl;
	}
	else {  /*The champion of the race  is only one.*/
		cout << "The Champion of the race is " << array1[champion] << "!\n" << endl;
	}
	cout <<"The average speed of the racers is " << sum/a << "km/h." << endl;

	return;
}

/**************************************************************************************************************
 * Function: invalid_1(int& n,int a = 100, int b = 500)
 * Description: It defines the invalid numbers and asks the player to enter valid number.
 * Parameters: int& n, int a, int b
 * Return: Returns the loop to get_input(int& m, int& n, float& l) function.
 * ***********************************************************************************************************/
void invalid_1(int& n, int a = 100, int b = 500){
	while(n < a || n > b){   /* This iterates until the player enters a valid number.*/
		cout << "Please try again; enter a number between " << a << " and " << b <<": ";
		cin >> n;
	}
	return;
}

/************************************************************************************************************
 * Function: invalid_2(int& m, int& n, int c = 100, int d = 500)
 * Description: It defines the invalid numbers and asks the player to enter valid number in maximum speed.
 * Parameters: int& m, int& n, int c, int d
 * Return: Return the loop to get_input(int& m, int& n, float& l) function.
 * *********************************************************************************************************/
void invalid_2(int& m, int& n, int c = 100, int d = 500){
	while(n >= m || (m < c || m > d)){  /* This iterates until the player enters a valid number.*/
		cout << "Please try again; enter a number between " << c << " and " << d << ": ";
		cin >> m;
	}

	return;
}

/******************************************************************************************************************
 *Function: invalid_3(float& l, int a = 10, int b = 200)
 *Description: It defines the invalid numbers and asks the player to enter valid number in the length of the race.
 *Parameters: float& l, int a, int b
 *Return: Return the loop to get_input(int& m, int&n, float& l) function.
 ******************************************************************************************************************/
void invalid_3(float& l, int a = 10, int b = 200){
	while(l < a || l > b){  /*This iterates until the player enters a valid number.*/ 
		cout << "Please try again; enter a number between " << a << " and " << b << ": ";
		cin >> l;
		}
	
	return;
}

/*******************************************************************************************************************
 * Function: get_input(int& m, int& n, float& l)
 * Description: It is an input function in order to reduce the line of the main() function.
 * Parameters: int& m, int& n, float& l
 * Return: Returns the input that the player made to int main() function
 * *****************************************************************************************************************/
void get_input(int& m, int& n, float& l){
	cout << "What is the minimum car speed in km/h(100~500)? ";
	cin >> m;
	invalid_1(m);
	
	cout << "What is the maximum car speed in km/h(100~500)? ";
	cin >> n;
	invalid_2(n,m);

	cout << "How long is the race course in km(10~200)? ";
	cin >> l;
	invalid_3(l);

	return;
}

int main(){
	srand(time(NULL));
	
	/*I assumed that the number of racers, maximum speed, minimum speed, 
	 * and the speed of each racer have to be integer in order to see the race easily,
	 * so int (min -2*10^9, max 2*10^9) will be sufficient.*/
	const int racer = 10;	
	int max = 0,min = 0,speed[racer] = {};
	
	/*I assumed that the finsih time can be decimal.
	 * In order to print out finish time in decimal 
	 * the length has to be float because the speed of each racer is integer.
	 * So float(min -3.4*10^38, max 3.4*10^38) will be sufficient.*/
	float length = 0, time[racer] = {};
	
	/*I assumed that the name of each racer is more than one character, so string will be sufficient.*/
	string car_name[racer] = {"\e[92mTachyon\e[0m","\e[96mHiggs\e[0m","\e[91mFlash\e[0m","\e[37mSliver Suffer\e[0m","\e[31mBerry Alan\e[0m",
								     "\e[93mLightning Mcqueen\e[0m","\e[34mAerosmith\e[0m","\e[95mSpeedster\e[0m","\e[33mVelocirapter\e[0m","\e[36mGodspeed\e[0m"};
	
	get_input(min, max, length);
	
	
	
	for(int i = 0;i < racer;i++){
		speed[i] = rand()%(max-min+1) + min; /*It stores the speed of each racer between min and max.*/
		time[i] = length/speed[i]*60; /*It stores the finish time of each racer.*/
	}
	
	speed_time(car_name,speed,racer,max,min,time);
	
	winner_plus_speed_average(car_name,speed,racer);

	return 0;
}
