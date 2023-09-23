#include <iostream>
#include <iomanip>
using namespace std;

void showBalance(double balance);
double deposit();
double withdraw (double balance);

int main() {
  double balance = 0;
  int choice;
  
  cout << "*-*-*-*-*- JIJI BANK -*-*-*-*-*" << '\n';
  
  do {
    cout << "Select option:" << '\n';
    cout << "_ - _ - _ - _ "<< '\n';
    cout << "1. Show account balance" << '\n';
    cout << "2. Deposit money" << '\n';
    cout << "3. Withdraw cash" << '\n';
    cout << "4. Exit" << '\n';
    cin >> choice;
    
    cin.clear();
    fflush (stdin);
    
    switch (choice){
      case 1:
        showBalance(balance);
        break;
      case 2:
        balance += deposit();
        showBalance(balance);
        break;
      case 3:
        balance -= withdraw(balance);
        showBalance(balance);
        break;
      case 4:
        cout << "Thank you for using Jiji Bank" << '\n';
        break;
      default:
        cout << "Invalid choice!" << '\n';
    }
  }
  while (choice != 4);
  
  
  return 0;
}

void showBalance(double balance) {
  cout << "Your account balance is: KSH" << setprecision(2) << fixed << balance << '\n';
}

double deposit(){
  double amount = 0;
  
  cout << "Enter the amount to be deposited:" << '\n';
  cin >> amount;
  
  if (amount < 0){
    cout << "Enter a valid amount!" << '\n';
    return 0;
  }
  else {
    return amount;
  }
}

double withdraw (double balance){
  double amount = 0;
  
  cout << "Enter the amount to be withdrawn:" << '\n';
  cin >> amount;
  
  if (amount < 0){
    cout << "Enter a valid amount!" << '\n';
    return 0;
  }
  else if (amount > balance){
    cout << "Insufficient funds!" << '\n';
    return 0;
  }
  else {
    return amount;
  }
}