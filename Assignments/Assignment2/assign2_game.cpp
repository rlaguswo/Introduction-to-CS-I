/*********************************************************************************************************************************************************************************
 * Program: assign2_game.cpp
 * Author: Hyunjae Kim
 * Description: This is a game that offer the choices in oder to complete the game.Player can see 3 different ending of the game. 
 *              One is drinking coffee, and the other is getting autograph of famous athlete or taking photo with a famous athlete. 
 *              If the player haveinvalid choices, it asks the player to play again or not. 
 *              And if the player chooses to play again, it goes back to the first step of the game.
 *              Or if the player chooses not to play again, it quits the game.
 *              If the player completed the game, plater can choose to play again or not. 
 *              If the player chooses to play again, it goes back to the first step of the game.
 *              Or if the player chooses not to ply again, it quits the game.
 ********************************************************************************************************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main(){
/* I assumed that players will enter simple numbers like positive numbers or decimals,
 * so float (min -3.4*10^38 max 3.4*10^38) will be sufficient.*/
float choice1 = 0;
float choice1_1 = 0;
float choice1_2 = 0;

/*I assumed that the scores are only +7 and -4
 *so int (min -2*10^9, max 2*10^9) will be sufficient.*/
int scores=0;

/*I assumed that the numbers of menu, autography, and photo are  positive whole numbers and they are less than 10,
 * so unsigned  short (min 0, max 65535) will be sufficient.*/
unsigned short  menu1,menu2, menu3,  numbers_autography, numbers_photo;

/*I assumed that choosing again or not will be typing 'y' or 'n',
 * so char (min -128, max 127) will be sufficient.*/
char yes_no = 'y';

srand(time(NULL));

cout << "Enter your nickname: ";
string your_name; /*I used string in order to store player's name.*/
cin >> your_name;

do{

cout <<your_name << " saw a cafe on the street." <<  your_name <<"  will "<<endl << "1.enter a cafe." << endl << "2.pass a cafe." << endl;
cin >> choice1;

if(choice1 == 1){
	
		cout <<"\e[0mMenu: a.Americano b.Cafe Latte c.Espresso d.Affogato" << endl
   	<< your_name << "  is in a cafe." << your_name << "  will say"<< endl << "1.Can I order one cup of coffee?" << endl 
		<< "2.Give me coffee!" << endl << "3.Can I order hamburger?" << endl;
   
		cin >> choice1_1;
	 
		if(choice1_1 == 1 ){
				scores+=7;
				menu1 = rand()%4+1;
				switch(menu1){ /*This prints out the menu randomly.*/
					case 1:
						cout << your_name << " ordered Americano.\n" << endl;
						break;
					case 2:
						cout<< your_name << " ordered Cafe Latte.\n" << endl;
						break;
					case 3:
						cout << your_name << " ordered Espresso.\n" << endl;
						break;
					case 4:
						cout << your_name << " ordered Affogato.\n" << endl;
						break;
					default:
						return 1; /*This default is a safeguard when I modify the program.*/
				}
				cout << your_name << " gains 7 points for a score of " << scores << "points.\n" << endl;
			}
 	   
		else if( choice1_1== 2){
				scores-=4;
				menu2= rand()%4+1;
				switch(menu2){ /*This prints out the menu randomly.*/
					case 1:
						cout << your_name << " ordered Americano.\n" << endl;
						break;
					case 2:
						cout << your_name << " ordered Cafe Latte.\n" << endl;
						break;
					case 3:
						cout << your_name << " ordered Espresso.\n" << endl;
						break;
					case 4:
						cout << your_name << " ordered Affogato.\n" << endl;
						break;
					default: 
						return 1; /*This default is a safeguard when I modify the program.*/
				
				}
				cout << your_name << "  loses 4 points for a score of " << scores << "points.\n" << endl;
		 	}	
	   
		else if(choice1_1== 3){
			  scores-=4;
			  cout << your_name << ", we don't have hamburger. We only have coffee. What coffee would you like to drink?" << endl;
			  menu3= rand()%4+1;
			  switch(menu3){ /*This prints out the menu randomly.*/
			  	case 1:
					cout << your_name << " ordered Americano.\n" << endl;
					break;
				case 2:
					cout << your_name << " ordered Cafe Latte.\n" << endl;
					break;
				case 3:
					cout << your_name << " ordered Espresso.\n" << endl;
					break;
				case 4:
					cout << your_name << " ordered Affogato.\n" << endl;
					break;
				default:
					return 1; /*This default is a safeguard when I modify the program.*/
			  }
			 
			  cout << your_name << " loses 4 points for a score of " << scores << "points.\n" << endl;
		
		
		}
	  
		/*If the player had invalid choice, 
		* it allows the plyer to quit the game or play the game again.*/ 
		else { 
		cout << "Game over! Invalid Choice. Play again?(y/n) ";
			   cin >> yes_no;
		
		}
 	
		cout << your_name << "  ordered coffee, but you are short of money. You will" << endl 
		<< "1.Cancel the order." << endl << "2.Cancel the order and reorder much cheaper one." << endl 
		<< "3.Use coffee coupon.\n" << endl;
	 
		cin >> choice1_2;
	
		if(choice1_2 == 1){
			scores-=4;
			cout << your_name << " fails to drink coffee!" << endl
			<< your_name << " loses 4 points for a score of " << scores << "points.\n" << endl
			<< your_name << "'s final scores are " << scores<< "points.\n" << endl;
			cout << your_name << " completed the game.\n" << endl;
			cout << "Play again?(y/n) ";
			cin >> yes_no;
		}

	   else if(choice1_2 == 2 || choice1_2 == 3){
			scores+=7;
			cout << your_name << " successes to drink coffee!." << endl
			<< your_name << "  gains 7 points for a score of " << scores << "points.\n" << endl
		   << your_name << "'s final scores are " << scores << "points.\n" << endl;
			cout << your_name << " completed the game.\n" << endl;
			cout << "Play again?(y/n) ";
			cin >> yes_no;
		
		}
		
		/*If the player had invalid choice at the paht1 second question,
		 *it allows the player to quit the game or play the game again.*/
		else{
		 cout << "Game Over! Invalid choice! Play again?(y/n): ";
		 cin >> yes_no;

		}
		
	}
 
else if(choice1 == 2){
  	cout << your_name <<"  saw a famous athlete on the street. " 
  	<< your_name <<"  will" << endl << "1.Ignore and go home." << endl 
  	<< "2.ask autographs." << endl << "3.ask taking photos." << endl;
  
  	cin >> choice1_1;
  
  	if(choice1_1 == 1){
		scores-=4;
		cout << your_name << " arrives home." << endl
	   << your_name <<  " loses 4 points for a score of " << scores << "points.\n" << endl
		<< your_name << "'s final scores are " << scores << "points.\n" << endl
		<< your_name << " completed the game. Play again?(y/n) ";
		cin >> yes_no;
 		 	}
   
  	else if(choice1_1 == 2){
		scores+=7;
		numbers_autography = rand()%5+1;
		cout << your_name << " gets " << numbers_autography << " autography." << endl
		<< your_name << "  gains 7 points for a score of" << scores << "points.\n" << endl
		<< your_name << "'s final scores are " << scores << "points.\n" << endl;
		cout << your_name <<  " completed the game. Play again?(y/n) ";
		cin >> yes_no;

			} 
  
 	 else if(choice1_1 == 3){
  		scores+=7;
		numbers_photo = rand()%6+1;
		cout << your_name << " gets " << numbers_photo << " photo(s) with famous athlete." << endl
		<< your_name << " gains 7 points for a score of " << scores << "points.\n" << endl
		<< your_name << "'s final scores are " << scores << "points.\n" << endl;
		cout << your_name <<  " completed the game.\n "<< endl <<" Play again?(y/n) ";
		cin >> yes_no;
  			}
  
  	/*if the player had invalid choice at the path2 question, 
	 * it allows the player to quit the game or play the game again.*/
  	else{	   
 		cout << "Game Over! Play again?(y/n) ";
		cin  >> yes_no;
 	  		}	
	  }
	

/*If the player had invalid choice at the first choice. 
 * It allows the player to quit the game or play the game again.*/
else{
	cout << "Game Over! Invalid Choice. Play again?(y/n) ";
	cin >> yes_no;
		}

}while(yes_no=='y');/*It loops if the yes_no is equal to 'y'.*/


return 0;
}
