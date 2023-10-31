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
using namespace std;

int k=7,r=0,flag=0;
ofstream fout;
ifstream fin;

void admin();
void user();

void design(int a,char ch)
{
	cout<<"\n\n\n";
	system("cls");
	cout<<"\t\t\t"<<setw(a+5)<<setfill(ch);
	cout<<"\n\n\t\t\t\t\t"<<"Sajha Bazar";
	cout<<"\n\n\t\t\t"<<setw(a)<<setfill(ch);
	cout<<"\n\n";
	}

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

	struct date
{
    int mm,dd,yy;
};

class project
{
    int itemno ;
    char name[25];
    date d;
public:
    void add()
    {
        cout<<"\n\n\tItem identification No: ";
        cin>>itemno;
        cout<<"\n\n\tName of the item: ";
        cin>>name;
        cout<<"\n\n\tManufacturing Date(dd-mm-yy): ";
        cin>>d.mm>>d.dd>>d.yy;
    }
       void show()
    {
        cout<<"\n\tItem identification  No: ";
        cout<<itemno;
        cout<<"\n\n\tName of the item: ";
        cout<<name;
        cout<<"\n\n\tDate : ";
        cout<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
    }
    int retno()
    {
        return(itemno);

    }
    void report()
    {
        gotoxy(3,k);
        cout<<itemno;
        gotoxy(13,k);
        puts(name);
    }
};

class amount: public project
{
    float price,qty,tax,gross,dis,netamt,iamt;//profit;
public:
    void add();
    void show();
     void pay();
     void pay1(int);
     void report1();
        void report();
         float retnetamt()
    {
        return(netamt);
    }
} amt;
void amount::add()
{
    project::add();
    cout<<"\n\n\tPrice: ";
    cin>>price;
    cout<<"\n\n\tQuantity: ";
    cin>>qty;
    cout<<"\n\n\tTax percent: ";
    cin>>tax;
    cout<<"\n\n\tDiscount percent: ";
    cin>>dis;
    gross=price+(price*(tax/100));
    iamt=(gross-(gross*(dis/100)));
    //profit=(iamt-price)*qty;
    netamt=qty*(gross-(gross*(dis/100)));
    fout.write((char *)&amt,sizeof(amt));
    fout.close();

}
void amount::show()
{
    fin.open("itemstore.dat",ios::binary);
    fin.read((char*)&amt,sizeof(amt));
    project::show();
    cout<<"\n\n\tindividual amount:";
    cout<<iamt;
    cout<<"\n\n\tNet amount: ";
    cout<<netamt;
    //cout<<"\n\n\tNet profit: ";
    //cout<<profit;
    fin.close();
}
void amount::pay()
{
    show();
    cout<<"\n\n\n\t\t*********************************************";
    cout<<"\n\t\t                 DETAILS                  ";
    cout<<"\n\t\t*********************************************";
    cout<<"\n\n\t\tPRICE                       :"<<price;
    cout<<"\n\n\t\tQUANTITY                    :"<<qty;
    cout<<"\n\t\tTAX PERCENTAGE              :"<<tax;
    cout<<"\n\t\tDISCOUNT PERCENTAGE         :"<<dis;
    cout<<"\n\t\tINDIVIDUAL AMOUNT           :Rs."<<iamt;
    // cout<<"\n\n\n\t\tprofit             :Rs."<<profit;
    cout<<"\n\t\t----------------------------------------------";
    cout<<"\n\n\t\tNET AMOUNT                :Rs."<<netamt;
    cout<<"\n\t\t*********************************************";
}
void amount::report()
{
    project::report();
    gotoxy(23,k);
    cout<<price;
    gotoxy(33,k);
    cout<<qty;
    gotoxy(44,k);
    cout<<tax;
    gotoxy(52,k);
    cout<<dis;
    gotoxy(64,k);
    cout<<netamt;
    k=k+1;
    if(k==50)
    {
        gotoxy(25,50);
        cout<<"PRESS ANY KEY TO CONTINUE...";
        getch();
        k=7;
        system("cls");
        gotoxy(30,3);
        cout<<" ITEM DETAILS ";
        gotoxy(3,5);
        cout<<" ID NUMBER";
        gotoxy(13,5);
        cout<<"NAME";
        gotoxy(23,5);
        cout<<"PRICE";
        gotoxy(33,5);
        cout<<"QUANTITY";
        gotoxy(44,5);
        cout<<"TAX";
        gotoxy(52,5);
        cout<<"DEDUCTION";
        gotoxy(64,5);
        cout<<"NET AMOUNT";
    }
}

int main()
{
	int ch;
    float gtotal;
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
		menu:
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
            	      design(45,'*');
                      admin();

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
               user();
                break;

            case 3:
                design(45,'*');
                 gotoxy(20,15);
        cout<<"ARE YOU SURE, YOU WANT TO EXIT (Y/N)?";
        char yn;
        cin>>yn;
        if((yn=='Y')||(yn=='y'))
        {
            design(45,'*');
            gotoxy(20,15);
            cout <<"|=======================================================================|";
            gotoxy(20,16);
            cout<<"|********************************THANKS*********************************|";
            gotoxy(20,17);
            cout <<"|=======================================================================|";
            getch();
            exit(0);
        }
            else if((yn=='N')||(yn=='n'))
            goto menu;
            else
        {
            goto menu;
        }


              break;
	        default:
                cout<<"\n\n\n\n\t\t\t\t\tEnter valid choice\n";
                getch();
				break;
        	    }
    }
    return 0;
}

void admin()
{
     cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout<<setprecision(2);
    fstream tmp("temp.dat",ios::binary|ios::out);
    int option ;
   cout << "\t\t\t 1. Add product \n ";
   cout << "\t\t\t 2. View cart \n ";
   cout << "\t\t\t 3. View bill \n ";
   cout << "\t\t\t 4. Survey the product \n ";
   cout << "\t\t\t 5. Choose the best costumer \n ";
   cout << "\t\t\t 6. Choose costumer of the month  \n ";
   cout << "\t\t\t 7. Return to main menu \n ";
   cout << "\t\t\t enter your option :\n ";
   cin  >> option ;
    float gtotal;
    int ff;
   switch(option)
   {
       case 1:
       {
           design(45,'*');
            add1: fout.open("itemstore.dat",ios::binary|ios::app);
            amt.add();
            cout<<"\n\t\tItem Added Successfully!";
            char choice;
            cout<<" do you want to add more item(y/n) ?\n";
            cin >> choice;
            if(choice =='y'||choice =='Y')
            {
                goto add1;
            }
            else
            getch();
           break;
       }
       case 2:
       {
           design(45,'*');
         view1: flag=0;
        int ino;
        cout<<"\n\n\t\tEnter Item  identification Number :";
        cin>>ino;
        fin.open("itemstore.dat",ios::binary);
        if(!fin)
        {
            cout<<"\n\nFile Not Found...\nProgram Terminated!";
            //goto menu;
            break;
        }
        fin.seekg(0);
        while(fin.read((char*)&amt,sizeof(amt)))
        {
            int x=amt.project::retno();
            if(x==ino)
            {
                amt.pay();
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"\n\t\tItem does not exist....Please Retry!";
        getch();
        fin.close();
        char choice;
            cout<<"\n\t do you want to view more item (y/n) ?";
            cin >> choice;
        if(choice =='y'||choice =='Y')
            {
                goto view1;
            }
            else
            getch();
           break;
       }
       case 3:
       {
           design(45,'*');
            gotoxy(30,3);
            cout<<" BILL DETAILS ";
            gotoxy(1,5);
            cout<<"ITEM ID NO. ";
            gotoxy(13,5);
            cout<<"NAME";
            gotoxy(23,5);
            cout<<"PRICE";
            gotoxy(33,5);
            cout<<"QUANTITY";
            gotoxy(44,5);
            cout<<"TAX %";
            gotoxy(52,5);
            cout<<"DISCOUNT %";
            gotoxy(64,5);
            cout<<"NET AMOUNT";
            fin.open("itemstore.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                //goto menu;
                break;
            }
            fin.seekg(0);
            gtotal=0;
            while(!fin.eof())
            {
                fin.read((char*)&amt,sizeof(amt));
                if(!fin.eof())
                {
                    amt.report();
                    gtotal+=amt.retnetamt();
                    ff=0;
                }
                if(ff!=0) gtotal=0;
            }
            gotoxy(17,k);
            cout<<"\n\n\n\t\t\tGrand Total="<<gtotal;
            getch();
            fin.close();
           break;
       }
       case 4:
       {
           design(45,'*');
           cout << " \t\t\t under construction ";
           break;
       }
       case 5:
       {
           design(45,'*');
           cout << " \t\t\t under construction";
           break;
       }
        case 6:
       {
           design(45,'*');
           cout << " \t\t\t under construction";
           break;
       }
        case 7:
       {
          break;
       }
        default:
                cout<<"\n\n\n\n\t\t\t\t\tEnter valid choice\n";
                getch();
				break;
        }

   }
   //==================================My portion==========================================
   void amount::report1()
{
    project::report();
    gotoxy(23,k);
    cout<<price;
    gotoxy(33,k);
    cout<<qty;
    gotoxy(44,k);
    cout<<tax;
    gotoxy(52,k);
    cout<<dis;
    gotoxy(64,k);
    
    k=k+1;
    if(k==50)
    {
        gotoxy(25,50);
        cout<<"PRESS ANY KEY TO CONTINUE...";
        getch();
        k=7;
        system("cls");
        gotoxy(30,3);
        cout<<" ITEM DETAILS ";
        gotoxy(3,5);
        cout<<" ID NUMBER";
        gotoxy(13,5);
        cout<<"NAME";
        gotoxy(23,5);
        cout<<"PRICE";
        gotoxy(33,5);
        cout<<"QUANTITY";
        gotoxy(44,5);
        cout<<"TAX";
        gotoxy(52,5);
        cout<<"DEDUCTION";     
    }
}

void amount::pay1(int c)
{
	design(45,'*');
	
    fin.read((char*)&amt,sizeof(amt));
    project::show();
    cout<<"\n\n\n\t\t*********************************************";
    cout<<"\n\t\t                 DETAILS                  ";
    cout<<"\n\t\t*********************************************";
    cout<<"\n\n\t\tPRICE                       :"<<price;
    cout<<"\n\n\t\tQUANTITY                    :"<<qty;
    cout<<"\n\t\tTAX PERCENTAGE              :"<<tax;
    cout<<"\n\t\tDISCOUNT PERCENTAGE         :"<<dis;
    cout<<"\n\t\tINDIVIDUAL AMOUNT           :Rs."<<iamt;
    cout<<"\n\t\t*********************************************";
    getch(); cout<<"\n\n\t\tinput the quantity you want to buy";
     int quantity;
    cin>>quantity;
 //===================================================================
int choice=c;
int  pos;
	fstream fio;

	fio.open("itemstore.dat",ios::in|ios::out|ios::binary);

	
	while(fio.read((char*)&amt,sizeof(amt)))
	{
		pos=fio.tellg();

		if(choice==amt.project::retno())
		{			
			fio.seekg(pos-sizeof(amt));
			qty-=quantity;
			fio.write((char*)&amt,sizeof(amt));			
		}
	}
	fio.close();  
}

   
   void user()
   {
design(45,'*');
            gotoxy(30,3);
            cout<<" BILL DETAILS ";
            gotoxy(1,5);
            cout<<"ITEM ID NO. ";
            gotoxy(13,5);
            cout<<"NAME";
            gotoxy(23,5);
            cout<<"PRICE";
            gotoxy(33,5);
            cout<<"QUANTITY";
            gotoxy(44,5);
            cout<<"TAX %";
            gotoxy(52,5);
            cout<<"DISCOUNT %";
            fin.open("itemstore.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                 }
            fin.seekg(0);
              while(!fin.eof())
            {
                fin.read((char*)&amt,sizeof(amt));
                if(!fin.eof())
                {
                    amt.report1();                
                }                
            }
            gotoxy(17,k);
            getch();
            fin.close();
            //;;;;;;;;;;;;;;;;;;;;;;;;;;;'''''''''''''''''''''''''''''
            int choice=1;
            fstream em("itemstore.dat",ios::binary|ios::app|ios::out|ios::in);
    		while(choice!=0) 
			{
				cout<<"\ninput the product's identification no. you want to buy";
				cin>>choice;
				if(!em)
        {
            cout<<"\n\nFile Not Found...\nProgram Terminated!";           
            break;
        }
        em.seekg(0);
        while(em.read((char*)&amt,sizeof(amt)))
        {
            int x=amt.project::retno();
            if(x==choice)
            {
                amt.pay1(choice);
                //=====================================================================
                
       		    //=======================================================================
				   flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"\n\t\tItem does not exist....Please Retry!";
        getch();
        
        cout<<"\n press 0 to exit or any thing to continue";
        cin>>choice;
        	
			 } 
            
            getch();
            em.close();
   }

