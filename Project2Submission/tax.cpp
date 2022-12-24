//Ishaan Gupta
//UID: 905917973

#include <iostream>
using namespace std;

int main()
{
    
    //declaring the 4 variables that we will get from the user
    string name;
    double taxableIncome;
    string occupation;
    int numberOfChildren;
    
    //asking for inputs and storing inputs
    cout << "Name: ";
    getline(cin, name);
    
    cout << "Taxable income: ";
    cin >> taxableIncome;
    cin.ignore(10000, '\n');
    
    cout << "Occupation: ";
    getline(cin, occupation);
    
    cout << "Number of children: ";
    cin >> numberOfChildren;
    
    cout << "---" << endl;
    
    //check for erroneous cases
    if (name == "")
    {
        cout << "You must enter a name" << endl;
    }
    else if (taxableIncome < 0)
    {
        cout << "The taxable income must not be negative" << endl;
    }
    else if (occupation == "")
    {
        cout << "You must enter an occupation" << endl;
    }
    else if (numberOfChildren < 0)
    {
        cout << "The number of children must not be negative" << endl;
    }
    
    //if no erroneous cases calculate tax based on income
    else
    {
        double tax = 0;
        double tempTaxableIncome = taxableIncome;
        
        //start with wealthiest tax bracket and work our way down towards the poorest bracket
        if (tempTaxableIncome > 125000)
        {
            tax += (tempTaxableIncome - 125000) * 0.093;
            tempTaxableIncome = 125000;
        }
        if (tempTaxableIncome > 55000)
        {
            //checking occupation for teacher or nurse and deciding tax rate
            if (occupation == "teacher" || occupation == "nurse")
            {
                tax += (tempTaxableIncome - 55000) * 0.05;
            }
            else
            {
                tax += (tempTaxableIncome - 55000) * 0.07;
            }
            tempTaxableIncome = 55000;
        }
        tax += (tempTaxableIncome) * 0.04;
        
        //subtracting from tax based on the number of children
        if (taxableIncome < 125000)
        {
            tax -= numberOfChildren * 200;
        }
        
        //if the tax is negative just make it zero
        if (tax < 0)
        {
            tax = 0;
        }
        
        cout.setf(ios::fixed);
        cout.precision(2);
        
        cout << name << " would pay $" << tax << endl;
        
    }
}
