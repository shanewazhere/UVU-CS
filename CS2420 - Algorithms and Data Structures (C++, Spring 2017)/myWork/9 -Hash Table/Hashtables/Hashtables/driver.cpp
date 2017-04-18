
//Hash Tables - project 9 - 04/17/2017
//Max Nelson
//Section 002
//driver.cpp
//I Max Nelson have not used any code other than my own(or that in the textbook) for this project.
//I also have not used any function or data - structure from the Standard - Template Library.
//The standard library for C++ is fine.I also have not shared my code with any student in this class.
//I understand that any violation of this disclaimer will result in a 0 for the project.

//class: driver.cpp

#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//precondition: formula string
//postcondition: molecular weight of formula is calculated
double calcWeight(string formula);

//hashtable object to store our periodic table of elements
HashTable table;

int main () {
    cout << "Max Nelson CS2420 002 Hash Tables - project 9 - 04/17/2017";
    //read in periodic table of elements
    //insert them
    string line;
    ifstream myfile ("PeriodicTableElements.txt");
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            string element;
            myfile >> element;
            double weight;
            myfile >> weight;
            //cout << "e: " << element << " w: " << weight << endl;
            table.Insert(element, weight);
        }
        myfile.close();
    }
    
    //retrieve formulas and calculate their molecular weight
    cout << endl << endl << "Formulas and their molecular weight: " << endl << endl;
    
    string formulaline;
    ifstream formulafile ("formulas.txt");
    if (formulafile.is_open())
    {
        while ( formulafile.good() )
        {
           
            string formula;
            formulafile >> formula;
            
            cout << left << setw(20) << formula << calcWeight(formula) << endl;
            
        }
        formulafile.close();
        cout << endl << "end of file" << endl;
    }
    
    
    
    else cout << "Unable to open file";
    
	system("pause");
    return 0;
}

//precondition: formula string
//postcondition: molecular weight of formula is calculated
double calcWeight(string formula) {
    double weight = 0;
    
    string element = "";
    string multiply = "";
    
    for (int i = 0; i < formula.length();) {
        if (formula[i] == '(') {
            i++;
            string tempFormula = "";
            string tempMultiply = "";
            while (formula[i] != ')') {
                tempFormula += formula[i];
                i++;
            }
            i++;
            while(isdigit(formula[i])) {
                tempMultiply += formula[i];
                i++;
            }
            if(tempMultiply == "") {
                weight += calcWeight(tempFormula);
            } else {
                weight += calcWeight(tempFormula) * stod(tempMultiply);
            }
            
        } else {
            string tempElement = "";
            string tempMult = "";
            if (isupper(formula[i])) {
                tempElement += formula[i];
                i++;
            }
            while(islower(formula[i])) {
                tempElement += formula[i];
                i++;
            }
            
            while(isdigit(formula[i])) {
                tempMult += formula[i];
                i++;
            }
            
            if(tempMult == "") {
                weight += table.Retrieve(tempElement);
            } else {
                weight += table.Retrieve(tempElement) * stod(tempMult);
            }
        }
    }
    return weight;
}


