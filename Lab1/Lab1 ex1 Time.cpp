#include <iostream>
using namespace std;

int main() {
	int h,m,s,tr;
	cout <<"Please enter time\n";
	cout <<"HH:mm:ss\n";
	cout <<"Hour : ";
	cin >> h;
	cout <<"Minute : ";
	cin >> m;
	cout <<"Second : ";
	cin >> s;
	cout <<h<<":"<<m<<":"<<s<<endl;
	tr = (h*3600)+(m*60)+s;
	cout <<"Convert time to seconds : "<<tr<<" Second";
}
