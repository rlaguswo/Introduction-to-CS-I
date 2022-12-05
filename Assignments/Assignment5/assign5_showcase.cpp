/*****************************************************************************************************************************************************
 *Program: assign5_showcase.cpp
 *Date: 06/01/2020
 *Author: Hyunjae Kim
 *Description: This program is about the showcase. You can create a showcase, and determine the size of the showcase. 
 					You can sell a book in the showcase, or buy another book to fill the showcase. You can earn money by reciting the book in the showcase. 
					Moreover, you can always check the total values of the books in the showcase, and the amount of money in your bank account.
 *****************************************************************************************************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct books{
	
	/*I assumed that the title of the book will be longer than one character,
	 * so string will be sufficient.*/
	string title;

	/*I assumed that the name of author will be longer than one character,
	 * so string will be sufficient.*/
	string author;
	
	/*I assumed that the value of the book will be positive integer,
	 * so int(min -2*10^9, max 2*10^9) will be sufficient.*/
	int value;
	
	/*I assumed that the publication year of the book will be positive integer,
	 * so int(min -2*10^9, max 2*10^9) will be sufficient.*/
	int year;
};

/**************************************************************************************************
 * Function: create_showcase(int x,int y,int& s,string arr1[],string arr2[],int arr3[],int arr4[])
 * Parameters: int x,int y,int& s,string arr1[],string arr2[],int arr3[],int arr4[]
 * Pre-condition: string arr1[],string arr2[],int arr3[],int arr4[] has to be initiated 
 * 					in the int main() function.
 * Post-condition: This function should be called in the int main() function.
 * Return: This function returns dynamic 2D array which size is determined by the user.
 * 		  The struct of the 2D arrays are stored, and they are random.
 * ************************************************************************************************/
books** create_showcase(int x,int y,int&s,string arr1[],string arr2[],
								int arr3[],int arr4[]){
	srand(time(NULL));
	books** f = NULL;
	f = new books* [x];
	for(int i = 0;i < x;i++)
		f[i] = new books[y];
	for(int a = 0;a < x;a++){
		for(int b = 0;b < y;b++){
			int num = rand()%16;
			f[a][b].title = arr1[num];
			f[a][b].author = arr2[num];
			f[a][b].value = arr3[num];
			f[a][b].year = arr4[num];
			s += f[a][b].value;
		}
	}

return f;
}

/********************************************************************************
 * Function: count_items(books** arr,int x,int y)
 * Parameters: books** arr,int x,int y
 * Pre-condition: The size of the 2D array has to be determined, and the 2D array
 * 					has to be created already.
 * Post-condition: This function should be called in the pint_program function. 
 * Return: This function returns the number of the items in the shocase.
 ********************************************************************************/
int count_items(books** arr,int x,int y){
	int item = 0;
	for(int i = 0;i < x;i++){
		for(int j = 0;j < y;j++){
			if(arr[i][j].value != 0)
				item++;
		}
	}

return item;
}

/*********************************************************************************
 * Function: show_item(books** arr,int x,int y,int a)
 * Parameters: books** arr,int x,int y,int a
 * Pre-condition: The size of the 2D array has to be determined already, and
 * 					the 2D array has to be created.
 * Post-condition: This function should be called in the print_program function.
 * Descriptions: This function shows the information of the book in the showcase.
 * 				  If there is no book in the location which the user chose,
 * 				  it informs the user that there is no book in that location.
 *********************************************************************************/
void show_item(books** arr,int x,int y,int a){
	if(a == 1){
		if(arr[x-1][y-1].value == 0)
			cout << "There is no book! Please try again!" << endl;

		/*If there is a book in the chosen location,
		 *it prints out the information of the book.*/
		else{
		cout << "Book: |Title: " << arr[x-1][y-1].title << "|Author: " 
		<< arr[x-1][y-1].author << "|Value: $" << arr[x-1][y-1].value
		<< "|Publication year: " << arr[x-1][y-1].year << "|" << endl;
		}
	}
}

/**************************************************************************************************************************
 * Function: sell_item(books** arr,int x,int y,int a,string arr1[],string arr2[],int arr3[],int arr4[],int& b,int& s)
 * Parameters: books** arr,int x,int y,int a,string arr1[],string arr2[],int arr3[],int arr4[]
 * Pre-condition: The size of the 2D array has to be determined already, and
 * 					the 2D array has to be created.
 * Post-condition: This function should be called in the print_program function.
 * Description: This function sells the item in the showcase. 
 * 				 The user enters the location of the book which the user wants to sell.
 * 				 after selling the book, it deducts money from the total value as the value of the book, 
 * 				 and add the money to the bank account as the value of the book.
 * 				 If there is no book in the location which the user chose, 
 * 				 the function informs that there is no book in that location.
 **************************************************************************************************************************/
void sell_item(books** arr,int x,int y,int a, string arr1[],string arr2[],
				   int arr3[],int arr4[],int& b,int& s){
	if(a == 2){
		if(arr[x-1][y-1].value == 0){
				cout << "There is no book! Please try again!" << endl;
		}
		else { /*If the book is sold, it changes the location of the book empty.*/
			cout << "You sell |" << arr[x-1][y-1].title << "| for $"
			<< arr[x-1][y-1].value << "." << endl;
			b += arr[x-1][y-1].value;
			s -= arr[x-1][y-1].value;
			arr[x-1][y-1].title = "__________";
			arr[x-1][y-1].author = "__________";
			arr[x-1][y-1].value = 0;
			arr[x-1][y-1].year = 0;
		}
	}
}

/***************************************************************************************************************************
 * Function: buy_item(books** arr,int x,int y,int a,string arr1[],string arr2[],int arr3[],int arr4[],int& b,int& s)
 * Parameters: books** arr,int x,int y,int a,string arr1[],string arr2[],int arr3[],int arr4[],int& b,in& s
 * Pre-condition: The size of the 2D array has to be determined already, and
 * 					the 2D array has to be created.
 * Post-condition: This function should be called in the print_program function.
 * Description: This funtion buys another book. 
 * 				 The user only can buy another book if there is any empty location in the showcase.
 * 				 The user has choice to buy a book or not. After the user buys the book, the user pays $50. 
 * 				 $50 will be deducted from the bank account, but the value of the book will be added to the total value.
 * 				 The reason is that even though the user might buy the book at $50, the value of the book is constant.
 ***************************************************************************************************************************/
void buy_item(books** arr,int x,int y,int a,string arr1[],string arr2[],
				  int arr3[],int arr4[],int& b,int& s){
	int num = rand()%16;
	char yes_no = 'y';
	if(a == 3){
		if(arr[x-1][y-1].value != 0)
			cout << "This Location is full! Please try again!" << endl;
		if(arr[x-1][y-1].value == 0){
			cout << "You will be charged $50 for buying a book. Proceed (y/n)? ";
			cin >> yes_no;
			if(yes_no == 'y'){
				arr[x-1][y-1].title = arr1[num];
				arr[x-1][y-1].author = arr2[num];
				arr[x-1][y-1].value = arr3[num];
				arr[x-1][y-1].year = arr4[num];
				b -= 50;
				s += arr[x-1][y-1].value;
			}
			else /*If the user decides not to buy another book, it returns to the main function.*/
				return;
			}	
	}
}

/**************************************************************************************
 * Function: recite_item(books** arr,int x,int y,int a,int& b)
 * Parameters: books** arr,int x,int y,int a,int& b
 * Pre-condition: The size of the 2D array has to be determined already, and
 * 					the 2D array has to be created.
 * Post-condition: This function should be called in the print_program function.
 * Description: This function makes the user to earn money without selling the book. 
 * 				 If the user choose a book in the showcase, the user will earn $300.
 * 				 $300 will be only added to the user's bank account.
 **************************************************************************************/
void recite_item(books** arr,int x,int y,int a,int& b){
	if(a == 4){
		if(arr[x-1][y-1].value == 0)
			cout << "There is no book! Please try again!" << endl;
	
		else{ /* If there is book in the location, it prints out that the user recited the book for $300.*/
			cout << "You recited |" << arr[x-1][y-1].title << "| for $300." << endl;
			b += 300;
		}
	}
}

/*******************************************************************************
 * Function: print_showcase(books** arr,int x,int y)
 * Parametes: books** arr,int x,int y
 * Pre-condition: The size of the 2D array has to be determined already, and
 * 					the 2D array has to be created.
 * Post-condition: This function should be called in the print_program function.
 * Descriptions: This function prints out the allocated 2D array.
 * ****************************************************************************/
void print_showcase(books** arr,int x,int y){
	for(int i = 0;i < x;i++){
		for(int j = 0;j < y;j++){
			cout << arr[i][j].title << "\t";
		}
		cout << endl;
	}
}

/****************************************************************************************
 * Function: invalid_choice(int& a)
 * Paramete: int& a
 * Pre-condition: The input of the user has to be less than 1 or more than 5.
 * Post-condition: This function should be called in the print_program() function.
 * Description: If the user enter an invalid choice in the option part in the program,
 * 				 it prompts user to enter a valid choice.
 ****************************************************************************************/
void invalid_choice(int& a){
	while(a < 1 || a > 5){
		cout << "Invalid choice! Please try again: ";
		cin >> a;
	}
}

/*************************************************************************************************************************************
 * Function: invalid_row(int& a,int b)
 * Parameters: int& s,int b
 * Pre-condition: The input of the user has to be less than 1 and more than the determined size of  maximum number of the row.
 * Post-condition: This function should be called in the print_program() and asking_location() function.
 * Description: If the user enters a number of the row 
 * 				 which is not between 1 and the maximum number of the column of the showcase,
 * 				 it prompts the user to enter a number of the row between 1 and the maximum number of the row of the showcase..
 *************************************************************************************************************************************/
void invalid_row(int& a,int b){
	while(a < 1 || a > b){
		cout << "You entered wrong row. Please try again: ";
		cin >> a;
	}
}

/*************************************************************************************************************************************
 * Function: invalid_column(int& a,int b)
 * Parameters: int& a,int b
 * Pre-condition: The input of the user has to be less than 1 and more than the determined size of maximum number of the column.
 * Post-condition: This function should be called in the print_program() function and asking_location() function.
 * Description: If the user enters a number of the column 
 * 				 which is not between 1 and the maximum number of the column of the showcase,
 * 				 it prompts the user to enter a number of the column between 1 and the maximum number of the column of the showcase..
 *************************************************************************************************************************************/
void invalid_column(int& a,int b){
	while(a < 1 || a > b){
		cout << "You entered wrong column. Please try again: ";
		cin >> a;
	}

}

/******************************************************************************
 * Function: invalid_rows(int& a)
 * Parameter: int& a
 * Pre-condition: The input of the user has to be less than 1 and more than 4.
 * Post-condition: This function should be called in the asking_size() function.
 * Description: When the user is determing the size of the showcase, 
 * 			 	 if the user enters a number which is not between 1 and 4,
 * 				 it prompts the user to enter a number between 1 and 4.
 ******************************************************************************/
void invalid_rows(int& a){
	while((a < 1) || (a > 4)){
		cout << "You entered a invalid size of rows. Please try again(1~4): ";
		cin >> a;
	}
}

/******************************************************************************
 * Function: invalid_columns(int& b)
 * Parameter: int& b
 * Pre-condition: The input of the user has to be less than 1 and more than 4.
 * Post-condition: This function should be called in the asking_size() function.
 * Description: when the user is determining the size of the showcase,
 * 				 if the user enters a number which is not between 1 and 4,
 * 				 it propmts the user to enter a number between 1 and 4.
 ******************************************************************************/
void invalid_columns(int& b){
	
	while((b < 1) || (b > 4)){
		cout << "You entered a invalid size of columns. Please try again(1~4): ";
		cin >> b;
	}


}

/***********************************************************************************
 * Function: delete_array(books** arr,int a)
 * Parameters: books** arr,int a
 * Pre-condition: The dynamic 2D array has to be created already.
 * Post-condition: This function should be called in the print_program() function.
 * Description: This function frees the 2D array.
 ***********************************************************************************/
void delete_array(books** arr, int a){
	for(int i = 0;i < a;i++){
		delete [] arr[i];
	}
	delete [] arr;
}

/*****************************************************************************************************************
 * Function: asking_location(int& a,int& b,int c,int d)
 * Parameter: int& a,int& b,int c,int d
 * Pre-condition: The variables for the parameters of the function have to be initiated in int main() function.
 * Post-condition: This function should be called in print_program() function.
 * Description: This funtion asks the user to enter the location of the book 
 * 				 which the user chose in the showcase.
 *****************************************************************************************************************/
void asking_location(int& a, int& b,int c,int d){
	cout << "\e[92mRow:\e[0m ";
	cin >> a;
	invalid_row(a,c);
	cout << "\e[92mColumne:\e[0m ";
	cin >> b;
	invalid_column(b,d);
}

/***********************************************************************************************************************************************
 * Function: print_program(books** arr,int a,int b,int& d,string arr1[],string arr2[],int arr3[],int arr4[],int& e,int& s,int f)
 * Parameters: books** arr,int a,int b,int& c,int& d,string arr1[],string arr2[],int arr3[],int arr4[],int& e,int& s,int f
 * Pre-condition: The 2D array has to be created already.
 * Post-condition: This funciton should be called in int main() function.
 * Description: This function prints out the part of the program. To be specific, it prints out the options and recieve the choice of the user.
 * 				 Moreover, it shows, sells, buys ,and recite the book. Moreover, it updates the change of the showcase.
 ***********************************************************************************************************************************************/
void print_program(books** arr,int a,int b, int& c,int& d,string arr1[],
						 string arr2[],int arr3[],int arr4[],int& e,int& s,int f){

	while(true){
		cout << "Your total value of " << count_items(arr,a,b) << "books: $"
		<< s << " Your bank account: $" << e << endl;
		cout << "1) Show 2)Sell 3)Buy 4)Recite 5)Quit: ";
		cin >> f;
		invalid_choice(f);
		if(f == 5) break;
		asking_location(c,d,a,b);
		show_item(arr,c,d,f);
		sell_item(arr,c,d,f,arr1,arr2,arr3,arr4,e,s);
		buy_item(arr,c,d,f,arr1,arr2,arr3,arr4,e,s);
		recite_item(arr,c,d,f,e);
		print_showcase(arr,a,b);
	}
delete_array(arr,a);
}

/*****************************************************************************************************************
 * Function: asking_size(int& a,int& b)
 * Parametes: int& a,int& b
 * Pre-condition: The variables for the parameters of the function have to be initiated in int main() function.
 * Post-condition: This function should be called in int main() function.
 * Descriptions: This function asks the user to determine the size of the showcase.
 *					  It also detects the invalid input of the user.
 *****************************************************************************************************************/
void asking_size(int& a,int& b){
	cout << "\e[96mEnter Rows:\e[0m ";
	cin >> a;
	invalid_rows(a);
	cout << "\e[96mEnter Columns:\e[0m ";
	cin >> b;
	invalid_columns(b);
}


int main(){

/* I assumed that the title and the author will be more than one character,
 * so string will be sufficient.*/
	string titles[] = {"The Chronicles of Narnia","Harry Potter","The Lord of the Rings","Critik der reinen Vemunft",
							 "The Razor's Blade","Bridge to Terabithia","The Old Man and the Sea","1984",
							 "Logisch-Philosophische","The grapes of Wrath","Surveiller et punir","Sein und Zeit","Capitalism, Socialism, and Democracy",
							 "Cosmos","Guns, Germs, and Steel","Revolutionary Wealth"};
	
	string authors[] = {"C.S. Lewis","J.K. Rowling","J.R.R. Tolken","Immanuel Kant",
							  "W. Somerset Maugham","Katherine Paterson","Ernest Hemingway","George Orwell",
							  "Ludwig Wittgenstein","John Steinbeck","Micha Foucault","Martin Heidegger",
							  "Joseph Schumpeter","Carl Sagan","Jared Diamond","Alvin Toffler"};

/* I assumed that the value of the book and 
 * the publication year of the book will be positive integer,
 * so int (min -2*10^9, max 2*10^9) will be sufficient.*/
	int values[] = {183,223,423,856,314,208,127,328,75,464,318,589,431,365,480,512};
	
	int years[] = {1955,1997,1954,1781,1944,1977,1952,1949,
						1922,1939,1975,1927,1942,1980,1997,2006};

/* I assumed that the rows and the columns of the showcase, total value, 
 * and the money amount in the bank account will be positive integer.
 * So int (min -2*10^9 max 2*10^9) will be sufficient.*/
	int rows = 0, columns = 0, bank = 0, total = 0,choice = 0,row = 0,column = 0;
	
	asking_size(rows,columns);
	
	books** showcase = create_showcase(rows,columns,total,
												  titles,authors,values,years);
	
	print_showcase(showcase,rows,columns);
	
	print_program(showcase,rows,columns,row,column,titles,
					  authors,values,years,bank,total,choice);
	

return 0;
}
