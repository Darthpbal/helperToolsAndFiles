/*

This program is made to read a "payroll.txt" file in the same folder as the 
program itself. The program reads payroll.txt which contains employee information 
and pay rate information. The program then calculates how much money should be on 
a person's paycheck, and creates a text file called "paycheck.txt"

to run this successfully, the program you make needs to be in the same file as
the "payroll.txt" and there MUST be NO "paycheck.txt" file. SO if you run the 
program, it will make that file, so you'll have to delete "paycheck.txt" before running
the program again.

*/
// -------------------------------------------------------------------------------------------------
// TEST CASE 1:
// -------------------------------------------------------------------------------------------------
// Test Input Data:
// Simpson Homer
// 15.25 84
// 2
//
// Expected Results:
// -----------------------------
// EMPLOYEE: Simpson, Homer
//
// PAY RATE:           $   15.25
// HOURS:                  84.00
// GROSS PAY:          $ 1311.50
// MED INS DEDUCT:     $  110.13
// 401K DEDUCT:        $   78.69
// FED TAX GROSS PAY:  $ 1122.68
// TAX - FEDERAL:      $   89.48
// TAX - OASDI:        $   69.61
// TAX - MEDICARE:     $   16.28
// TAX - STATE:        $   38.62
// TAX - TOTAL:        $  213.98
// NET PAY:            $  908.70
// -----------------------------
//
// Test Results: <PASSED>
//
// -------------------------------------------------------------------------------------------------
// TEST CASE 2:
// -------------------------------------------------------------------------------------------------
// Test Input Data:
// Murcury Reggie
// 20.10 48.25
// 0
//
// Expected Results:
// -----------------------------
// EMPLOYEE: Murcury, Reggie
//
// PAY RATE:           $   20.10
// HOURS:                  48.25
// GROSS PAY:          $   969.82
// MED INS DEDUCT:     $   32.16
// 401K DEDUCT:        $   58.18
// FED TAX GROSS PAY:  $   879.48
// TAX - FEDERAL:      $   70.09
// TAX - OASDI:        $   54.52
// TAX - MEDICARE:     $   12.75
// TAX - STATE:        $   10.46
// TAX - TOTAL:        $   147.82
// NET PAY:            $   731.66
// -----------------------------
//
// Test Results: <PASSED>
//
// -------------------------------------------------------------------------------------------------
// TEST CASE 2:
// -------------------------------------------------------------------------------------------------
// Test Input Data:
// Salemander Oliver
// 13.66 106
// 1
//
// Expected Results:
// -----------------------------
// EMPLOYEE: Salemander, Oliver
//
// PAY RATE:           $   13.66
// HOURS:                  106
// GROSS PAY:          $   1625.54
// MED INS DEDUCT:     $   64.97
// 401K DEDUCT:        $   97.53
// FED TAX GROSS PAY:  $   1463.04
// TAX - FEDERAL:      $   186.53
// TAX - OASDI:        $   90.70
// TAX - MEDICARE:     $   21.02
// TAX - STATE:        $   50.32
// TAX - TOTAL:        $   348.57
// NET PAY:            $   1114.47
// -----------------------------
//
// Test Results: <PASSED>
//**************************************************************************************************
#include <cstdlib>   // For exit()
#include <fstream>   // For ifstream, ofstream
#include <iomanip>   // For setprecision(), setw()
#include <iostream>  // For endl, fixed
#include <string>    // For string class

using namespace std;

const double OASDI_RATE = 0.062;

const double FOUR01K_RATE = 0.06;

const double MEDICARE_RATE = 0.0145;

const double MED_INS_DEDUCT_EMPL_ONLY = 32.16;  const double MED_INS_DEDUCT_EMPL_ONE  = 64.97;  const double MED_INS_DEDUCT_FAMILY    = 110.13;  
const int MED_INS_STATUS_EMPL_ONLY = 0;  const int MED_INS_STATUS_EMPL_ONE  = 1;  const int MED_INS_STATUS_FAMILY    = 2;  
void ErrorExit(string msg)
{
    cout << msg << endl;
    exit(-1);
}

double CalcGrossPay(double pPayRate, double pHrsWorked)
{
        double grossPay = 0;
    if(pHrsWorked <= 80){
        grossPay = pHrsWorked * pPayRate;
    }
    else{
        grossPay = (80 * pPayRate) + (pHrsWorked - 80) * (1.5 * pPayRate);
    }
    return grossPay;
}

double CalcMedInsDeduct(int pMedInsStatus)
{
        double medInsDeduct = 0;
    if(pMedInsStatus == MED_INS_STATUS_EMPL_ONLY){
        medInsDeduct = MED_INS_DEDUCT_EMPL_ONLY;
    }
    else if(pMedInsStatus == MED_INS_STATUS_EMPL_ONE){
        medInsDeduct = MED_INS_DEDUCT_EMPL_ONE;
    }
    else{
        medInsDeduct = MED_INS_DEDUCT_FAMILY;
    }
    return medInsDeduct;
}

double CalcTaxFed(double pFedTaxGrossPay)
{
    double taxFed = 0;
    if(pFedTaxGrossPay >= 384.62 && pFedTaxGrossPay < 1413.67 ){
        taxFed = 0.0797 * pFedTaxGrossPay;
    }
    else if(pFedTaxGrossPay >= 1413.67 && pFedTaxGrossPay < 2695.43 ){
        taxFed = 0.1275 *  pFedTaxGrossPay;
    }
    else if(pFedTaxGrossPay >= 2695.43 ){
        taxFed = 0.195 * pFedTaxGrossPay;
    }
    return taxFed;
}

double CalcTaxState(double pFedTaxGrossPay)
{
    double taxState = 0;
    if (pFedTaxGrossPay < 961.54) {
        taxState = pFedTaxGrossPay * 0.0119;
    } else if (pFedTaxGrossPay < 2145.66) {
        taxState = pFedTaxGrossPay * 0.0344;
    } else {
        taxState = pFedTaxGrossPay * 0.0774;
    }
    return taxState;
}

int main()
{
    ifstream fin("payroll.txt");

    if (!fin) {
        ErrorExit("Could not open 'payroll.txt' for reading.");
    }

    string firstName, lastName;
    fin >> lastName >> firstName;

    double payRate;
    fin >> payRate;

    double hrsWorked;
    fin >> hrsWorked;

    int medInsStatus;
    fin >> medInsStatus;

    fin.close();

    double grossPay = CalcGrossPay(payRate, hrsWorked);

    double four01kDeduct = grossPay * FOUR01K_RATE;

    double medInsDeduct = CalcMedInsDeduct(medInsStatus);

    double fedTaxGrossPay = grossPay - four01kDeduct - medInsDeduct ;

    double taxFed = CalcTaxFed(fedTaxGrossPay);

    double taxOASDI = OASDI_RATE * fedTaxGrossPay;

    double taxMedicare = MEDICARE_RATE * fedTaxGrossPay;

    double taxState = CalcTaxState(fedTaxGrossPay);

    double taxTotal = taxFed + taxOASDI + taxMedicare + taxState;

    double netPay = fedTaxGrossPay - taxTotal;

    ofstream fout("paycheck.txt");

    if (!fout) {
        ErrorExit("Could not open 'paycheck.txt' for writing.");
    }

    fout << fixed << setprecision(2);

    fout << right;

    fout << "-----------------------------"    << endl;
    fout << "EMPLOYEE: " << lastName << ", "   << firstName << endl << endl;
    fout << "PAY RATE:           $" << setw(8) << payRate << endl;
    fout << "HOURS:               " << setw(8) << hrsWorked << endl;
    fout << "GROSS PAY:          $" << setw(8) << grossPay << endl;
    fout << "MED INS DEDUCT:     $" << setw(8) << medInsDeduct << endl;
    fout << "401K DEDUCT:        $" << setw(8) << four01kDeduct << endl;
    fout << "FED TAX GROSS PAY:  $" << setw(8) << fedTaxGrossPay << endl;
    fout << "TAX - FEDERAL:      $" << setw(8) << taxFed << endl;
    fout << "TAX - OASDI:        $" << setw(8) << taxOASDI << endl;
    fout << "TAX - MEDICARE:     $" << setw(8) << taxMedicare << endl;
    fout << "TAX - STATE:        $" << setw(8) << taxState << endl;
    fout << "TAX - TOTAL:        $" << setw(8) << taxTotal << endl;
    fout << "NET PAY:            $" << setw(8) << netPay << endl;
    fout << "-----------------------------"    << endl;

    fout.close();

    return 0;
}
