#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>  // for setprecision()

using namespace std;

// Function Declarations
void mainMenu();
void deposit();
void withdraw();
void getBalance();

double balance = 0.0;

int main() {
  const string PIN = "1234";
  string userInput;

  cout << "Please enter your four digit pin: " << endl;
  getline(cin, userInput);

  if (userInput == PIN) {  // check PIN
    cout << "Thank you! Please make a selection from the menu below:" << endl;
    mainMenu();  // call mainMenu
  } else {
    cerr << "You have entered an incorrect pin." << endl;
    return 1;
  }
  return 0;
}

void mainMenu() {
  string userInput;
  cout << "\n1. Deposit\n2. Withdraw\n3. Balance\n4. Exit\n" << endl;
  cout << "Please enter your choice from the menu: " << endl;
  getline(cin, userInput);
  double choice = atof(userInput.c_str());

  while (choice != 4) {
    if (choice == 1) {
      deposit();
      mainMenu();
      break;
    } else if (choice == 2) {
      withdraw();
      mainMenu();
      break;
    } else if (choice == 3) {
      getBalance();
      mainMenu();
      break;
    } else {
      cerr << "Your choice is not on the menu." << endl;
      break;
    }
  }
}

void getBalance() {
  cout << fixed << setprecision(2) << "Your balance is: $" << balance
       << endl;  // Print balance
  // mainMenu(); //can call here because the other functions go to this function
  // to print the new balance.
}

void deposit() {
  string deposit;
  cout << "Please enter how much money would you like to deposit: " << endl;
  getline(cin, deposit);
  double money = atof(deposit.c_str());
  if (money > 0.0) {
    balance += money;
    getBalance();
  } else {
    cout << "You cannot deposit a negative amount." << endl;
  }
}

void withdraw() {
  string deposit;
  cout << "Please enter how much you would like to withdraw: " << endl;
  getline(cin, deposit);
  double money = atof(deposit.c_str());
  if (balance > money && money > 0.0) {
    balance -= money;
    getBalance();
  } else if (money < 0.0) {
    cout << "You cannot withdraw a negative amount." << endl;
  } else {
    cout << "You do not have enough money in your account to withdraw that "
            "amount." << endl;
  }
}
