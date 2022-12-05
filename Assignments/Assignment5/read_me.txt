Name: Hyunjae Kim
ONID: kimh6
Section: CS 161
Assignment 5, due 06/01/2020

Description:

This program is about the showcase. You can create a showcase, and determine the size of the showcase. You can sell a book in the showcase, or buy another book to fill the showcase. You can earn money by reciting the book in the showcase. Moreover, you can always check the value of the books in the showcase, and the amount of money in your bank account.

Instructions:

1) Compile the program with

g++ assign5_showcase.cpp -o assign5_showcase

2) Run the showcase with

./assign5_showcase

3) The program will ask you to determine the size of the showcase. You have to know that  the maximum number of rows and columns is 4, and the minimum number of rows and columns is 1. After you determine the size of the showcase, the program will randomly print out the books in the showcase. After printing out the showcase, the program will show you that the total value of the books in the showcase, and the amount of money in your bank account. But you will start the program with $0 bank account. The program will ask 5 choices: show the information of the book, sell a book, buy another book, recite a book, and quit the program. If you chose to sell a book, you will earn money as the value of the book, and the total value will be deducted as the value of the book. Moreover, if you chose to buy another book, you will spend $50, but in the total value of the books will be increase as the amount of value which you bought. However you can only buy another book if there is an empty location in the showcase.

Enter Rows:
Enter Columns:

If you enter numbers between 1 and 4, the program will print out the books randomly in the  showcase that you determined the size.

EX) Enter Rows: 2
	 Enter Columns: 2
	Capitalism, Socialism, and Democracy    The grapes of Wrath
	Logisch-Philosophische  Bridge to Terabithia
	Your total value of 4books: $1178 Your bank acount: $0
	1) Show 2)Sell 3)Buy 4)Recite 5)Quit:

If you select 1, the program will ask you to enter the row and column in order to see the information of the book that you chose.
EX) Row: 1
	 Column: 1
	 Book: |Title: Capitalism, Socialism, and Democracy|Author: Joseph Schumpeter|Value: $431|Publication year: 1942|

If you select 2, the program will ask you to enter the row and column in order to sell the book which you chose.
EX) Row: 1
	 Column: 1
    You sell |Capitalism, Socialism, and Democracy| for $431.
	 __________      The grapes of Wrath
	 Logisch-Philosophische  Bridge to Terabithia
	 Your total value of 3books: $747 Your bank acount: $431
	 1) Show 2)Sell 3)Buy 4)Recite 5)Quit:

If you select 3, the program will ask you to enter the row and column in order to fill another book in that location.
EX)	Row: 1
		Column: 1
		This Location is full! Please try again!
		The Chronicles of Narnia        The Old Man and the Sea
		The Chronicles of Narnia        Logisch-Philosophische
		Your total value of 4books: $568 Your bank acount: $0
		1) Show 2)Sell 3)Buy 4)Recite 5)Quit:
If the showcase is totally full, the program will prompt you to try again.

EX)	__________      The Old Man and the Sea
		The Chronicles of Narnia        Logisch-Philosophische
		Your total value of 3books: $385 Your bank acount: $183
		1) Show 2)Sell 3)Buy 4)Recite 5)Quit: 3
		Row: 1
		Column: 1
		You will be charged $50 for buying a book. Proceed (y/n)? y
		Guns, Germs, and Steel  The Old Man and the Sea
		The Chronicles of Narnia        Logisch-Philosophische
		Your total value of 4books: $865 Your bank acount: $133
		1) Show 2)Sell 3)Buy 4)Recite 5)Quit:
$50 will be deducted from the bank account, but the value of the book will be added to the total value.

If you select 4, you can chose a book that you are going to recite, and earn money.
EX)	Row: 1
		Column: 1
		You recited |Guns, Germs, and Steel| for $300.
		Guns, Germs, and Steel  The Old Man and the Sea
		The Chronicles of Narnia        Logisch-Philosophische
		Your total value of 4books: $865 Your bank acount: $433
		1) Show 2)Sell 3)Buy 4)Recite 5)Quit: 

4) Limitation
	The program sometimes prints out the same book more than one in the showcase. Moreover, the user can't buy the book what the user wants. 

5) Extra Credit
	This program has one new option that allows the user to earn money without selling the book in the showcase. It is 'recite' option. The user can earn $300 if they recite a book in the showcase.




