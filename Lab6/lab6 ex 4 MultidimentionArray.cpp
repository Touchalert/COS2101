#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main() 
{
	int rowA, colA, rowB, colB, rowC, colC, size;
	cout <<"Enter the size of the matrix(A) & matrix(B) :\n" ;
	cin >> size;
	rowA = size; colA = size;
	rowB = size; colB = size;
	rowC = size; colC = size;
	
	int A[rowA][colA];
	int B[rowB][colB];
	int C[rowC][colC];
	
	//input MatrixA
	cout << "Enter the elements of the matrix(A):\n";
	for (rowA = 1; rowA <= size; rowA++) {
		for (colA = 1; colA <= size; colA++){
		cout << "Enter Row "<< rowA << " Enter Column " << colA <<" :\n";
		cin >> A[rowA][colA];	}
	}
	cout<<"Matrix A is:"<<endl;

	//output MatrixA
	for (rowA = 1; rowA <= size; rowA++) {
      	for (colA = 1; colA <= size; colA++)
    cout << A[rowA][colA] <<" ";
    cout<<endl; }
    
    //input MatrixB
	cout << "Enter the elements of the matrix(B):\n";
	for (rowB = 1; rowB <= size; rowB++)
		for (colB = 1; colB <= size; colB++){
		cout << "Enter Row "<< rowB << " Enter Column " << colB <<" :\n";
		cin >> B[rowB][colB];
	}
	
	//output MetrixB
	cout<<"Matrix B is:"<<endl;
	for (rowB = 1; rowB <= size; rowB++) 
	{
      	for (colB = 1; colB <= size; colB++)
    cout << B[rowB][colB] <<" ";
    cout<<endl; }
    
    //Process MatrixA * MatrixB
    for ( rowC =1; rowC <= size; rowC++)
    { 
		for (colC = 1; colC <= size; colC++){
			C[rowC][colC] = 0;
			for (int k = 1; k<= size; k++){
				C[rowC][colC] += A[rowC][k] * B[k][colC];
			}
		} 
	}
	
	//Output Result A*B=C
	cout<<"Matrix A * Matrix B is :"<<endl;
		for (rowC = 1; rowC <= size; rowC++) 
	{
      	for (colC = 1; colC <= size; colC++)
    cout << C[rowC][colC] <<" ";
    cout<<endl; }
    
}
