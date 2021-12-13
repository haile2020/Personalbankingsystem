//
//  main.cpp
//  PersonalBankingSystem
//
//  Created by Haile on 12/3/21.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//prototype

int print_Menu();
void display(int x);

////global variable
//int pin;
int account_number;
double account_balance;
string branch_name;
string name;

//Parent class

class CustomerRecords {
private:
    int pin;
public:
    int getpin(){
        return this->pin;
    }
    //defualt constractor
    CustomerRecords () {//std::cout<<"Parent constractor"<<endl;
        
    }
    
    //creat print_menu function/method to give opition to user input
    int print_Menu()
    {
            int input;
        
            std::cout<<"Menu"<<endl;
            std::cout<<"Please enter 0 for new account: "<<std::endl;
            std::cout<<"Please enter 1 for to see you balance"<<std::endl;
            std::cout<<"Please enter 2 for Witdrawal "<<std::endl;
            std::cout<<"Please enter 3 for deposit: "<<std::endl;
            std::cout<<"Please enter 4 for exit: "<<std::endl;
            
            std::cin>>input;
        
            return input;
    }
    
    //create a function to creat and write on the  customer file
    
    void crt_wrt()
    {
        ofstream file("/Users/haile/Desktop/PersonalBankingSystem/PersonalBankingSystem/customerfile/consumerrecord.txt");
        while (cin>>account_number>>name>>pin>>account_balance>>branch_name) {
             file<<account_number<<' '<<name<<' '<<pin<<' '<<account_balance<<' '<<branch_name<<endl;
         }
    
        file.close();
    }
    
    //create a fuction to read from the file
    
    void read_file()
    {
        ifstream file("/Users/haile/Desktop/PersonalBankingSystem/PersonalBankingSystem/customerfile/consumerrecord.txt");
        
        while (file>>account_number>>name>>pin>>account_balance>>branch_name) {
            std::cout<<account_number<<", "<<name<<", "<<pin<<","<<account_balance<<", "<<branch_name<<endl;
        }
        file.close();
        
    }
    
    //create a function to add info to the customer file
    
    void add_file()
    {
        cin>>account_number>>name>>pin>>account_balance>>branch_name;
        ofstream file;
        file.open("/Users/haile/Desktop/PersonalBankingSystem/PersonalBankingSystem/customerfile/consumerrecord.txt",ios::app | ios::out);
        file<<account_number<<' '<<name<<' '<<pin<<' '<<account_balance<<' '<<branch_name<<endl;
        file.close();
   
    }
    
    //create function to upadte a file
    
    double updatefile()
    {
        ifstream file("/Users/haile/Desktop/PersonalBankingSystem/PersonalBankingSystem/customerfile/consumerrecord.txt");
        int accut_num;
        double searchitem;
        
        cout<<"Enter Account Number\n";
        cin>>accut_num;
        
        cout<<"Enter item to search\n";
        cin>>searchitem;
        
        while (file>>account_number>>name>>pin>>account_balance>>branch_name) {
            
            if (accut_num== account_number) {
//                std::cout<<account_number<<", "<<name<<", "<<pin<<","<<account_balance<<", "<<branch_name<<endl;
                std::cout<<account_balance<<"\n";
                
                if (searchitem == account_balance) {
                    return account_balance;
                }
                
            }

        }
        file.close();
        return 0;
    }
    
    //create a function to handel file based on user input
    
    auto file_handler()
    {
        char chioce;
        
        std::cout<<"Create and write on the file press 'w' "<<endl;
        std::cout<<"Read a file press 'r' "<<endl;
        std::cout<<"add a file 'a'"<<endl;
        std::cout<<"update a file 'u' "<<endl;
        std::cout<<"delete a file 'd' "<<endl;
        cin>>chioce;
        
        std::cout<<"Enter account number, name, pin, account balance, and branch name"<<endl;
        std::cout<<"Press Command+Z and enter to quit"<<endl;
//        int account_number;string name;  int pin;
//        double account_balance; string branch_name;
        
        while (1)
        {
        if (chioce == 'w' || chioce == 'W')
        {
            crt_wrt();
        }
        if (chioce == 'r' || chioce == 'R')
            {
            read_file();
        }
        if (chioce == 'a' || chioce == 'A')
        {
            add_file();
        }
        if (chioce == 'u' || chioce == 'U')
        {
            updatefile();
        }
        
        if (chioce == 'd' || chioce == 'D') {}
            return 0;
        }
      
    }
};

//child class for personal account

class PersonalAccount : public CustomerRecords {
    
private:
    int pin;
    
public:
    
    int getpin()
    {
        return this->pin;
    }
                  //create withdrawal function
                    void withdrawal(int ppin,double amount){
                        
                        ifstream customerFile("/Users/haile/Desktop/PersonalBankingSystem/PersonalBankingSystem/customerfile/consumerrecord.txt");
                        
                        int account_number;
                        string name;
                        int pin;
                        double account_balance;
                        string branch_name;
                        
                        std::cout<<"withdrawal!!!\n";
                        while(customerFile>>account_number>>name>>pin>>account_balance>>branch_name)
                        {
                        
                            if (pin == ppin)
                            {
                                account_balance = account_balance -amount;
                                
                                cout<< "you are withdraw  "<<amount <<" and your new Balance is: "<<account_balance<<std::endl;
                            }
                            
                        }
                        
                    }
        
    void deposit(int ppin,double amount)
    {
        
        ifstream customerFile("/Users/haile/Desktop/PersonalBankingSystem/PersonalBankingSystem/customerfile/consumerrecord.txt");
        
        int account_number;
        string name;
        int pin;
        double account_balance;
        string branch_name;
        
        std::cout<<"Deposit!!!\n";
        
        while(customerFile>>account_number>>name>>pin>>account_balance>>branch_name)
        {
        
            if (pin == ppin) {
                double new_balance = account_balance + amount;
                cout<< "you are depost  "<<amount <<" and your new Balance is: "<<new_balance<<std::endl;
            }
            
        }
        
    }
    //create function to enter the money amount
    
    double usr_ipt()
    {
        int amt;
        std::cout<<"Please enter amount: ";
        std::cin>>amt;
        return amt;
    }
    
    //create display function that set condition based on user input
    
    void display(int x)
    {
        ifstream customerFile("/Users/haile/Desktop/PersonalBankingSystem/PersonalBankingSystem/customerfile/consumerrecord.txt");
        
        int account_number;
        string name;
        int pin;
        double account_balance;
        string branch_name;
        
        //read file and execute accordingly
        if (x==0)
        {
//            crt_wrt_file();
            file_handler();
            exit(1);
        }
        else
        {
            int apin;
            std::cout<<"Please enter pin\n";
            std::cin>>apin;
            if (x==1)
            {
               while(customerFile>>account_number>>name>>pin>>account_balance>>branch_name)
               {
                     if (pin==apin)
                     {
                         cout<<"Hello "<<name<<" Your current balance is:  "<<account_balance<<endl;
                         
                     }
             }
                 }
             else if (x==2)
             {
                
                 while(customerFile>>account_number>>name>>pin>>account_balance>>branch_name)
                 {
                     if (pin==apin)
                     {
                         cout<<"\t\t\tWelcome "<<name<<endl;
                         double amt = usr_ipt();
                         withdrawal(apin, amt);
                     }
             
                 }
                 
             }
             else if (x==3)
             {
                 
                 while(customerFile>>account_number>>name>>pin>>account_balance>>branch_name)
                 {
                     if (pin==apin)
                     {
                         cout<<"\t\t\tWelcome "<<name<<endl;
                         double amt = usr_ipt();
                         deposit(apin, amt);
                     }
             
                 }
                 
             }
             else
             {
                 std::cout<<"done!\n";
             }
        }
       
        
    }
};

//child class for checkig account

class Checking_Account : public PersonalAccount
{
public:
    double checking_balance= 2000;
    void deposit(int ppin,double amount)
    {
        
        ifstream customerFile("/Users/haile/Desktop/PersonalBankingSystem/PersonalBankingSystem/customerfile/consumerrecord.txt");
        
        int account_number;
        string name;
        int pin;
        double account_balance;
        string branch_name;
        
        std::cout<<"Deposit!!!\n";
        while(customerFile>>account_number>>name>>pin>>account_balance>>branch_name)
        {
        
            if (pin == ppin)
            {
                checking_balance = checking_balance + amount;
                cout<< "you are depost  "<<amount <<" and your new Balance is: "<<checking_balance<<std::endl;
            }
            
        }
        
    }
    
    //create withdrawal
      void withdrawal(int ppin,double amount)
    {
          
          ifstream customerFile("/Users/haile/Desktop/PersonalBankingSystem/PersonalBankingSystem/customerfile/consumerrecord.txt");
          
          int account_number;
          string name;
          int pin;
          double account_balance;
          string branch_name;
          
          std::cout<<"withdrawal!!!\n";
          
          while(customerFile>>account_number>>name>>pin>>account_balance>>branch_name)
          {
          
              if (pin == ppin)
              {
                  checking_balance = checking_balance - amount;
                  cout<< "you are withdraw  "<<amount <<" and your new Balance is: "<<checking_balance<<std::endl;
              }
              
          }
          
      }

    void print_info(int accut_no)
    {
       
        ifstream file("/Users/haile/Desktop/PersonalBankingSystem/PersonalBankingSystem/customerfile/consumerrecord.txt");
        int pin = getpin();
        while (file>>account_number>>name>>pin>>account_balance>>branch_name)
        {
            if (accut_no == account_number)
            {
            std::cout<<"Customer Account number: "<<account_number<<"\n"<<"Customer name "<<name<<"\n"<<"pin: "<<pin<<"\n"<<"Customer Account balance"<<account_balance<<"\nBranch name: "<<branch_name<<endl;
            }
            
        }
        file.close();
        }
    
};

//child class for saving account

class Saving_Account : public PersonalAccount
{
    
public:
    double saving_balance= 2000;
    
    // craet a  deposit function for saving account
    
    void deposit(int ppin,double amount)
    {
        
        //read a file
        
        ifstream customerFile("/Users/haile/Desktop/PersonalBankingSystem/PersonalBankingSystem/customerfile/consumerrecord.txt");
        
        //declar a variable
        
        int account_number;
        string name;
        int pin;
        double account_balance;
        string branch_name;
        std::cout<<"Deposit!!!\n";
        
        //loop over a file
        
        while(customerFile>>account_number>>name>>pin>>account_balance>>branch_name)
        {
        //check if the pin entered was correct
            
            if (pin == ppin)
            {
                //calculate a balance and add the amount enter to balance
                
                saving_balance = saving_balance + amount;
                
                //display the amount
                
                cout<< "you are depost  "<<amount <<" and your new Balance is: "<<saving_balance<<std::endl;
            }
            
        }
        
    }
    
    //create withdrawal for saving account
    
      void withdrawal(int ppin,double amount)
    {
          
          ifstream customerFile("/Users/haile/Desktop/PersonalBankingSystem/PersonalBankingSystem/customerfile/consumerrecord.txt");
          
          int account_number;
          string name;
          int pin;
          double account_balance;
          string branch_name;
          
          std::cout<<"withdrawal!!!\n";
          
          while(customerFile>>account_number>>name>>pin>>account_balance>>branch_name)
          {
          
              if (pin == ppin)
              {
                  saving_balance = saving_balance - amount;
                  cout<< "you are withdraw  "<<amount <<" and your new Balance is: "<<saving_balance<<std::endl;
              }
              
          }
          
      }
    
//acreate function to display customer info
    
    //overload
    
    void print_info(int accut_no)
    {
       
        ifstream file("/Users/haile/Desktop/PersonalBankingSystem/PersonalBankingSystem/customerfile/consumerrecord.txt");
        
        int pin = getpin();
        while (file>>account_number>>name>>pin>>account_balance>>branch_name)
        {
            if (accut_no == account_number)
            {
            std::cout<<"Customer Account number: "<<account_number<<"\n"<<"Customer name "<<name<<"\n"<<"pin: "<<pin<<"\n"<<"Customer Account balance"<<account_balance<<"\nBranch name: "<<branch_name<<endl;
            }
            
        }
        file.close();
        }
    
    //over load
    
    void print_info()
    {
        std::cout<<"***************************************************"<<endl;
        std::cout<<"information about this Bank\n";
        std::cout<<"est. 2021\n";
        std::cout<<"have four branchs\n";
        std::cout<<"***************************************************"<<endl;
        
    }
};

int main () {
//    system("clr");
    
    //creating  CustomerRecords class instance
    
    CustomerRecords record1;
    PersonalAccount paccount;
    Checking_Account checking;
    Saving_Account saving;
//    record1.print_Menu();
//    paccount.print_Menu();
//    checking.print_Menu();
//    record1.crt_wrt_file("haile","Haile","123456789",1234,5000,"North west Washington D.C.");
//    record1.read_file("haile","Haile","123456789",1234,5000,"North west Washington D.C.");
//    string username;
//    std::cout<<"Enter User name\n";
//    std::cin>>username;
//    record1.crt_wrt_file();
//    record1.read_file();
//    saving.read_file();
    
    
    //display menu
    int ipt = record1.print_Menu();
//    checking.updatefile();
    while (ipt != 4) {
        switch (ipt) {
            case 0:
               paccount.display(0);
                break;
            case 1:
                paccount.display(1);
                break;
            case 2:
                paccount.display(2);
                break;
            case 3:
                paccount.display(3);
                break;
                
            default:
                break;
        }
        
        ipt = record1.print_Menu();
    }
    checking.deposit(1234, 9999);
    checking.withdrawal(1234, 9999);
    cout<<"Enter account number\n";
        int acnum;
        cin>>acnum;
    saving.print_info(acnum);
    saving.print_info();
//
//    checking.print_info(acnum);
    
  return  0;
}
