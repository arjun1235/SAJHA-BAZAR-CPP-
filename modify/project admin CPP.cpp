#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include <cstring>
#include<stdio.h>
#include <conio.h>
using namespace std;
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
	int ch;
        cout<<"\n \t\t\t=============================================================\n";
        cout<<"\n\t\t\t\t\tWELCOME TO SAJHA BAZAR  \n";
        cout<<"\n \t\t\t=============================================================\n\n";
        cout<<"\n\n\n\n\t\t\t\tProject members are:";
        cout<<"\n\n\t\t\t Name\t\t\t\tRoll.no";
		cout<<"\n\t\t\t Arjun Chhetri\t\t\ttha075bei007";
		cout<<"\n\t\t\t Shovit Nepal\t\t\ttha075bei040";
		cout<<"\n\t\t\t Suraj Agrahari\t\t\ttha075bei043";
		cout<<"\n\t\t\t Sushovan Shakya\t\ttha075bei046";
		getch();
	while(1)
	{
		 
		std::string password,again;
		static int tryd=3;
		design(45,'*');
        cout<<"\n\t\t\t  1. ADMIN";
        cout<<"\n\t\t\t  2. USER";
        cout<<"\n\t\t\t  3. EXIT";
        cout<<"\n\t\t\t Enter Your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
            	if(tryd>=1)
            	{
            		done:	cout <<"\n\n\n\t\t\t\tenter the password for admin:";
            		cin>>password;
            	
            		if(password=="admin")
            	{
            		cout<<"done bro";
            		//  admin();
            		getch();
              	 	break;
				}
				else
				{
					tryd--;
					design(50,'*');
					if(tryd>=1)
					{
						cout<<"\n\n\n\t\t\tWrong password you have "<<tryd<<" chances left:";
						cout<<"\n\n\n\t\t\t Do you want to try again (yes/no)";
						cin>>again;
						if(again=="yes"||again=="YES")
						goto done;				
					}
					break;
				}
				}
				else
				cout<<"\n\n\n\t\t\t Passowrd try limit exceeded";
				getch();
            	break;
								
              case 2:
              //  user();
              cout<<"\n\n\t\t\t\tfor user";
                break;
                
            case 3:
                exit(0);
            	break;
	        default:
                cout<<"\n\n\n\n\t\t\t\t\tEnter valid choice\n";
                getch();
				break;
        	    }
    }
    return 0;
}

