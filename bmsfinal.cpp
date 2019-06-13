#include<fstream>
#include <iostream>
#include <string>
#include<cstdlib>
#include<conio.h>

using namespace std;

class account
{
public:
int i;
long long int mobileno;
char z;
int age;
char eid[50];
char firstname[50];
char lastname[50];
int pass;
int acno;
int Balance;
void login(int );
//display account
void show_account()
{
	cout<<"FIRSTNAME  :  "                <<firstname<<endl;
	cout<<"LASTNAME  :  "                 <<lastname<<endl;
	cout<<"EMAIL ID  :  "                 <<eid<<endl;
	cout<<"MOBILE NO  :  "                <<mobileno<<endl;
	cout<<"AGE        :  "                <<age<<endl;
	cout<<"ACCOUNT NUMBER  :  "            <<acno<<endl;
	cout<< "ACCOUNT TYPE  :  "             <<z<<endl;
	cout<<"BALANCE :"                      <<Balance;
	cout<<endl;
}

//creating account
void create_account()
{
cout<<"ENTER FIRST NAME \n";
cin.ignore();
  cin.getline(firstname,50);
  cout<<"ENTER LAST NAME \n";
  cin.getline(lastname,50);
  cout<<"ENTER YOUR AGE\n";
  cin>>age;
  if(age>18)
  {
  cout<<"ENTER EMAIL ID\n";
  cin.ignore();
  cin.getline(eid,50);
  cout<<"ENTER MOBILE NO\n";
  cin>>mobileno;
  cout<<"ENTER ACCOUNT NUMBER\n";
  cout<<"*NOTE : account number must be a 6 digits number\n";
  cin>>acno;
if(acno>99999&&acno<1000000)
{
cout<<"CREATE YOUR PASSCODE \n";
cout<<"*NOTE : passcode must be a 4 digits number\n";
cin>>pass;

if(pass>999&&pass<10000)
{
cout<<"enter type of account[c for current/s for savings]<<endl: ";
cin>>z;
if(z=='c'||z=='C')
{
L5:cout<<"minimum amount should be 1000\n";
  cout<<"ENTER AMOUNT \n";
cin>>Balance;
if(Balance>=1000)
cout<<"account created succesfully\n\n";
else
{
cout<<"not eligible\n";
goto L5;
}
}
else if(z=='s'||z=='S')
{
    L6:cout<<"minimum amount should be 500\n";
  cout<<"ENTER AMOUNT \n";
cin>>Balance;
if(Balance>=500)
cout<<"account created succesfully\n\n";
else
{
cout<<"not eligible \n";
goto L6;
}
}
else
{
    cout<<"account not created";
}
}
else
{
	cout<<"***passcode not have 4 digits***\n";
}
}
else
{
	cout<<"***account number not have 6 digits***\n";
}
}
else
{
	cout<<"REJECTED\n";
}
}

//modify account
void modify()
{
	int no;
	int m;
	cout<<"\n\n\t01. MODIFY WHOLE DETAILS ";
    cout<<"\n\n\t02. MODIFY SPECIFIC \n";
    cin>>m;
    switch(m)
    {
    	case 1:
    		 cout<<"MODIFY FIRST NAME \n";
             cin.ignore();
             cin.getline(firstname,50);
             cout<<"MODIFY LAST NAME \n";
             cin.getline(lastname,50);
             cout<<"MODIFY AGE\n";
             cin>>age;
             cout<<"MODIFY EMAIL ID\n";
             cin.ignore();
             cin.getline(eid,50);
             cout<<"MODIFY MOBILE NO\n";
             cin>>mobileno;
             break;
        case 2:     
	    cout<<"which details are need to be modified";
        cout<<"\n\n\n\tLIST";
		cout<<"\n\n\t01. NAME";
		cout<<"\n\n\t02. AGE";
		cout<<"\n\n\t03. EMAIL ID";
		cout<<"\n\n\t04. MOBILE NO";
		cout<<"\n\n\t05.EXIT";
		cout<<"\n\n\tSelect Your Option (1-5) : ";
		  cin>>no;
	
		  switch(no)
       {
        case 1:
        	cout<<"MODIFY FIRST NAME \n";
            cin.ignore();
            cin.getline(firstname,50);
            cout<<"MODIFY LAST NAME \n";
            cin.getline(lastname,50);
	        break;
	    case 2:
	    	cout<<"MODIFY AGE\n";
            cin>>age;
      	    break;
      	case 3:	
		  cout<<"MODIFY EMAIL ID\n";
		  cin.ignore();
          cin.getline(eid,50);
	      break;
	    case 4:
		  cout<<"MODIFY MOBILE NO\n";
          cin>>mobileno;	
	      break;
}
}
}
//forgot passcode
void forgot()
{
	cin>>pass;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
void dep(int x)
{
	Balance+=x;
	cout<<" Updated balance"<<Balance;
}
	
void draw(int x)
{
	Balance-=x;
	cout<<" Updated balance"<<Balance;
}
	
int retacno() const
{
	return acno;
}

int retdeposit() const
{
	return Balance;
}

char rettype() const
{
	return z;
}
int retpass() 
{

	return pass;
}

int retage() const
{
	return age;
}
};

//function declaration
void delete_account(int );
void deposit_withdraw(int , int);
void write_account();
void display_sp(int );
void modify_account(int );
void forgot_passcode(int );
void intro();
void login(int );

//main function
int main( )
{
int userid1;
int userid=1608733;
string pass3=("bms");
string pass2;
int s;
int num;
intro();
cout<<"*********************************************************************************\n";
cout<<"                   WELCOME TO THE BANK MANGEMENT SYSTEM                                            \n";
cout<<"********************************************************************************\n";
cout<<"\n\n";
cout<<"enter admin userid : ";
cin>>userid1;
cout<<"enter admin password : ";
cin>>pass2;
if (userid1==userid&&pass2==pass3)
{
while(1)
{

cout<<"\n 1.CREATE ACCOUNT\n 2.LOGIN\n 3.EXIT\n";
cout<<" SELECT AN OPTION (1-3) :  ";
cin>>s;
switch(s)
{
      case 1:
	          write_account();
			  break;
      case 2:
              cout<<"\n\nAccount number ";
              cin>>s;   	
      	      login(s);
      	      break;
      case 3:exit(0);
}
}
}
else
{
	cout<<"login failed";
	exit(0);
}
}

//login function
void login(int n)
{	
	int num;
	int s;
	int pass1;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retage()>18)
		{
		if(ac.retacno()>99999&&ac.retacno()<1000000)
	    {
	if(ac.retpass()>999&&ac.retpass()<10000)
	  { 
		if(ac.retacno()==n)
		{
				cout<<"enter passcode  ";
           cin>>pass1;
			if(ac.retpass()==pass1)
			{
			while(1)
			{
		cout<<"***************************LOGIN SUCCESSFUL******************************* ";
		cout<<"\n\n\t1. SHOW ACCOUNT";
		cout<<"\n\n\t2. DEPOSIT AMOUNT";
		cout<<"\n\n\t3. WITHDRAW AMOUNT";
		cout<<"\n\n\t4. MODIFY AN ACCOUNT";
		cout<<"\n\n\t5. CLOSE AN ACCOUNT";
		cout<<"\n\n\t6. CHANGE PASSCODE";
		cout<<"\n\n\t7. MAIN MENU";
		cout<<"\n\n\t8. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8 ) : ";
		cin>>s;
		
		switch(s)
		{

	   case 1:
	          cout<<"\n\nAccount number ";
              cin>>s;
              display_sp(s);break;
       case 2:
			 cout<<"\n\n\tEnter The account No. : "; 
		     cin>>num;
			 deposit_withdraw(num, 1);
			 break;
	   case 3:
			 cout<<"\n\n\tEnter The account No. : "; cin>>num;
			 deposit_withdraw(num, 2);
			 break;
	   case 4:
			 cout<<"\n\n\tEnter The account No. : "; cin>>num;
			 modify_account(num);
			 break;
       case 5:
			 cout<<"\n\n\tEnter The account No. : "; 
			 cin>>num;
			 delete_account(num);
			 break;
	   case 6:
	  	     cout<<"enter your account number :  ";
	  	     cin>>num;
	  	     forgot_passcode(num);
	  	     break;
	   case 7:
	   	     cout<<endl;
	         main();
	         break;
	   case 8:
	         exit(0);
	          	  
}}}}
}
}
}
else
{
	cout<<"not eligible\n";
}
}
}

//forgot_passcode 
 void forgot_passcode(int n)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			cout<<"\n\nEnter The New passcode"<<endl;
			ac.forgot();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t passcode changed successfully\n";
			found=true;
		  }
	}
}	

//write function
void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

//display function
void display_sp(int n)
{
int pass1;

	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
	
		if(ac.retacno()==n)
		{
				cout<<"enter passcode  ";
           cin>>pass1;
			if(ac.retpass()==pass1)
			{
			cout<<"\nBALANCE DETAILS\n";
			ac.show_account();
			flag=true;
	     	}
	     	else
	     	{
	     		cout<<"password invalid";
			 }
		   
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
}


//modify account
void modify_account(int n)
{
	int pass1;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			cout<<"         enter passcode  ";
            cin>>pass1;
			if(ac.retpass()==pass1)
			{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	   }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}


//diposit & withdraw
void deposit_withdraw(int n, int option)
{
int pass1;	
	int amt;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			cout<<"         enter passcode  ";
           cin>>pass1;
			if(ac.retpass()==pass1)
			{
			
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited : ";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw : ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
			}
		}
		else
		{
				cout<<"password invalid";
		}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
		
			found=true;
	       }
         }
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}

//delete account
void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	int pass1;
	cout<<"        enter passcode  ";
	cin>>pass1;
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			if(ac.retpass()!=pass1)
			{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}


//introduction
void intro()
{
	cout<<"\n\n\n \t \t \t \t **********BANK MANAGEMENT SYSTEM********** ";
	cout<<"\n\n\n \t \t \t \t BATCH NO : A7";
	cout<<"\n\n\n \t \t \t \t COLLEGE  : MATRUSRI ENGINEERING COLLEGE";
	cout<<"\n\n\n \t \t \t \t DONE BY  : S.SAIKUMAR(1608-16-733-010)";
	cout<<"\n\n\n \t \t \t \t          : K.SRIHARI(1608-16-733-020)";
	cout<<"\n\n\n \t \t \t \t          : R.NIKHIL BHARADWAJ(1608-16-733-031)";
		cout<<"\n\n\n \t \t \t \t *************************************** ";
	cin.get();
}

