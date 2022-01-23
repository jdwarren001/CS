//
//  main.cpp
//  Practicum_2.2
//
//  Created by Jackson Warren on 8/28/19.
//  Copyright © 2019 Jackson Warren. All rights reserved.
//

/* You found an exciting summer job for five weeks. It pays, say, $15.50 per hour. Suppose that the total tax you pay on your summer job income is 14%. After paying the taxes, you spend 10% of your net income to buy new clothes and other accessories for the next school year and 1% to buy school supplies. After buying clothes and school supplies, you use 25% of the remaining money to buy savings bonds. For each dollar you spend to buy savings bonds, your parents spend $0.50 to buy additional savings bonds for you. Write a program that prompts the user to enter the pay rate for an hour and the number of hours you worked each week. The program then outputs the following:
 a. Your income before and after taxes from your summer job.
 b. The money you spend on clothes and other accessories.
 c. The money you spend on school supplies.
 d. The money you spend to buy savings bonds.
 e. The money your parents spend to buy additional savings bonds for you. */


#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    float pay, hours, tax_pay,wage, clothes_spending, books, remaining, daddy;
    
// a.
    
    cout << "What is your pay per hour? \n Pay: ";
    cin >> wage;
    
    cout << "How many hours do you work per week? \n Hours: ";
    cin >> hours;
    
    pay = wage*hours*5;
    tax_pay = pay - (pay*.14);
    cout << "You will be paid: $" << pay << " before taxes and $" << tax_pay << " after taxes."<< endl;
    
// b. and c.
    clothes_spending = tax_pay*.10;
    books = tax_pay*.01;
    cout << "You will be spend a totol of $" << clothes_spending << " on clothes and $" << books << " on books." << endl;
    
// d.
    remaining = (tax_pay-books-clothes_spending)*.25;
    cout << "You then will put $" << remaining << " into saving bonds." << endl;
    
// e.
    daddy = remaining*.50;
    cout << "Your parents give you $0.50 for every dollar you put in to your saving bonds. They give you $" << daddy << endl << endl;
    
    

return 0;
}
