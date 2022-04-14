#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct customer {
 string id;
 string name;
 string address;
 float deposit;
};

void Menu(char&);
int Search(const customer[], int, int);
void Input(customer[] ,int&);
void ProcessDeposit(customer[] ,int);
void ProcessWithdraw(customer[] ,int);
void ProcessCompound(customer[] ,int);

int main()
{
 customer cus[100];
 int n = 0;
 char select;
 do
 {
  system("cls");
  Menu(select);
  switch(select)
  {
   case '1':Input(cus,n); break;
   case '2':ProcessDeposit(cus,n); break;
   case '3':ProcessWithdraw(cus,n); break;
   case '4':ProcessCompound(cus,n);
  }
 }while(select != '5');
 return 0; 
}

void Menu(char& select)
{
 cout << "Menu" << endl;
 cout << "1.Oepan a new Account" << endl;
 cout << "2.Deposit" << endl;
 cout << "3.Withdraw" << endl;
 cout << "4.Compound interest" << endl;
 cout << "5.Quit" << endl;
 cout << "Please select 1/2/3/4/5 : ";
 cin >> select;
}

int Search(const customer cus[] ,int n, string key)
{
 for(int i = 0; i < n ; i++)
  if(key == cus[i].id)
   return i; //found at i
  return -1; //not found
}

void Input(customer cus[], int& n)
{
 string key;
 cout << "id=?"; cin >> key;
 int index = Search(cus,n,key);
 if(index == -1)
 {
  cus[n].id = key;
  cout << "name=?"; cin >> cus[n].name;
  cout << "address=?"; cin >> cus[n].address;
  cout << "deposit=?"; cin >> cus[n].deposit;
  n++;
  cout << "Suscess:" << endl;
 }
 else
  cout << "Invalid id:" << endl;
 system("pause"); 
}

void ProcessDeposit(customer cus[] ,int n)
{
 string key;
 float money;
 cout << "id=?"; cin >> key;
 int index = Search(cus,n,key);
 if(index == -1)
  cout << "Invalid id:" << endl;
 else
 {
  cout << cus[index].id << "balance="
    << cus[index].deposit << endl;
  cout << "deposit=?"; cin >> money;
  cus[index].deposit += money;
  cout << cus[index].id << "balance="
    << cus[index].deposit << endl;
 }
 system("pause");
}

void ProcessWithdraw(customer cus[] ,int n)
{
 string key;
 float money;
 cout << "id=?"; cin >> key;
 int index = Search(cus,n,key);
 if(index == -1)
  cout << "Invalid id:" << endl;
 else
 {
  cout << cus[index].id << "balance="
    << cus[index].deposit << endl;
  cout << "witdraw=?"; cin >> money;
  if(cus[index].deposit-money < 100.00)
   cout << "Invalid withdraw" << endl;
  else
  {
   cus[index].deposit -= money;
   cout << cus[index].id << "balance="
     << cus[index].deposit << endl;
  }
 }
 system("pause");
}

void ProcessCompound(customer cus[] ,int n)
{
 float interest, rate;
 cout << "rate=?"; cin >> rate;
 cout << setw(5) << "id" << setw(8) << "name" << setw(15) << "deposit"
   << setw(15) << "interest" << setw(15) << "balance" << endl;
 for(int i = 0; i < n; i++)
 {
  cout << setw(5) << cus[i].id;
  cout << setw(8) << cus[i].name;
  cout << fixed << setprecision(2);
  cout << setw(15) << cus[i].deposit;
  cout << fixed << setprecision(4);
  interest = rate / 100 * cus[i].deposit / 365;
  cout << setw(15) << interest;
  cus[i].deposit += interest;
  cout << fixed << setprecision(2);
  cout << setw(15) << cus[i].deposit << endl;
 }
 system("pause");
}
