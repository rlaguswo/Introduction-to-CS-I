/**********************************************************************************************************************************
 * Program: assign1_fortune.pp
 * Author: Hyunjae Kim
 * Date: 04/06/2020
 * Description: This program predicts your fortune or future events that you don't know. Your fortune can be good or bad.
 * I would use a  double for distance and weight of gold, which gives me a range of values from -1.8*10^308 to 1.8*10^308.
 * I would use a short for today's temperature, whigh gives me a range of values from -3.4*10^38 to 3.4*10^38.
 * I would use a unsigned long for the value of money and the number of boxes, which gives me a range of values from 0 to 18*10^18i.
 ***********************************************************************************************************************************/
#include<string>
#include<iostream>
using namespace std;   /*so we don't have to write std::cout.*/

float rate(double money_km, double  distance_walk){   /*This calculates $/km in the second fortune based on the number that the user entered.*/
 return money_km/distance_walk;
}

int main(){
 /* I assumed that the value of  distance, weight,and money can be really large and include decimals,
 * so double (min -1.8*10^308, max 1.8*10^308) will be sufficient.*/
 double distance_walk, weight_gold, money_km;

 /* I assumed that the value of temperature can be positive or negative whole numbers , 
  * but the scale that I think about
  * temperature is smaller than the value of distance, weight, and money.
  * So short (min -32768, max 32767) will be sufficient.*/
 short  today_temperature;

/* I assumed that number of boxes are always positive
 * and can be really large,
 * so unsigned long (min 0, max 18*10^18) will be sufficient.*/
 unsigned long  number_boxes;

 /************************************************not initialized. User will fill in.************************************************************************/

 cout << "What is your first name? ";
/* I wanted to put the user's name in the fortune in order to give much more fun to the user. So I used string.*/
 string your_firstname;
 cin >> your_firstname;
 cout << "Please enter a number that you want:";
 cin >> today_temperature;
 cout << "Today's temperature is " << today_temperature <<"Celsius." << endl;
                                   
/*I wanted to give more detail about the temperature that the user entered. So I used if.*/

 if( today_temperature > 30){

 cout << "Today is really hot!" << endl;

}
 else if(-273< today_temperature <0){

 cout << "Today is really cold!" << endl;

}
 else if ( today_temperature < -273){            /* The reason is that the lowest temperature is 0K(-273Celsius degree).*/
 cout << "Error!" << endl;
}

 cout << "Please enter two positive numbers including decimals that you want :";
 cin >> money_km;
 cin >> distance_walk;
 cout << your_firstname <<" will earn $" << money_km << " if " << your_firstname <<" walks " << distance_walk << "km." << endl
 << "The rate of money that " << your_firstname <<" will earn is $" << rate(money_km,distance_walk)<<"/km." << endl;
 
 cout << "Please enter two  positive two numbers that you want:";
 cin >> number_boxes;
 cin >> weight_gold;
 cout << your_firstname << " will discover "<< number_boxes<<"boxes which is filled with " << weight_gold << "kg of gold." << endl;






return 0;

}
 
