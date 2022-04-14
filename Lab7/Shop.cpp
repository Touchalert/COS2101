#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct product {
 string id;
 string name;
 float cost;
 int instock;
};

struct Sell {
 string id;
 string name;
 float cost;
 int peice;
 float amount;
};

void Menu(char& );
int Search(const product[] ,int ,string);
void Input(product[] ,int&);
void SellItem(product[], int);
void CheckStock(product[] ,int);
void Reorder(const product[], int);

int main()
{
 product item[100];
 int n = 0;
 char select;
 cout << fixed << setprecision(2);
 do{
  system("cls");
  Menu(select);
  switch(select)
  {
   case '1':Input(item,n); break;
   case '2':SellItem(item,n); break;
   case '3':CheckStock(item,n); break;
   case '4':Reorder(item,n); 
  }
 }while(select != '5');
 return 0;
}

void Menu(char& select)
{
 cout << "Menu" << endl;
 cout << "1.Add item to Cart" << endl;
 cout << "2.Sell product" << endl;
 cout << "3.Check stock" << endl;
 cout << "4.Reorder" << endl;
 cout << "5.End program" << endl;
 cout << "Please select 1/2/3/4/5 : ";
 cin >> select;
}

int Search(const product item[] ,int n, string key)
{
 for(int i = 0; i < n ; i++)
  if(key == item[i].id)
   return i; //found at i
  return -1; //not found
}

void Input(product item[], int& n)
{
 string key;
 char repeat; int num;
 do {
  cout << "id=?"; cin >> key;
  int index = Search(item,n,key);
  if(index == -1) //new product
   {
    cout << "New product:" << endl;
    item[n].id = key;
    cout << "name=?"; cin >> item[n].name;
    cout << "cost="; cin >> item[n].cost;
    cout << "instock="; cin >> item[n].instock;
    n++;
   }
  else //add stcok
  {
   cout << item[index].id << "instock="
     << item[index].instock << endl;
   cout << "peice=?"; cin >> num;
   item[index].instock += num;
   cout << item[index].id << "instock="
     << item[index].instock << endl;
  }
  cout << "Repeat Y/N?"; cin >> repeat; 
 }while(repeat == 'Y'|repeat == 'y');
}

void SellItem(product item[], int n)
{
 string key;
 char repeat;
 Sell order[10];
 int p = 0;
 float total = 0.0;
 do {
  cout << "id=?"; cin >> key;
  int index = Search(item,n,key);
  if(index == -1)
   cout << "Invalid id:" << endl;
  else
  {
   int num = 0;
   cout << item[index].id << "instock="
     << item[index].instock << endl;
   do{
    cout << "peice=?"; cin >> num;
   }while(num > item[index].instock);
   item[index].instock -= num;
   cout << item[index].id << "instock="
     << item[index].instock << endl;
   order[p].id = item[index].id;
   order[p].name = item[index].name;
   order[p].cost = item[index].cost;
   order[p].peice = num;
   order[p].amount = num * item[index].cost;
   total += order[p].amount;
   p++;
  }
  cout << "Repeat Y/N?"; cin >> repeat;
 }while(repeat == 'Y'|repeat == 'y');
 cout << "Total = " << total << " THB" << endl << endl;
 system("pause");
}

void CheckStock(product item[], int n)
{
 product temp;
 int row,col;
 for(row = 0; row < n - 1; row++)
 {
  for(col = row + 1; col < n; col++)
   if(item[row].instock > item[col].instock)
   {
    temp = item[row];
    item[row] = item[col];
    item[col] = temp;
   }
 }
 cout << "instcok id name" << endl;
 for(int i = 0; i < n; i++)
  cout << setw(4) << item[i].instock << setw(10)
    << item[i].id << setw(10)
    << item[i].name << endl;
    system("pause");
 }
 
void Reorder(const product item[], int n)
{
 cout << endl << "REORDER" << endl << endl;
 cout << "instock     id    name" << endl;
 for(int i = 0; i < n; i++){
 if(item[i].instock < 50)
   cout << setw(4) << item[i].instock << setw(10) << item[i].id
     << setw(7) << item[i].name << endl;      
 }
 system("pause");
}
