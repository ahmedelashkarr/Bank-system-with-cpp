
#include <iostream>
#include <string>
using namespace std;
struct user {
    string name ;
    string number;
    int  id = 0;
    int balance = 0;
}arr[10];

void create();
void update();
void withdraw( int);
void deposite( int);
void program();
void info(int);
int main()
{
    char have;
    cout << "You have account ? (Y/N) ";cin >> have;
    system("cls");
    if (have == 'y' || have == 'Y')program();
    else if (have == 'N' || have == 'n') { 
        create();
        program();
    }

}

//create - update - withdraw - deposite - info - delete


void create() {
    system("cls");
    for(int i = 1 ; i < 10 ;i++ )
        if (arr[i].id == 0) {
            cout << "Enter your name : "; cin >> arr[i].name;
            cout << "Enter your number : "; cin >> arr[i].number;
            arr[i].id = i ;
            cout << "Your id is " << arr[i].id << endl ;
            break;
        }
}
void update() {
    system("cls");
    int id, choice, flag = 0;
    cout << "enter your id : "; cin >> id;
    system("cls");
    for (int i = 0; i < 10; i++)
        if (id == arr[i].id) {
            cout << "What do you want change ? " << endl << "1- Name \n2- number\n";
            cin >> choice;
            system("cls");
            switch (choice)
            {
            case 1:
                cout << "Enter new name : "; cin >> arr[i].name;
                break;
            case 2:
                cout << "Enter new number : "; cin >> arr[i].number;
                break;
            default:
                cout << "Wrong anwer";
                break;
            }
        }

}
void withdraw( int id) {
    system("cls");
    int with;
    cout << "Enter price : "; cin >> with;
    if (with > arr[id].balance)cout << "Sorry your balance dont alowed\n";
    else{
    arr[id ].balance -= with;
    cout << "your balance : "<< arr[id].balance<<endl;
    }
}
void deposite( int id) {
    int dep;
    system("cls");
    cout << "Enter price : "; cin >> dep;
    arr[id ].balance += dep;
    cout << "your balance : "<< arr[id].balance << endl;

}
void program() {
    int id, flag = 0;
    char any = 'y';
    cout << "Enter your id : "; cin >> id;
    for (int i = 1; i < 10; i++) {
        if (id == arr[i].id)flag = 1;
        break;
    }
    while ((any == 'Y' || any == 'y') && flag == 1) {
        int op;
        system("cls");
        cout << "1- Withdraw\n2- deposite\n3- update\n4- info \n";
        cout << "Enter operation : "; cin >> op;
        switch (op)
        {
        case 1:
            withdraw(id);
            break;
        case 2:deposite(id);
            break;
        case 3:update();
            break;
        case 4:info(id);
        default:
            cout << "wrong answer\n";
            break;
        }
        cout << "Do you want other operation ? (Y/N) ";
        cin >> any;
    }
    if (flag == 0)cout << "\t\t\t\tsorry no account for this id";
    cout << "\n\n\t\t\t\t--------------Thank you--------------";
}
void info(int id) {
    system("cls");
    cout << "Your name is " << arr[id].name << endl;
    cout << "Your number is " << arr[id].number << endl;
    cout << "Your balance is " << arr[id].balance << endl;
    cout << "Your id is " << arr[id].id << endl;

}