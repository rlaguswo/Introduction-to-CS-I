#include <iostream>
using namespace std;

bool is_even(int num){
	
	if(num%2==0)
		return true;
	
	else
		return false;
}

int product(int num1,int num2){
	return num1*num2;
}
int main(){

	int a,b,c;
	cout << "Enter a number: ";
	cin >> a;
	cout <<is_even(a) << endl;
	cout << "Enter two numbers: ";
	cin >> b;
	cin >> c;
	cout << product(b,c) << endl;



return 0;
}


