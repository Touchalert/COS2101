#include <iostream>
using namespace std;

int main() {
    int n;
    double fac1 = 0.0;
	double fac2 = 2.0;
	double sum = 0;
	
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0)
        cout << "Error! Result of a negative number doesn't exist.";
    else {
        for(int i = 1; i <= n; ++i) {
            fac1 += 1;
            fac2 += 1;            
			sum += (fac1/fac2);
            cout << "( " << fac1 <<" / " << fac2 << " )";
            if(i < n){
            	cout << " + ";
			} else {
				cout << " = " << sum;
			}
        }
        cout << "\nSUM( " << n << " ) = " << sum;    
    }

    return 0;
}
