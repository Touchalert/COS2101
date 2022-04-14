#include <iostream>
using namespace std;

int main() {
	int money;
	cout << "Enter money for change : ";
	cin >> money;
	if(money >= 1000){
		cout<<"1000 Bath = "<<(money/1000);
		money=money%1000;
	}if(money >= 500) {
		cout<<"\n500 Bath = "<<(money/500);
		money=money%500;
	}if(money >= 100) {
		cout<<"\n100 Bath = "<<(money/100);
		money=money%100;
	}if(money >= 50) {
		cout<<"\n50 Bath = "<<(money/50);
		money=money%50;
	}if(money >= 20) {
		cout<<"\n20 Bath = "<<(money/20);
		money=money%20;
	}if(money >= 10) {
		cout<<"\n10 Bath = "<<(money/10);
		money=money%10;
	}if(money >= 5) {
		cout<<"\n5 Bath = "<<(money/5);
		money=money%5;
	}if(money >= 2) {
		cout<<"\n2 Bath = "<<(money/2);
		money=money%2;
	}if(money >= 1) {
		cout<<"\n1 Bath = "<<(money/1);
	}
	return 0;
}
