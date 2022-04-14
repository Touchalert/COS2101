#include <iostream>
using namespace std;

int main()
{
    int base,i,pow2=1,pow3=1,pow4=1;
    cout << "Enter Base value : ";
    cin >> base;
    
    for(i=1;i<=2;i++)
    {
       pow2 = pow2 * base;                   
    }    
    cout << "Result Exponent value 2 is : " << pow2<<endl;
    for(i=1;i<=3;i++)
    {
       pow3 = pow3 * base;                   
    }    
    cout << "Result Exponent value 3 is : " << pow3<<endl;;
    for(i=1;i<=4;i++)
    {
       pow4 = pow4 * base;                   
    }    
    cout << "Result Exponent value 4 is : " << pow4;

   
    return 0;
}
