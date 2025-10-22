/*/Name: Krystal Brown
  Course: CS 210 – Programming Languages
  Project: Airgead Banking Investment Calculator
  Date: October 5, 2025
  Description: This file contains the [main logic / class definition]
               for calculating investment growth with and without
               monthly deposits using compound interest. **/

#include <iostream>
#include "InvestmentCalculator.h"

using namespace std;

int main() {
    // Create an object of the InvestmentCalculator class
    InvestmentCalculator calculator;

    // Step 1: Prompt the user for investment details
    calculator.getUserInput();

    // Step 2: Display report without monthly deposits
    calculator.displayReportWithoutMonthlyDeposit();

    // Step 3: Display report with monthly deposits
    calculator.displayReportWithMonthlyDeposit();

    // Step 4: End program with a friendly message
    cout << "\nThank you for using the Airgead Banking Investment Calculator!" << endl;

    return 0;
}