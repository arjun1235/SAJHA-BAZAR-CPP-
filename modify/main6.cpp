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

char name1[50],ctn1[50];
int age1,cradit1;
float points1=0,mbuy1=0;
		

void craditcard();
void admin();
void user();
void design(int a,char ch)// function is used to design at the top of the screen
{
	cout<<"\n\n\n";
	system("cls");
	cout<<"\t\t\t"<<setw(a+5)<<setfill(ch);
	cout<<"\n\n\t\t\t\t\t"<<"SAJHA BAZAR";
	cout<<"\n\n\t\t\t"<<setw(a)<<setfill(ch);
	cout<<"\n\n";
	}

COORD coord = {0, 0};
void gotoxy(int x, int y) // function is used to set the coordinate in output screen
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

class project // base and main class where almost every thing is done.
{
	protected:
    int itemno ;
    char name[25];
    date d;
public:
    void add()// member function used to add product in file
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
        cout<<"\n\n\tName of the item: ";
        cin>>name;
        cout<<"\n\n\tManufacturing Date(dd-mm-yy): ";
        cin>>d.mm>>d.dd>>d.yy;
    }
    
       void show()// used to display product on screen
    {
        cout<<"\n\tItem identification  No: ";
        cout<<itemno;
        cout<<"\n\n\tName of the item: ";
        cout<<name;
        cout<<"\n\n\tDate : ";
        cout<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
    }
    int retno()// used to calculate grand total amount
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

class amount: public project// derived class of base class project
{
	protected:
    float mrp,price,qty,tax,gross,dis,iamt,tqty,total;
public:
    void add();
    void show();
    void pay();
    void pay1(int ,int);
    void refille();
    void edt();
    void report();
    void del(int);
    void report1();
    void surv();
    float retiamt()
    {
    	return (iamt);
	}
    void qnt(int a)
      {
      	qty=a;
	  }
	  
	  float rettotal()
	  {
	  	return (total);
	  }
	int retnum()
	{
		return (retno());
	}

    
} amt;
void amount::add()// used to add numerical part of product to file
{
    project::add();
    cout<<"\n\n\t cost Price: ";
    cin>>price;
    cout<<"\n\n\tMark price";
    cin>>mrp;
    cout<<"\n\n\tQuantity: ";
    cin>>qty;
    tqty=qty;
    cout<<"\n\n\tTax percent: ";
    cin>>tax;
    cout<<"\n\n\tDiscount percent: ";
    cin>>dis;
    gross=mrp+(mrp*(tax/100));
    iamt=(gross-(gross*(dis/100)));
    total=iamt*qty;
    //profit=(iamt-price)*qty;
    fout.write((char *)&amt,sizeof(amt));
    fout.close();
}

void amount::edt()
{
	project::uadd();
	cout<<"\n\n\t cost Price: ";
    cin>>price;
    cout<<"\n\n\t Mark Price: ";
    cin>>mrp;
    cout<<"\n\n\tTax percent: ";
    cin>>tax;
    cout<<"\n\n\tDiscount percent: ";
    cin>>dis;
    gross=mrp+(mrp*(tax/100));
    iamt=(gross-(gross*(dis/100)));
	total=iamt*qty;	
}

void amount::del(int d)// used to delete unwanted product.
{
           flag=0;
           int ino=d;
           fin.close();
           cout << "this is a try"<<ino;
            fstream tmp("temp.dat",ios::binary|ios::out);
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
            getch();
}
void amount::refille()// used to add number of goods when it is about to empty.
{
		
    	refi: design(45,'*');
        int inum,quanti;
        cout <<"\t\t\t\n Enter the item identification number:";
        cin>>inum;

        
        int  pos;
        char ans1,ans2;
	fstream fio;
	  	fio.open("itemstore.dat",ios::in|ios::out|ios::binary);
	 if(!fio)
        {
            cout<<"\n\nFile Not Found...\nProgram Terminated!";
        }
	int ans=0;       
	fio.seekg(0);
	while(fio.read((char*)&amt,sizeof(amt)))
	{
		pos=fio.tellg();
		
		if(inum==amt.project::retno())
		{	
			ans++;		
			cout<<endl<<"Input the quantity to be added"<<endl;
			cin>>quanti;
			fio.seekg(pos-sizeof(amt));
			qty+=quanti;
			total=qty*iamt;
			tqty=qty;
			fio.write((char*)&amt,sizeof(amt));			
		}
	}
	if (ans==0)
	{
		cout<<endl<<"You entered invalid choice";
		cout<<endl<<"Do you wish to add quantity (Y/N)";
		cin>>ans1;		
	}
	if (ans1=='y'||ans1=='y')
	goto refi;
	cout<<endl<<"do you want add other products(Y/N)";
	cin>>ans2;
	if (ans2=='y'||ans2=='y')
	goto refi;
	
	fio.close();  
}


void amount::show()//used to show numerical portion of product
{
    fin.open("itemstore.dat",ios::binary);
    fin.read((char*)&amt,sizeof(amt));
    project::show();
    cout<<"\n\n\tindividual amount:";
    cout<<iamt;
    cout<<"\n\n\t quantity : ";
    cout<<qty;

    //cout<<"\n\n\tNet profit: ";
    //cout<<profit;
    fin.close();
}

void amount::pay()// shows full detail of product in bill formate
{
    show();
    cout<<"\n\n\n\t\t*********************************************";
    cout<<"\n\t\t                 DETAILS                  ";
    cout<<"\n\t\t*********************************************";
    cout<<"\n\n\t\tCOST PRICE                :Rs."<<price;
    cout<<"\n\n\t\tMARK PRICE				 :Rs."<<mrp; 	
    cout<<"\n\n\t\tQUANTITY                     :"<<qty;
    cout<<"\n\t\tTAX PERCENTAGE                 :"<<tax;
    cout<<"\n\t\tDISCOUNT PERCENTAGE            :"<<dis;
    cout<<"\n\t\tSELLING PRICE               :Rs."<<iamt;
    cout<<"\n\n\n\t\tprofit                  :Rs."<<qty*(iamt-price);
    cout<<"\n\t\t----------------------------------------------";
    cout<<"\n\t\t*********************************************";
}

void amount::surv()
{
	float a=10*tqty/100;		
	if (qty<a)
	{
		cout<<endl;
		cout<<endl<<"You need to add: ";
		project::show();
		cout<<endl<<"\tRemaining: "<<qty;		
		cout<<endl;
		cout<<endl;
	}
	else
	{
		cout<<endl<<"You dont need to add";
		project::show();
		cout<<endl<<"\tRemaining: "<<qty;		
		cout<<endl;
		cout<<endl;
		}	
}

void amount::report()
{
    project::report();
    gotoxy(23,k);
    cout<<price;
    gotoxy(33,k);
    cout<<mrp;
    gotoxy(44,k);
    cout<<qty;
    gotoxy(52,k);
    cout<<tax;
    gotoxy(64,k);
    cout<<dis;
    gotoxy(74,k);
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
        cout<<" SELLING PRICE";

    }
}


int main()
{
	int ch;
    float gtotal;
        cout<<"\n \t\t\t=============================================================\n";
        cout<<"\n\t\t\t\t\tWELCOME TO SAJHA BAZAR  \n";
        cout<<"\n \t\t\t=============================================================\n\n";
        cout<<"\n\n\n\n\t\t\t\t\t  Project members are:";
        cout<<"\n\n\t\t\t\t Name\t\t\t\tRoll.no";
		cout<<"\n\t\t\t\t Arjun Chhetri\t\t\ttha075bei007";
		cout<<"\n\t\t\t\t Shovit Nepal\t\t\ttha075bei040";
		cout<<"\n\t\t\t\t Suraj Agrahari\t\t\ttha075bei043";
		cout<<"\n\t\t\t\t Sushovan Shakya\t\ttha075bei046";
		getch();
	while(1)
	{
		menu:
		    std::string password,again;
		static int tryd=3;
		design(45,'*');
		cout<<"\n\t\t\t  1. VIEW/GENERATE CUSTOMER ID ";
        cout<<"\n\t\t\t  2. ADMIN ";
        cout<<"\n\t\t\t  3. USER ";
        cout<<"\n\t\t\t  4. EXIT ";
        cout<<"\n\t\t\t Enter Your choice: ";
        cin>>ch;
        switch(ch)
        {
        	case 1:
        		craditcard();
        		break;
            case 2:
            	if(tryd>=1)
            	{
            		done:	cout <<"\n\n\n\t\t\t\tEnter the password for Admin : ";
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
						cout<<"\n\n\n\t\t\t Do you want to try again (y/n) ? ";
						cin>>again;
						if(again=="y"||again=="Y")
						goto done;
					}
					break;
				}
				}
				else
				cout<<"\n\n\n\t\t\t Password try limit exceeded.";
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

class costumer
{
	protected:
		char name[50],ctn[50];
		int age,cradit;
		float points,mbuy;
		public:
			void cal()
			{ 
			
				if(points1<points)
				{
					cout<<"aayo 1";
					strcpy(name1,name);
					strcpy(ctn1,ctn);
					age1=age;
					cradit1=cradit;
					points1=points;
					mbuy1=mbuy;
				}
			 }
			 
			 		
			
			int retcradit()
			{
				return cradit;
			}
			void getdata()
			{
				cout<<endl<<"input name of costumer:";
				cin>>name;
				cout<<endl<<"input citizenship no.: ";
				cin>>ctn;
				cout<<endl<<"input age:";
				cin>>age;
				calculation();
			}
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
	
			void display()
		{
			cout<<endl<<"\t Name: "<<name;
			cout<<endl<<"\t Citizenship no.: " <<ctn;
			cout<<endl<<"\t Age: "<<age;
			cout<<endl<<"\t Credit card no. is: "<<cradit;
			cout<<endl<<"\t money used: " <<mbuy;
			cout<<endl<<"\t points: "<<points;
		}
		void calc(int,int, int);
}co;

void admin()
{

    adm: design(45,'*');
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout<<setprecision(2);
    fstream tmp("temp.dat",ios::binary|ios::out);
    int option ;
    cout << "\t\t\t 1. Add product \n ";
    cout << "\t\t\t 2. View desired product details \n ";
    cout << "\t\t\t 3. View product \n ";
    cout << "\t\t\t 4. Delete \n ";
    cout << "\t\t\t 5. Edit \n ";
    cout << "\t\t\t 6. Refill \n ";
    cout << "\t\t\t 7. Survey \n ";
    cout << "\t\t\t 8. Gift dinu prne \n ";
    cout << "\t\t\t 9. Return to main menu \n ";
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
            cout<<" Do you want to add more item(y/n) ?\n";
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
        cout<<"\n\n\t\tEnter Item  identification Number : ";
        cin>>ino;
        fin.open("itemstore.dat",ios::binary);
        if(!fin)
        {
            cout<<"\n\nFile Not Found...\nProgram Terminated!";
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
             goto adm;
           break;
       }

       case 3:
       {
           design(45,'*');
            gotoxy(34,3);
            cout<<" <<  BILL DETAILS >> ";
            gotoxy(1,5);
            cout<<"ITEM ID ";
            gotoxy(13,5);
            cout<<"NAME";
            gotoxy(23,5);
            cout<<"COST PRICE";
            gotoxy(33,5);
            cout<<"MRP";
            gotoxy(44,5);
            cout<<"QUANTITY";
            gotoxy(52,5);
            cout<<"TAX %";            
            gotoxy(64,5);
            cout<<"DISCOUNT %";
			gotoxy(74,5);
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
            k=7;
            while(!fin.eof())
            {
                fin.read((char*)&amt,sizeof(amt));
                if(!fin.eof())
                {
                    amt.report();
                    gtotal+=amt.rettotal();
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
            dele: cout<<"\n\n\tEnter Item Number to be deleted :";
            cin>>ino;
            //cout <<"\n\n\t Item to be deleted is :";
            //amt.show();
            char choice;
            cout<<" Do you want to delete this item(y/n) ?\n";
            cin >> choice;
            if(choice =='y'||choice =='Y')
            {
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
                cout<<"\n\t\t Item Successfully Deleted";
            else if (flag==0)
                cout<<"\n\t\t Item does not Exist! Please Retry";
                char choice;
            cout<<"\n\t Do you want to delete  more item (y/n) ?";
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
            else
            goto dele;
       }
       case 5:
       {
       	
       	//++++++++++++++++++++++++++++++++++++++++++++++++++++++
       	edta: design(45,'*');
        int inum,quanti;
       cout<<"\n\n\tEnter Item Number to be edited :";
        cin>>inum;

        
        int  pos;
        char ans1,ans2;
	fstream fio;
	  	fio.open("itemstore.dat",ios::in|ios::out|ios::binary);
	 if(!fio)
        {
            cout<<"\n\nFile Not Found...\nProgram Terminated!";
        }
	int ans=0;       
	fio.seekg(0);
	while(fio.read((char*)&amt,sizeof(amt)))
	{
		pos=fio.tellg();
		
		if(inum==amt.project::retno())
		{	
			ans++;		
			//cout<<endl<<"Input the quantity to be added"<<endl;
			//cin>>quanti;
			fio.seekg(pos-sizeof(amt));
		//	qty+=quanti;
		amt.edt();
			fio.write((char*)&amt,sizeof(amt));	
					
		}
	}
	
	if (ans==0)
	{
		cout<<endl<<"You entered invalid choice";
		cout<<endl<<"Do you wish to edait (Y/N)";
		cin>>ans1;		
	}
	if (ans1=='y'||ans1=='y')
	goto edta;
	cout<<endl<<"do you want edit other products(Y/N)";
	cin>>ans2;
	if (ans2=='y'||ans2=='y')
	goto edta;
	

	 goto adm;
				break;
  
}
       	//++++++++++++++++++++++++++++++++++++++++++++++++++++
       		
        case 6:
       {
       	amt.refille();
		  goto adm;    
       }
        case 7:
       {
       	
       		 fin.open("itemstore.dat",ios::binary);
       		
       		while(fin.read((char*)&amt,sizeof(amt)))
       		{       		
       			amt.surv();      			
			}
			fin.close();			
          getch();
		  goto adm;
       }
       case 8:
       {    
	   fin.open("itemstore.dat",ios::binary);
       		
       		while(fin.read((char*)&amt,sizeof(amt)))
       		{       			
       			co.cal();     						      			
			}
			fin.close();			
          	

			cout<<endl<<"\t Name: "<<name1;
			cout<<endl<<"\t Citizenship no.: " <<ctn1;
			cout<<endl<<"\t Age: "<<age1;
			cout<<endl<<"\t Credit card no. is: "<<cradit1;
	//		cout<<endl<<"\t money used: " <<mbuy1;
	//		cout<<endl<<"\t points: "<<points1;
		     		
		
          getch();
		  goto adm;
       	
          break;
       }
       case 9:
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




//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void costumer::calc(int a,int b,int c)
{
	int crad=a;	
	int quantity=b;
	int choice=c;
	float po,buy;
		
	 fin.open("itemstore.dat",ios::binary);
    while(fin.read((char*)&amt,sizeof(amt)))
    {
    	if(choice==amt.project::retno())
    	{    
    		float d=amt.retiamt();  
		 	//===========================================================
			 int  pos;
	fstream fio;
	fio.open("costumer.txt",ios::in|ios::out|ios::binary);
	while(fio.read((char*)&co,sizeof(co)))
	{
		pos=fio.tellg();
		
		if(crad==cradit)
		{			
			fio.seekg(pos-sizeof(co));
					buy=d*quantity;
					mbuy+=buy;
					float e=2*d/100;
					po=e*quantity;			
					points+=po;	
			fio.write((char*)&co,sizeof(co));			
		}
		}			 		
		fio.close(); 
		}		  	   	
	} 	
    fin.close();    
}



void craditcard()
{
fstream em;
char ch;
design(45,'*');
gotoxy(1,5);
cout<<"\n Do you want to create credit card no. (y/n) ? ";
cin>>ch;
em.open("costumer.txt",ios::app|ios::out|ios::in);
while(ch=='y'||ch=='Y')
{
 		co.getdata();
 		em.write(reinterpret_cast<char*>(&co),sizeof(co));
	cout<<"\n Do you want to create more credit card no. (y/n) ? ";
	cin>>ch;
}
	em.close();
	 //em.seekg(0);
		 //	em.read(reinterpret_cast<char*>(&co),sizeof(co));
            cout<<"\n\t\t============================================================";
		 	cout<<"\n\t\t\t\t     The credit card detail:";
		 	 cout<<"\n\t\t============================================================\n";
			

	 em.open("costumer.txt",ios::app|ios::out|ios::in);
		 	em.read(reinterpret_cast<char*>(&co),sizeof(co));
		 	while(!em.eof())
		 	{
		 		co.display();
		 		cout<<endl<<endl;
				em.read(reinterpret_cast<char*>(&co),sizeof(co));
			 }	
			 getch();
			 em.close();
}

//=========================================================for grnereting bill============
class bill: public costumer,public amount
{
	protected:
	int craditcr, idcr,price,sale;
	char nam[50],ctn[50],prodnam[50];
	public:	
		void set(int a,int b)
		{
			
			strcpy(prodnam,project::name);
			strcpy(nam,costumer::name);
			strcpy(ctn,costumer::ctn);
			craditcr= costumer::cradit;
			idcr=project::itemno;
			price=a*amount::iamt ;
			sale=9912345;
		}
		void disp()
		{
			cout<<endl<<craditcr;
			cout<<endl<<idcr;
			cout<<endl<<price;
			cout<<endl<<sale;
			cout<<endl<<nam;
			cout<<endl<<ctn;
			
		}
		void billcalc(int,int,int);
}cr;

void bill::billcalc(int a,int b,int c)
{
	int crdta=a;
	int quantity=b;       
	int idno=c;
	//+++++++++++++++++++++++++++++++++++++++
	fstream em,eima,eimb;
	em.open("bill.txt",ios::app|ios::out|ios::binary|ios::in);
	eima.open("costumer.txt",ios::app|ios::out|ios::binary|ios::in);
	eimb.open("itemstore.dat",ios::app|ios::out|ios::binary|ios::in);	
	eima.seekg(0);
	if(!em)
       	{
   			cout<<"\n\nFile Not Found...\nProgram Terminated!";         
		}
		//eima.read(reinterpret_cast<char*>(&co),sizeof(co))
		while(eima.read(reinterpret_cast<char*>(&co),sizeof(co)))
	{			
	cout<<"loop2";
	int ac=co.retcrad();
		if(crdta==ac)
		{
			cout<<"loop 1"<<endl;			
			eimb.seekg(0);				
		//	eimb.eof()==0				
		//	eimb.read(reinterpret_cast<char*>(&amt),sizeof(amt))
			while(!eimb.eof())
			{
			//	cout<<"out 2";
				int ab=amt.retnum();
				if(idno==ab)
				{
					set(quantity,crdta);				
					em.write(reinterpret_cast<char*>(&cr),sizeof(cr));	
					cout<<endl<<"loop 3"<<endl;
					
					cr.disp();		
					break ;
				}
				//break ;	
			}			
		break ;	
		}		
	}	
	em.close();
	eima.close();
	eimb.close();
	
		
	getch();
		
}
//====================================buy wala==================================
   void amount::report1()
{
    project::report();
    gotoxy(23,k);
    cout<<mrp;
    gotoxy(33,k);
    cout<<qty;
    gotoxy(44,k);
    cout<<tax;
    gotoxy(52,k);
    cout<<dis;
    gotoxy(68,k);
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
    getch(); cout<<"\n\n\t\tinput the quantity you want to buy ";
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
	//	cr.billcalc(crd,quantity,choice);
		co.calc(crd,quantity,choice);
		
}

//=============================================================

   void user()
   {
	design(45,'*');
	int idc=0;
	char ans;
	cout<<endl<<"\n\t\t Do you have credit no.(y/n) ? ";
	cin>>ans;
	if(ans=='y'||ans=='Y')
	{
		cout<<endl<<" Input your credit number : ";
		cin>>idc;
	}
      bgoto:design(45,'*');
            gotoxy(39,3);
            cout<<" BILL DETAILS ";
            gotoxy(1,5);
            cout<<"ITEM ID";
            gotoxy(13,5);
            cout<<"NAME";
            gotoxy(23,5);
            cout<<"MRP";
            gotoxy(33,5);
            cout<<"QUANTITY";
            gotoxy(44,5);
            cout<<"TAX %";
            gotoxy(52,5);
            cout<<"DISCOUNT %";
            gotoxy(68,5);
            cout<<"PRICE";
            fin.open("itemstore.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
            }
            fin.seekg(0);
            k=7;
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
            //int choice=1;
          fstream em("itemstore.dat",ios::binary|ios::app|ios::out|ios::in);
    		//while(choice!=0)
                int choice;
				cout<<"\n Input the product's identification no. you want to buy :";
				cin>>choice;
				if(!em)
        {
            cout<<"\n\nFile Not Found...\nProgram Terminated!";
           // break;
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

        //cout<<"\n press 0 to exit or any thing to continue";
        //cin>>choice;
        //*************************************************
        //char ans;
        cout<<"\n\n press Y to continue and N to exit ? ";
            cin >> ans;
        if(ans =='y'||ans =='Y')
            {
                goto bgoto;
            }
            else
            getch();
            em.close();



			 }


