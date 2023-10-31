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

int k=7,r=0,flag=0;
ofstream fout;
ifstream fin;
void craditcard();
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
      void uadd()
    {
        cout<<"\n\n\tItem user id No: ";
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
    float price,qty,tax,gross,dis,netamt,iamt,quanti;//profit;
public:
	int retnum()
	{
		return (retno());
	}
   void add();
    void show();
     void pay();
     void pay1(int ,int);
     // void pay1(int);
     //void report1();
     void refill();
      void report();
      void report1();
       void qnt(int a)
      {
      	qty=a;
	  }
      
	   float retnetamt()
    {
         return(netamt);
    }
} amt;
void amount::add()
{
    project::add();
    cout<<"\n\n\t cost Price: ";
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
void amount::refill()
{
    cout<<"\t\t\t\n enter the number of goods you want to add :";
    cin >>quanti;
    quanti=quanti+qty;
    qty = quanti;
    cout<<"\t\t\t\n now you have :"<<qty<<"  numbers of goods";
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
    cout<<"\n\n\t quantity : ";
    cout<<quanti;

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
    cout<<"\n\n\t\tCOST PRICE                  :"<<price;
    cout<<"\n\n\t\tQUANTITY                    :"<<qty;
    cout<<"\n\t\tTAX PERCENTAGE              :"<<tax;
    cout<<"\n\t\tDISCOUNT PERCENTAGE         :"<<dis;
    cout<<"\n\t\tSELLING PRICE               :Rs."<<iamt;
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
    gotoxy(80,k);
    cout<<netamt;
    gotoxy(64,k);
    cout<<iamt;
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
        gotoxy(80,5);
        cout<<"NET AMOUNT";
        gotoxy(64,5);
        cout<<" SELLING PRICE";

    }
}
/*void amount::report1()
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
}*/


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
		cout<<"\n\t\t\t  1.Generate/view cradit card no.";
        cout<<"\n\t\t\t  2. ADMIN";
        cout<<"\n\t\t\t  3. USER";
        cout<<"\n\t\t\t  4. EXIT";
        cout<<"\n\t\t\t Enter Your choice: ";
        cin>>ch;
        switch(ch){
        	case 1:
        		craditcard();
        		break;
            case 2:
            	if(tryd>=1)
            	{
            		done:	cout <<"\n\n\n\t\t\t\tenter the password for admin:  ";
            		cin>>password;

            		if(password=="admin")
            	{

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
						cout<<"\n\n\n\t\t\t Do you want to try again (y/n)  ";
						cin>>again;
						if(again=="y"||again=="Y")
						goto done;
					}
					break;
				}
				}
				else
				cout<<"\n\n\n\t\t\t Passowrd try limit exceeded";
				getch();
            	break;

              case 3:
               user();
                break;

            case 4:
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
     adm: design(45,'*');
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout<<setprecision(2);
    fstream tmp("temp.dat",ios::binary|ios::out);
    int option ;
   cout << "\t\t\t 1. Add product \n ";
   cout << "\t\t\t 2. View dersired product details \n ";
   cout << "\t\t\t 3. View product \n ";
   cout << "\t\t\t 4. delete \n ";
   cout << "\t\t\t 5. edit \n ";
   cout << "\t\t\t 6. refill \n ";
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
            goto adm;
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
             goto adm;
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
            //getch();
             goto adm;
           break;
       }

       case 3:
       {
           design(45,'*');
            gotoxy(34,3);
            cout<<" <<  BILL DETAILS >> ";
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
            gotoxy(80,5);
            cout<<"NET AMOUNT";
            gotoxy(64,5);
            cout<<"SELLING PRICE";
            fin.open("itemstore.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                 goto adm;
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
             goto adm;
           break;
       }
       case 4:
       {
           view2: design(45,'*');
           flag=0;
           int ino;
            cout<<"\n\n\tEnter Item Number to be deleted :";
            cin>>ino;
            fin.open("itemstore.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
            }
            fin.seekg(0);
            while(fin.read((char*)&amt, sizeof(amt)))
            {
                int x=amt.project::retno();
                if(x!=ino)
                    tmp.write((char*)&amt,sizeof(amt));
                else
                {
                    flag=1;
                }
            }
            fin.close();
            tmp.close();
            fout.open("itemstore.dat",ios::trunc|ios::binary);
            fout.seekp(0);
            tmp.open("temp.dat",ios::binary|ios::in);
            if(!tmp)
            {
                cout<<"Error in File";
            }
            while(tmp.read((char*)&amt,sizeof(amt)))
                fout.write((char*)&amt,sizeof(amt));
            tmp.close();
            fout.close();
            if(flag==1)
                cout<<"\n\t\tItem Succesfully Deleted";
            else if (flag==0)
                cout<<"\n\t\tItem does not Exist! Please Retry";
                char choice;
            cout<<"\n\t do you want to view more item (y/n) ?";
            cin >> choice;
        if(choice =='y'||choice =='Y')
            {
                goto view2;
            }
            else
            getch();
             goto adm;
            break;
       }
       case 5:
       {
           view3: design(45,'*');
           int ino;
            flag=0;
            cout<<"\n\n\tEnter Item Number to be Edited :";
            cin>>ino;
            fin.open("itemstore.dat",ios::binary);
            fout.open("itemstore.dat",ios::binary|ios::app);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                goto adm;
            }
            fin.seekg(0);
            r=0;
            while(!fin.eof())
            {
                fin.read((char*)&amt,sizeof(amt));
                if(!fin.eof())
                {
                    int x=amt.project::retno();
                    if(x==ino)
                    {
                        flag=1;
                        fout.seekp(r*sizeof(amt));
                        system("cls");
                        cout<<"\n\t\tCurrent Details are\n";
                        amt.show();
                        cout<<"\n\n\t\tEnter New Details\n";
                        amt.add();
                        cout<<"\n\t\tItem Details editted";
                        char choice;
            cout<<"\n\t do you want to view more item (y/n) ?";
            cin >> choice;
        if(choice =='y'||choice =='Y')
            {
                goto view3;
            }
            else
            getch();
             goto adm;
                    }
                }
                r++;
            }
            if(flag==0)
            {
                cout<<"\n\t\tItem No does not exist...Please Retry!";
                getch();
                goto adm;
            }
            fin.close();
            getch();
           break;
       }
        case 6:
       {
           design(45,'*');
           int inum,quanti;
           cout <<"\t\t\t\nenter the item identification number:";
           cin>>inum;

           fout.open("itemstore.dat",ios::binary|ios::app);
           fin.open("itemstore.dat",ios::binary|ios::app);
        if(!fin)
        {
            cout<<"\n\nFile Not Found...\nProgram Terminated!";
        }
        fin.seekg(0);
        while(fin.read((char*)&amt,sizeof(amt)))
        {
            int x=amt.project::retno();
            if(x==inum)
            {
                amt.refill();

                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"\n\t\tItem does not exist....Please Retry!";
        getch();
        fin.close();
           cout << " \t\t\t\n under construction";
           getch();
            goto adm;
           break;
       }
        case 7:
       {
          break;
       }
        default:
                cout<<"\n\n\n\n\t\t\t\t\tEnter valid choice\n";
                getch();
                 goto adm;
				break;
        }

   }
      //==================================My portion==========================================
   //========================================cradit create===========================
	

class costumer
{
	
		char name[50],ctn[50];
		int age,cradit,mbuy;
		float points;
		public:
			void calculation()
			{
				 srand( time(NULL) );
   				 int number = (rand() % 9000)+1000;
				  cradit=number;
				  
			}
			int retcrad()
			{
				return cradit;
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
			
			cout<<endl<<"Name: "<<name;
			cout<<endl<<"citizenship no.: " <<ctn;
			cout<<endl<<"age: "<<age;
			cout<<endl<<"cradit card no is: "<<cradit;
		}
}co;

void craditcard()
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
		 	cout<<"\n the details are:";
			 while(!em.eof())
		 	{
		 		co.display();
				em.read(reinterpret_cast<char*>(&co),sizeof(co));
				cout<<endl<<endl;
			 }	
			 getch();
}
//=========================================================for grnereting bill============			 
class bill: public costumer,public amount
{	
int numa;
	public:
		void numb()
		{
			numa=50;
		}
		int retid()
		{
			amount::retnum();
		}
		int retcradit()
		{
			costumer::retcrad();
		}
		void billcalc(int,int,int);
}cr;

void bill::billcalc(int a,int b,int c)
{
	int crdta=a;
	int quantity=b;       
	int idno=c;
	fstream em,eima,eimb;
	em.open("bill.txt",ios::app|ios::out|ios::in);
	eima.open("costumer.txt",ios::app|ios::out|ios::binary|ios::in);
	eimb.open("itemstore.dat",ios::binary|ios::app);	
	eima.seekg(0);

	if(crdta!=0)
	{
		while(eima.read(reinterpret_cast<char*>(&co),sizeof(co)))
	{			
	int ac=co.retcrad();
		if(crdta==ac)
		{
			cout<<"vai aaayo 1"<<endl;
			amt.qnt(quantity);
			eimb.seekg(0);								
			while(eimb.eof()==0)
			{
				cout<<"out 2";
				int ab=amt.retnum();
				if(idno==ab)
				{
					if(!em)
       				 {
            			cout<<"\n\nFile Not Found...\nProgram Terminated!";         
        			 }
	
				//	cr.numb();
					em.write(reinterpret_cast<char*>(&cr),sizeof(cr));	
					cout<<endl<<"vai dimag kharab vo"<<endl;
			
					break ;
				}
				//break ;	
			}			
		break ;	
		}
		
	}
		
	}
	em.close();
	eima.close();
	eimb.close();
	cout<<"vai yeha summa ta aayo aru tha xina";
	getch();
		
}
//====================================buy wala==================================
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

void amount::pay1(int c,int a)
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
		int crd=a;
		cr.billcalc(crd,quantity,choice);
//	if(crd!=0)
//	{
//		cr.billcalc(crd,quantity);
//	}
}

//=============================================================

   void user()
   {
	design(45,'*');
	int idc=0;
	char ans;
	cout<<endl<<"do you have cradit no.(y/n)";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
		cout<<endl<<"input your cradit no.";
		cin>>idc;
	}
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
                amt.pay1(choice,idc);
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
            
         
            em.close();
   }

