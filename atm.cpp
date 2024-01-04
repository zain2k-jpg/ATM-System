//Muhammad Zain
//19i-0414
//Section B
//OOP final project

#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>

using namespace std;

class atm                               //parent class  (abstract)
{
	protected:
		int accountNum;                 //account number stored in database
		int pin;                        //pin stored in database
		float balance;                  //balance stored in database
	public:
		atm()
		{
			accountNum=0;
			pin=0;
			balance=0;
		}
		
		virtual void display()=0;       //pure virtual function for displaying initial output screen
		
		void dataBase()                 //Function for File Handling
		{
			ifstream input;
			input.open("database.txt");
			if(!input)
			{
	             cout<<"\nFile not found!";   //file validation
	             exit(0);
	        }
	        else
	        {
	            while(!input.eof())           //taking input from file
			    {
				    input>>accountNum;
				    input>>pin;
				    input>>balance;
			    }
		    }
			input.close();
		}
};

class withdrawal : public atm                 //child class for withdrawing money
{
	int withdrawalAmount;                     //variable for recieving amount to be withdrawn
	int userAccNum;                           //account number input by user
	int userPin;                              //pin input by user
	
	public:
		withdrawal():atm()                    //default constructor
		{
			withdrawalAmount=0;
		}
		void display()                        //initial display
		{
			cout<<"Welcome to the National Bank of FAST!\n\n";    //taking account no. and pin
			cout<<"Please Enter your Account Number: ";
			cin>>userAccNum;
			cout<<"Enter your PIN: ";
			cin>>userPin;
			
			while (1)                                             //verifying account number and pin
			{
				if(userAccNum!=accountNum || userPin!=pin)
				{
					system("cls");
					cout<<"You have entered an Invalid Account Number OR Password! Try Again.\n\n";
					cout<<"Please Enter your Account Number: ";
			        cin>>userAccNum;
			        cout<<"Enter your PIN: ";
			        cin>>userPin;
				}
				else
				   break;
			}
		}
		void getBalance()                                         //function to show current balance
		{
			cout<<"\nYour Account Balance Is: $"<<balance;
		}
		void withdrawCash()                                       //withdrawing cash
		{
			int option;
			while(1)                                              //taking input for amount of cash withdrawal
			{
			    cout<<"Select the option of amount you want to withdraw: "
			    <<endl<<endl
			    <<"1. $20\n"
			    <<"2. $40\n"
			    <<"3. $60\n"
			    <<"4. $100\n"
			    <<"5. $200\n"
			    <<"6. Cancel Transaction\n\n";
			    cout<<"Enter option: ";
			    cin>>option;
			    
			    cout<<endl;
	
				if(option==1 && balance>=20)                      //output for $20
				{
					system("cls");
					cout<<"\n$20 successfully withdrawn!";
					balance=balance-20;                           //updating balance
					cout<<"\n\nRemaining Balance: $"<<balance;
					break;
				}
				else if(option==2 && balance>=40)                 //output for $40
				{
					system("cls");
					cout<<"\n$40 successfully withdrawn!";
					balance=balance-40;                           //updating balance
					cout<<"\n\nRemaining Balance: $"<<balance;
					break;
				}
				else if(option==3 && balance>=60)                 //output for $60
				{
					system("cls");
					cout<<"\n$60 successfully withdrawn!";
					balance=balance-60;                           //updating balance
					cout<<"\n\nRemaining Balance: $"<<balance;
				    break;
				}
				else if(option==4 && balance>=100)                //output for $100
				{
					system("cls");
					cout<<"\n$100 successfully withdrawn!";
					balance=balance-100;                   
					cout<<"\n\nRemaining Balance: $"<<balance;
				    break;
				}
				else if(option==5 && balance>=200)                //output for $200
				{
					system("cls");
					cout<<"\n$200 successfully withdrawn!";
					balance=balance-200;                          //updating balance
					cout<<"\n\nRemaining Balance: $"<<balance;
				    break;
				}
				else if(option==1 && balance<20)                  //input validation for amount bigger than balance
				{
					system("cls");
					cout<<"\nYour Account Balance is insufficient to make a withdrawal!\n";
					cout<<"\nCurrent Balance: $"<<balance;
				    break;
				}
				else if(option==2 && balance<40)                 //input validation for amount bigger than balance
				{
					system("cls");
					cout<<"\nYou have selected an amount greater than your current balance!\n";
					cout<<"\nCurrent Balance: "<<balance;
					cout<<"\nPlease select an amount lesser than or equal to your current balance!\n\n";
				    continue;
				}
				else if(option==3 && balance<60)                 //input validation for amount bigger than balance
				{
					system("cls");
					cout<<"You have selected an amount greater than your current balance!\n";
					cout<<"\nCurrent Balance: $"<<balance;
					cout<<"\n\nPlease select an amount lesser than or equal to your current balance!\n\n";
				    continue;
				}
			    else if(option==4 && balance<100)               //input validation for amount bigger than balance
				{
					system("cls");
					cout<<"You have selected an amount greater than your current balance!\n";
					cout<<"\nCurrent Balance: $"<<balance;
					cout<<"\n\nPlease select an amount lesser than or equal to your current balance!\n\n";
				    continue;
				}
				else if(option==5 && balance<200)               //input validation for amount bigger than balance
				{
					system("cls");
					cout<<"You have selected an amount greater than your current balance!\n";
					cout<<"\nCurrent Balance: $"<<balance;
					cout<<"\n\nPlease select an amount lesser than or equal to your current balance!\n\n";
				    continue;
				}
				else if(option==6)                              //cancelling transaction
				{
					break;
				}
				else if(option!=1||option!=2||option!=3||option!=4||option!=5||option!=6)     //input validation 
				{
					system("cls");
					cout<<"You have entered an invalid option! Try Again\n\n";
					continue;
				}
		
	        }
			
		}
		void updateBalance(char *b)                            //function to update the account balance in file
        {
        	    ofstream output;
	            ifstream input;
	            
	            input.open("database.txt");                    
	            if(!input)                                    //performing file handling and changing balance
	                cout<<"\nFile not found";
            	else
	            {
		            output.open("temperory.txt");
		            input.read((char*)this,sizeof(*this));
		            while(!input.eof())
		            {
		                   	if(strcmp("12345",b))
			                {
			                   	output.write((char*)this,sizeof(*this));
		                 	}
			                input.read((char*)this,sizeof(*this));
		            }
		            input.close();
		            output.close();
		            remove("database.txt");
		            rename("temperory.txt","database.txt");
	            }
	            output.open("database.txt",ios::app);           //updating account balance in file
	            output<<"12345"<<"\n"<<"54321"<<"\n"<<balance;
	            output.close();
        }
};

class deposit : public atm          //child class for depositing amount
{
	float depositAmount;            //variable to recive deposit amount
	int userAccNum;                 //account number input by user
	int userPin;                    //pin input by user
	
	public:
		deposit():atm()             //default constructor
		{
			depositAmount=0;
		}
		void display()              //initial display
		{
			cout<<"Welcome to the National Bank of FAST!\n\n";
			cout<<"Please Enter your Account Number: ";
			cin>>userAccNum;
			cout<<"Enter your PIN: ";
			cin>>userPin;
			
			while (1)               //verifying account no and password
			{
				if(userAccNum!=accountNum || userPin!=pin)
				{
					system("cls");
					cout<<"You have entered an Invalid Account Number OR Password! Try Again.\n\n";
					cout<<"Please Enter your Account Number: ";
			        cin>>userAccNum;
			        cout<<"Enter your PIN: ";
			        cin>>userPin;
				}
				else
				   break;
			}
		}
		void getDepositAmount()        //function to recieve deposit amount from user
		{
			float depositAmountinDollars;
			cout<<"\nEnter Deposit Amount(in cents) OR Enter 0 to cancel transaction: ";
			cin>>depositAmount;
			while(1)
			{
			    if(depositAmount==0)  //cancelling transaction
			    {
				    break;
			    }
			    else                  //taking cents and converting them to dollars
			    {
			    	depositAmountinDollars=depositAmount/100;
			    	balance=balance+depositAmountinDollars;
			    	cout<<"\n$"<<depositAmountinDollars<<" Successfully Deposited\n";
			    
			    	break;
			    }
			}
		}
};
short int menu()                      //function for displaying main menu
{
	short int option;
	cout<<"Main Menu: "
	    <<endl<<"1. View my balance"
        <<endl<<"2. Withdraw Cash"
	    <<endl<<"3. Deposit Funds"
	    <<endl<<"4. Exit";
	    
	cout<<endl<<endl<<"Enter your option: ";
	cin>>option;
	return option;
}

int main ()
{
	withdrawal w;                    //creating object of withdrawal class
	deposit d;                       //creating object of deposit class
	w.dataBase();                    //calling database function
	w.display();                     //calling display function
	
	while(1)
	{
		system("cls");               //using cls function for a better output
		switch (menu())              //getting and performing according to the user's entered choice
		{
			case 1:
				system("cls");
				w.getBalance();
				break;
		    case 2:
		    	system("cls");
		    	w.withdrawCash();
		    	break;
		    case 3:
		    	system("cls");
		        d.getDepositAmount();
		    	break;
		    case 4:                 //terminating program
		    	system("cls");
		    	cout<<"\nTHANKYOU FOR BANKING WITH US!\n\n";
		    	w.updateBalance("12345");
		    	exit(0);
		    default:
		    	system("cls");
		    	cout<<"You have entered an Invalid Option!";

		}
		cout<<endl<<endl<<"Press anything to continue";
		getch();
		
	}
}
