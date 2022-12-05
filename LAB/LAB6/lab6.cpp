/********************************************************************************************
 * Program: lab6.cpp
 * Author: Hyunjae Kim
 * Date: 05/05/2020
 * *****************************************************************************************/



#include <iostream>
using namespace std;

void count_punctuation(string s, int& n_periods){
  n_periods = 0;

	for(int i = 0;i < s.length();i++){
				if(s[i] == '.')
				n_periods++;
				}
}

void count_punctuation2(string s, int* n_periods){
	*n_periods = 0;
	
	for(int i = 0;i < s.length();i++){
				if(s[i] == '.')
				(*n_periods)++;
				}

}
int main(){
	int raw_fish = 10;
	int& sashimi = raw_fish;

	cout << raw_fish << endl;
	cout << sashimi << endl;

	int num = 0;

	cout << "Enter: ";
	string s1;
	cin >> s1;
	count_punctuation(s1,num);
   cout << "< " << s1 << " > " << num << " periods." << endl;

	count_punctuation2(s1,&num);
	cout << "< " << s1 << " > " << num << " periods." << endl;

	short* cookie = new short;
	*cookie = 47;
	delete cookie;
	cookie =  NULL;

	int* ice_cream = new int;
	*ice_cream = 10;
	delete ice_cream;
	ice_cream = NULL;
 

	float* water = new float;
	*water = 55;
	delete water;
	water = NULL;

	return 0;
}
