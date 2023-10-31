#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include <cstring>
#include<stdio.h>
#include <conio.h>
#include<fstream>
#include<windows.h>
#include<cstdio>
#include<time.h>
using namespace std;

class costumer
{
	protected:
		char name[50],ctn[50];
		int age,cradit,points,mbuy;
		public:
			void calculation()
			{
				 srand( time(NULL) );
   				 int number = (rand() % 9000)+1000;
				  cradit=number;
				  
			}
			void getdata()
			{
				cout<<endl<<"iput name of costumer:";
				cin>>name;
				cout<<endl<<"input citizenship no.: ";
				cin>>ctn;
				cout<<endl<<"input age:";
				cin>>age;
				calculation();
			}
			
			void display()
		{
			cout<<"\n the details are:";
			cout<<endl<<"Name: "<<name;
			cout<<endl<<"citizenship no.: " <<ctn;
			cout<<endl<<"age: "<<age;
			cout<<endl<<"cradit card no is: "<<cradit;
		}
}co;

int main()
{
fstream em;
char ch;
cout<<"\n do you want to create cradit card no. (y/n) ";
cin>>ch;
em.open("costumer.txt",ios::app|ios::out|ios::in);
while(ch=='y'||ch=='Y')
{	
 		co.getdata();
 		em.write(reinterpret_cast<char*>(&co),sizeof(co));
	cout<<"\n do you want to create more cradit card no. (y/n) ";
	cin>>ch;
}
	 em.seekg(0);
		 	em.read(reinterpret_cast<char*>(&co),sizeof(co));
		 	while(!em.eof())
		 	{
		 		co.display();
				em.read(reinterpret_cast<char*>(&co),sizeof(co));
			 }	
	}
