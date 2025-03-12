#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
private:
    string name;
    int accountnum;
    double balance;
public:
    BankAccount(string n, int ac, double bal) {
        name = n;
        accountnum = ac;
        balance = bal;
    }
    string getname() {
        return name;
    }
    int getaccountnum() {
        return accountnum;
    }
    double getbalance() {
        return balance;
    }
    void deposit(double amount){
        balance = balance+amount;
        cout<<"\t\t Amount Successfully ADDED...!!"<<endl;
    }
    void withdraw(double amount){
        if(balance>=amount){
            balance=balance-amount;
            cout<<"\t\t Withdraw Successfull...!!"<<endl;
        }
        else{
            cout<<"\t\t Insufficent Balance...!!"<<endl;
        }
    }
};

class BankManagement {
private:
    vector<BankAccount> accounts;
public:
    void addaccount(string name, int accountnum, double balance) {
        accounts.push_back(BankAccount(name, accountnum, balance));
    }
    void showallaccounts() {
        cout << "\t\t Showing All Account Holders :- " << endl;
        for (int i = 0; i < accounts.size(); i++) {
            cout << "Name : " << accounts[i].getname() << "\t Account Number: " << accounts[i].getaccountnum() << "\t Account Balance : " << accounts[i].getbalance() << endl;
        }
    }
    void searchaccount(int accno){
        int flag=0;
        for(int i=0;i<accounts.size();i++){
            if(accounts[i].getaccountnum()==accno){
                cout<<"\t\t ACCOUNT SUCCESSFULLY SEARCHED...!!"<<endl;
                cout << "Name : " << accounts[i].getname() << "\t Account Number: " << accounts[i].getaccountnum() << "\t Account Balance : " << accounts[i].getbalance() << endl;
            }
            else{
                flag=1;
            }
        }
        if(flag==1){
            cout<<"\n\t\tAccount Cannot be FOUND Please Try Again..!!"<<endl;
        }
    }
    BankAccount* findaccount(int accountnum){
        for(int i=0;i<accounts.size();i++){
            if(accounts[i].getaccountnum()==accountnum){
                return &accounts[i];
            }
        }
    }
};

int main() {
    BankManagement bank;
    int choice;
    while (true) {
        cout << "\n\n\t\t:: Bank Management System\n" << endl;
        cout << "\n\t\t----------Main Menu-----------\n" << endl;
        cout << "\t\t 1. Create New Account" << endl;
        cout << "\t\t 2. Show All Accounts" << endl;
        cout << "\t\t 3. Search Account" << endl;
        cout << "\t\t 4. Deposit Money" << endl;
        cout << "\t\t 5. Withdraw Money" << endl;
        cout << "\t\t 6. Exit" << endl;
        cout << "\t\t------------------------------------" << endl;
        cout << "\t\t Enter Your Choice :- ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int accountnum;
            double balance;
            cout << "\t\tEnter Full Name: ";
            cin >> name;
            cout << "\t\tEnter Account Number : ";
            cin >> accountnum;
            cout << "\t\tEnter Initial Balance: ";
            cin >> balance;
            bank.addaccount(name, accountnum, balance);
            cout << "\t\tAccount Created Successfully...!!" << endl;
            break;
        }
        case 2: {
            bank.showallaccounts();
            break;
        }
        case 3:{
            int accountNum;
            cout<<"Enter the Account Number You Want to Search :- ";
            cin>>accountNum;
            bank.searchaccount(accountNum);
            break;
        }
        case 4:{
            int accountnum;
            double amount;
            cout<<"\t\t Enter Account Number to DEPOSIT Money :- ";
            cin>>accountnum;
            BankAccount* account = bank.findaccount(accountnum);
            if(account != NULL){
                cout<<"\t\t Enter Amount To DEPOSIT :- ";
                cin>>amount;
                account->deposit(amount);
                cout<<"\t\t"<<amount<<" Deposit Succesfull..."<<endl;
            }
            else{
                cout<<"\t\t Account NOT FOUND...!!"<<endl;
            }
            break;
        }
        case 5:{
            int accountnum;
            double amount;
            cout<<"\t\t Enter Account Number to WITHDRAW Money :- ";
            cin>>accountnum;
            BankAccount* account = bank.findaccount(accountnum);
            if(account != NULL){
                cout<<"\t\t Enter Amount To WITHDRAW :- ";
                cin>>amount;
                account->withdraw(amount);
                cout<<"\t\t"<<amount<<" WITHDRAW Succesfull..."<<endl;
            }
            else{
                cout<<"\t\t Account NOT FOUND...!!"<<endl;
            }
            break;
        }
        case 6: {
            cout << "\n\t\tThanks For Visiting To our Bank...!!" << endl;
            break;
        }
        default: {
            cout << "\t\tInvalid Choice. Please try again." << endl;
            break;
        }
        }
    }
    return 0;
}