/*
Name: Krystal Brown
Course: CS 210 – Programming Languages
Project: Airgead Banking Investment Calculator
Date: October 5, 2025
Description: This file contains the method implementations for the
             InvestmentCalculator class. It includes logic for input validation,
             compound interest calculations, and formatted report generation
             based on user input.
*/

#include "InvestmentCalculator.h"

// Constructor initializes all values to zero
InvestmentCalculator::InvestmentCalculator() {
    initialInvestment = 0.0;
    monthlyDeposit = 0.0;
    annualInterestRate = 0.0;
    numberOfYears = 0;
}

// Helper method to check if a value is positive
bool InvestmentCalculator::isPositive(double value) {
    return value > 0;
}

// Prompt the user for investment details with input validation
void InvestmentCalculator::getUserInput() {
    cout << "==========================================" << endl;
    cout << "Welcome to the Airgead Banking Investment Calculator" << endl;
    cout << "==========================================" << endl;

    // Initial Investment
    cout << "Enter Initial Investment Amount: $";
    cin >> initialInvestment;
    while (!isPositive(initialInvestment)) {
        cout << "Please enter a positive amount: $";
        cin >> initialInvestment;
    }

    // Monthly Deposit
    cout << "Enter Monthly Deposit: $";
    cin >> monthlyDeposit;
    while (!isPositive(monthlyDeposit)) {
        cout << "Please enter a positive amount: $";
        cin >> monthlyDeposit;
    }

    // Annual Interest Rate
    cout << "Enter Annual Interest Rate (e.g., 5 for 5%): ";
    cin >> annualInterestRate;
    while (!isPositive(annualInterestRate)) {
        cout << "Please enter a positive interest rate: ";
        cin >> annualInterestRate;
    }

    // Number of Years
    cout << "Enter Number of Years: ";
    cin >> numberOfYears;
    while (numberOfYears <= 0) {
        cout << "Please enter a positive number of years: ";
        cin >> numberOfYears;
    }

    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

// Display report without monthly deposits
void InvestmentCalculator::displayReportWithoutMonthlyDeposit() {
    double balance = initialInvestment;
    double interestEarned;

    cout << "\n\n     Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "=================================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    for (int year = 1; year <= numberOfYears; ++year) {
        interestEarned = balance * (annualInterestRate / 100);
        balance += interestEarned;

        cout << year << "\t$" << fixed << setprecision(2) << balance
            << "\t\t$" << interestEarned << endl;
    }
}

// Display report with monthly deposits
void InvestmentCalculator::displayReportWithMonthlyDeposit() {
    double balance = initialInvestment;
    double interestEarned;
    double monthlyInterestRate = (annualInterestRate / 100) / 12;

    cout << "\n\n     Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "=================================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
    cout << "-----------------------------------------------------------------" << endl;

    for (int year = 1; year <= numberOfYears; ++year) {
        interestEarned = 0.0;

        for (int month = 1; month <= 12; ++month) {
            balance += monthlyDeposit;
            double monthlyInterest = balance * monthlyInterestRate;
            interestEarned += monthlyInterest;
            balance += monthlyInterest;
        }

        cout << year << "\t$" << fixed << setprecision(2) << balance
            << "\t\t$" << interestEarned << endl;
    }
}