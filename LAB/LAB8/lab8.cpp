/***************************************************************
 * Program: lab8.cpp
 * Date: 05/19/2020
 * Author: Hyunjae Kim
 * ************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


void print_house(int a[3][4]){
	for(int x = 0;x<3;x++){
		for(int y = 0;y<4;y++){
			cout << a[x][y] << "\t";
		
		}
		cout << endl;
	
	}


}


int** create_house(int x, int y){
	srand(time(NULL));
	int** f = new int*[x];
	for(int i = 0;i<x;i++){
	
			f[i] = new int[y];
	}
	for(int a = 0;a < x;a++){
		for(int b = 0;b < y;b++){
			f[a][b] = rand()%10+1;
		
		}
	
	}
return f;
}




void print_house2(int** a,int nx,int ny){
	for(int x = 0; x <nx;x++){
		for(int y =0;y < ny;y++){
		
			cout << a[x][y] << "\t";
		
		}
		cout << endl;
	}


}

struct bottle{
	string color;
	int volume;

};

int main(){
	srand(time(NULL));
	int city_house[3][4];
	for(int x = 0;x < 3;x++){
		for(int y = 0; y < 4;y++){
			city_house[x][y] = rand()%10+1;
		}
	}
	print_house(city_house);

	int size_x = 0,size_y=0;
	cout << "Please Enter a number: ";
	cin >> size_x;
	cout << "Please Enter a number: ";
	cin >> size_y;
	int** city_house2 = create_house(size_x,size_y);
	
	/*int** city_house2 = new int*[size_x];
	for(int x = 0;x < size_x;x++){
	city_house2[x] = new int[size_y];
	
	}
	for(int x = 0;x < size_x;x++){
		for(int y = 0;y < size_y;y++){
			city_house2[x][y] = rand()%10+1;
			cout << city_house2[x][y] << "\t";
		}
		cout << endl;
	}*/
	print_house2(city_house2,size_x,size_y);
	for(int x = 0; x < size_x;x++){
		delete [] city_house2[x];
	}
	delete [] city_house2;
	
	bottle my_bottle[3];
	int max = 0;
	for(int i = 0;i < 3;i++){
		cout << "Enter color for bottle " << i+1 << ": ";
		cin >> my_bottle[i].color;
		cout << "Enter volume for bottle " << i+1 << ": ";
		cin >> my_bottle[i].volume;
	
	} 
	for(int i = 0;i < 3;i++){
		if(my_bottle[i].volume > my_bottle[max].volume){
			max = i;
		}
	}
	cout << "The larges bottle is bottle " << max+1 << "has a volume " << my_bottle[max].volume << "L and is " << my_bottle[max].color << ".";
	
return 0;
}
