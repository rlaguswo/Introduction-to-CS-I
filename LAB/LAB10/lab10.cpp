#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string pal(char a){
	if(a == 'A')
		return "A";
	else{
		return pal(a-1)+a+pal(a-1);
	}


}

int main(){
	char a;
	string c;
	const char b = 'B';
	do{
	cout << "Enter: ";
	cin >> a;
	}while(a < 'A' || a > 'Z');
	cout << pal(a) << endl;

	ofstream out_stream;
	//out_stream.open("my_text.txt");
	cout << "What is your new file?";
	cin >> c;
	rename("my_text.txt",c);
	out_stream.open(c);
//	out_stream << "My name is Hyunjae." << endl;
//	out_stream << pal(b) << endl;
	
//	out_stream.close();



return 0;
}
