#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int months;
    double annual_tax_rate;
    double balance;
    
    cout << "Enter initial account balance: ";
    cin >> balance;
    while (balance <= 0){
        cout << "Initial balance should be more than 0. " << endl;
        cout << "Enter a valid balance amount: ";
        cin >> balance;
    }

    cout << "Enter annual tax deduction rate (in percentage): ";
    cin >> annual_tax_rate;
    cout << "Enter total number of months since account opened: ";
    cin >> months;
    while (months <= 0){
        cout << "Enter data for at least 1 month(s): " << endl;
        cout << "Enter a valid number of months: ";
        cin >> months;
    } 

    double monthly_tax_rate = (annual_tax_rate / 100) / 12;
    double deposits[months];
    double withdrawals[months];
    double tax_deductions[months];

    double total_deposits = 0;
    double total_withdrawals = 0;
    double total_tax = 0;

    for (int i = 0; i < months; i++){
        cout << "\n--- Month " << i + 1 << "---\n";

        do {
            cout << "Enter deposit amount: ";
            cin >> deposits[i];
            if (deposits[i] < 0)
                cout << "Invalid input! Deposit cannot be negative.\n";

        } while (deposits[i] < 0);

        balance += deposits[i];
        total_deposits += deposits[i];

        do {
            cout << "Enter withdrawal amount: ";
            cin >> withdrawals[i];
            if (withdrawals[i] < 0) 
                cout << "Invalid input! Withdrawal cannot be negative.\n";
        } while (withdrawals[i] < 0);

        balance -= withdrawals[i];
        total_withdrawals += withdrawals[i];

        tax_deductions[i] = balance * monthly_tax_rate;
        balance -= tax_deductions[i];
        total_tax += tax_deductions[i];
    }

    cout << "\n\t------ ACCOUNT SUMMARY ------\n";
    cout << fixed << setprecision(2);
    cout << "Final Account Balance: \t" << balance << endl;
    cout << "Total Deposited: \t" << total_deposits << endl;
    cout << "Total Withdrawn: \t" << total_withdrawals << endl;
    cout << "Total Tax Deducted: \t" << total_tax << endl;
    cout << "\nThank you for using our program! Have a nice day!";

    return 0;
}