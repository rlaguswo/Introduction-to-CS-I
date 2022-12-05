/********************************************************************************************************************
 * Program: assign4_restaurant.cpp
 * Author: Hyunjae Kim
 * Date: 05/18/2020
 * Description: This program gives chances to the user to choose the menu of the restaurant.
 * 				 It asks the size of the party to the user and stores the order of the user.
 * 				 Then the program asks the user to give a tip or not.
 * 				 The program calculates the toatl and asks the user to split the bill or not.
 * 				 If the user decide to split the bill, the program calculates the price that each person have to pay.
 * ******************************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/***********************************************************************************************************
 * Function: invalid_input(int& n, int a, int b)
 * Parameters: int& n, int a, int b
 * Description: This function handles invalid input of the user, and prompts the user to enter valid input.
 * *********************************************************************************************************/
void invalid_input(int& n,int a, int b){
	while((n<a)||(n>b)){
		cout << "Invalid Party Size; Please enter a number between " << a << " and " << b << ": ";
		cin >> n;
	}
}

/********************************************************************************************************
 * Function: choices(string arr1[],float arr2[],int* n)
 * Parameters: string arr1[],float arr2[],int* n
 * Return: This function prints out the menu and the price, and handles the invalid input.
 * 		  Moreover, it prompts the user to enter valid input.
 * 		  The fundamental thing which this fucntion does is returning the heap to the int main() function.
 * ******************************************************************************************************/
int* choices(string arr1[], float arr2[], int* n, unsigned short c){
	int* menu_choice = new int[*n];
	for(int i = 0; i < *n;i++){
		for(int m =0; m < c;m++){ /*Prints out the dishes and the price of the dishes.*/
			cout << m+1 << " " << arr1[m] << ": $"  << arr2[m] << endl; 
		}
		cout << "Enter: ";
		cin >> menu_choice[i];
		
		/*Handles the invalid choice, and prompts the user to enter valid choice.*/
		while(menu_choice[i] < 1 || menu_choice[i] > 4){ 
			cout << "Invalid Order; Please enter a number between 1 and 4: " << endl;
			cout << "Enter: ";
			cin >> menu_choice[i];
		}

	}

/*Return the pointer to new array.*/
return menu_choice;
}

/************************************************************************************************************************
 * Function: print_bill(float a,int c)
 * Parameters: float a,int c
 * Description: This function prints out the bill when the user dosen't decide to give a tip.
 * 				 Moreover, it asks the user to split the bill or not.
 * 				 If the user wants to split the bill, it splits the bill and calculate how much each person has to pay.
 * *********************************************************************************************************************/
void print_bill(float a,int c){
	char yes_no1 = 'y';

	if(c > 1){
		cout << "Do you want to split the bill (y/n)? ";
		cin >> yes_no1;
		if(yes_no1 != 'y'){
		cout<< "_____________________________________________" << endl;
	 	cout << "Total amount: $" << a << endl;
		cout<< "_____________________________________________" << endl;
		}

		else{
	
		cout<< "_____________________________________________" << endl;
		cout << "Total amount: $" << a << endl;
		cout << "Each: $" << a/c << endl;
		cout << "_____________________________________________" << endl;
		
		
		}	
	}
}

/***********************************************************************************************************************
 * Function: print_bill1(float a,float b,int c)
 * Parametes: float a,float b,int c
 * Description: This function prints out the bill when the user decide to give a tip.
 * 				 Moreover, it asks the user to split the bill or not.
 *					 If the user wants to split the bill, it splits the bill and calculate how much each person has to pay.
 * *********************************************************************************************************************/
void print_bill1(float a,float b,int c){

		char yes_no1 = 'y';	

		cout<< "_____________________________________________" << endl;
	 	cout << "Total amount: $" << a+b << endl;
		cout<< "_____________________________________________" << endl;

		if(c > 1){
			cout << "Do you want to split the bill (y/n)? ";
			cin >> yes_no1;
		if(yes_no1 != 'y'){
			cout<< "_____________________________________________" << endl;
	 		cout << "Total amount: $" << a+b << endl;
			cout<< "_____________________________________________" << endl;
		}
		else{
		
			cout<< "_____________________________________________" << endl;
	 		cout << "Total amount: $" << a+b << endl;
			cout << "Each: $" << (a+b)/c << endl;
			cout<< "_____________________________________________" << endl;
			
			}
		}
}

/******************************************************************************************************************************
 * Function: bill_intro()
 * Description: This function prints out the intro of the bill.
 * 				 The purpose of this function is to reduce the line of void bill(int* n,int arr1[],string arr2[],float arr3[])
 * ****************************************************************************************************************************/
void bill_intro(){

	cout << "The bill for your delightful meal:" << endl;
	cout<< "_____________________________________________" << endl;
}

/***********************************************************************************************************************************
 * Function: bill(int *n,int arr1[],string arr2[],float arr3[])
 * Parameters: int* n int arr1[],string arr2[],float arr3[]
 * Description: This function prints out the entire bill and calculates the total amount of the price with the heap(dynamic array).
 * 				 Moreover, this fuction calculates total price including the tip with the heap(dynamic array).
 * *********************************************************************************************************************************/
void bill(int* n,int arr1[],string arr2[],float arr3[]){

	/*I assume that the total amount and tip will be positive decimal numbers,
	 * so float (min -3.4*10^38, max 3.4*10^38) will be sufficient.*/
	float total = 0,tip = 0;
	char yes_no = 'y';

	cout << "I hope your dinner was delicious!" << endl << "Do you want to give a tip (y/n)? ";
	cin >> yes_no;
	if(yes_no != 'y'){
		bill_intro();
		for(int i = 0;i < *n;i++){ /*Prints out  what diners had eaten.*/
			total += arr3[arr1[i]-1];
			cout << "Diner" << i+1 << " "  << arr2[arr1[i]-1] <<": $" << arr3[arr1[i]-1] << endl;
		}
		print_bill(total,*n);
	}

	else{
		cout << "Tip: $";
		cin >> tip;
		bill_intro();
		for(int i = 0;i < *n; i++){ /*calculates the total amount of money.*/
			total += arr3[arr1[i]-1];
			cout << "Diner" << i+1 << " "  << arr2[arr1[i]-1] <<": $" << arr3[arr1[i]-1] << endl;
			}		

		print_bill1(total,tip,*n);
	}
}

/*********************************************************************************************
 * Function: intro()
 * Description: This fucntion prints out the intro of the program.
 * 				 The purpose of this program is to reduce the line of int main() function.
 * ******************************************************************************************/
void intro(){
	cout << "Welcome to the Steak House Restaurant!" << endl;
	cout << "How many diners in your party (1~25)? " << endl;
	cout << "Enter: ";
}

int main(){
	/* I assume that the size of the party will be a positive whole numbuers,
	 * so int (min -2*10^9, max 2*10^9) will be sufficient.*/
	int diners = 0;

	/* I assume that the number of the menu will be a positive whole number,
	 * and less than 10, so unsigned short (min 0, max 65535) 
	 * will be sufficient.*/ 
	const unsigned short restaurant = 4;

	string menus[restaurant] = {"\e[7mTenderloin Steak\e[0m","\e[7mSirloin Steak\e[0m",
										 "\e[7mT-bone Steak\e[0m","\e[7mTomahawk Steak\e[0m"};
	
	/*I assume that the price of the dish will be positive decimal numbers,
	 * so float (min -3.4*10^38, max 3.4*10^38) will be sufficient.*/
	float prices[restaurant] = {15.85,14.65,21.75,30.55};
	
	while(true){ /*This is a loop to handle more than one party.*/
		intro();
		cin >> diners;
		invalid_input(diners,1,25);
		int* choice = choices(menus,prices,&diners,restaurant);
		bill(&diners,choice,menus,prices);	
		delete [] choice;
		choice = NULL;
	}


return 0;
}
