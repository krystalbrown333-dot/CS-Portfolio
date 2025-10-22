/*
Name: Krystal Brown
Course: CS 210 – Programming Languages
Project: Airgead Banking Investment Calculator
Date: October 5, 2025
Description: This file contains the class declaration and method prototypes
             for the InvestmentCalculator class. It defines the structure
             for calculating investment growth with and without monthly deposits
             using compound interest.
*/

#ifndef INVESTMENTCALCULATOR_H
#define INVESTMENTCALCULATOR_H

#include <iostream>
#include <iomanip>  // For formatting currency output

using namespace std;

// This class models an investment calculator for Airgead Banking.
// It handles user input, compound interest calculations, and displays reports.
class InvestmentCalculator {
private:
    // These variables store the user's investment details
    double initialInvestment;     // Starting amount of the investment
    double monthlyDeposit;        // Amount added each month
    double annualInterestRate;    // Annual interest rate (as a percentage)
    int numberOfYears;            // Duration of investment in years

    // Helper method to validate that a number is positive
    bool isPositive(double value);

public:
    // Constructor initializes all values to zero
    InvestmentCalculator();

    // Prompts the user to enter investment details with input validation
    void getUserInput();

    // Displays a report showing year-end balances WITHOUT monthly deposits
    void displayReportWithoutMonthlyDeposit();

    // Displays a report showing year-end balances WITH monthly deposits
    void displayReportWithMonthlyDeposit();
};

#endif
