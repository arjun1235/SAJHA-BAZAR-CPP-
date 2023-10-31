#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include <cstring>
#include<stdio.h>
#include <conio.h>
using namespace std;
void admin();
void design(int a,char ch)
{
	cout<<"\n\n\n";
	system("cls");
	cout<<"\t\t\t"<<setw(a+5)<<setfill(ch);
	cout<<"\n\n\t\t\t\t\t"<<"Sajha Bazar";
	cout<<"\n\n\t\t\t"<<setw(a)<<setfill(ch);
	cout<<"\n\n";
	}

int main()
{
	admin();
	return (0000);
}
void admin()
{
	int i;
	design(56,'@');
	cout<<"\n\n\n\n\n\t\t\t\t\tWELCOME ADMIN";
	getch();
	while(1)
	{
		design(56,'@');
	cout<<"\n\n\n\n\n\t\t\t\t\tChoose your option";
	cout<<"\n\n\t\t\t\t\t1.Add product";
	cout<<"\n\n\t\t\t\t\t2.Survey the product";
	cout<<"\n\n\t\t\t\t\t3.View bill";
	cout<<"\n\n\t\t\t\t\t4.Choose best costumer";
	cout<<"\n\n\t\t\t\t\t5.Choose costumer of the year";
	cout<<"\n\n\t\t\t\t\t6.Return to the main window\n\n\t\t\t\t\t\t";
	cin>>i;
	switch (i)
		{
			case 1:
				break;
				
			case 2:
					break;
			
			case 3:
				break;
						
			case 4:
				break;
			
			case 5:
				break;
				
			case 6:
				exit(0);
				break;
							
		}
	
	}
		
			
	
}
