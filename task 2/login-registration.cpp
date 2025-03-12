#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){
    int c;
    cout<<"\t\t\t______________________________________\n\n";
    cout<<"\t\t\t          WELCOME TO LOGIN PAGE              \n\n";
    cout<<"\t\t\t________________ MENU _______________\n\n";
    cout<<"                                        \n";
    cout<<"\t\t\t|         Press 1 to LOGIN       |"<<endl;
    cout<<"\t\t\t|         Press 2 to REGISTER       |"<<endl;
    cout<<"\t\t\t|         Press 3 in case you FORGOT your password       |"<<endl;
    cout<<"\t\t\t|         Press 4 to EXIT       |"<<endl;
    cout<<"\n\t\t\tPlease Enter Your Choice :-";
    cin>>c;
    cout<<endl;

    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout<<"\t\t\t THANK YOU ! \n\n";
        break;
    
    default:
        system("cls");
        cout<<"\t\t\tPlease SELECT from the options given above\n"<<endl;
        main();
    }
}

void login(){
    int count = 0; // Fix: Initialize count
    string userID, Password, id, pass;
    system("cls");
    cout<<"\t\t\tPLease Enter the Username and Password :- ";
    cout<<"\t\t\tUSERNAME : ";
    cin>>userID;
    cout<<"\t\t\tPASSWORD : ";
    cin>>Password;

    ifstream input("records.txt");

    while (input>>id>>pass)
    {
        if(id==userID && pass==Password){
            count=1;
            system("cls");
        }
    }
    input.close();

    if(count==1){
        cout<<userID<<"\n Your LOGIN is successful...\n Thanks for Logging in !\n";
        main();
    }
    else{
        cout<<"\n LOGIN ERROR \n Please check Your Username and Password\n";
        main();
    }
}

void registration(){
    string ruserID,rpassword;
    system("cls");
    cout<<"\t\t\t Enter the Username You want to Use: ";
    cin>>ruserID;
    cout<<"\t\t\t Enter the Password You want to Use: ";
    cin>>rpassword;

    ofstream f1("records.txt",ios::app);
    f1<<ruserID<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is SUCCESSFUL...\n";
    main();
}

void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\t You Forgot the Password ?? No worries...\n";
    cout<<"\t\t\tPress 1 to search your id by Username\n"<<endl;
    cout<<"\t\t\tPress 2 to go back to the main menu\n"<<endl;
    cout<<"\t\t\t Enter your choice : ";
    cin>>option;

    switch(option){
        case 1:
        {
            int count = 0; // Fix: Initialize count
            string suserID,sID,spass;
            cout<<"\n\t\t\tEnter the Username that You Remembered :- ";
            cin>>suserID;

            ifstream f2("records.txt");
            while(f2>>sID>>spass){
                if(sID==suserID){
                    count = 1; // Fix: Assign 1 instead of ==1
                    break;
                }
            }
            f2.close();

            if(count==1){
                cout<<"\n\n Your account is found! \n";
                cout<<"\n\n Your Password is : "<<spass<<endl;
                main();
            }
            else{
                cout<<"\nSorry, Your Account is not found !!\n";
                main();
            }
            break;
        }
        case 2:
            main();
        default:
            cout<<"\n\t\t\tWrong Choice, Please Try again "<<endl;
            forgot();
    }
}
