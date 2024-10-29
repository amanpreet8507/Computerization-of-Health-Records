//
//  main.cpp
//  Computerization of Health Records
//
//  Created by Amanpreeet Sandhu on 2024-10-26.
//

#include <iostream>
#include "HealthProfile.h"

using namespace std;

int main() {
    string firstName, lastName, gender;
    int month, day, year;
    double heightInInches, weightInPounds;
    
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter gender: ";
    cin >> gender;
    cout << "Enter birth month(1-12): ";
    cin >> month;
    cout << "Enter birth day(1-31): ";
    cin >> day;
    cout << "Enter birth year: ";
    cin >> year;
    cout << "Enter height in inches: ";
    cin >> heightInInches;
    cout << "Enter weight in pounds: ";
    cin >> weightInPounds;
    
    HealthProfile profile1(firstName, lastName, gender, month, day, year, heightInInches, weightInPounds);
    profile1.displayProfile();
    
    // Output the BMI values chart
    cout << "BMI values chart: " << endl;
   cout << "Underweight: less than 18.5" << endl ;
   cout << "Normal : between 18.5 and 24.9"  << endl;
   cout << "Overweight : between 25 and 29.9"  << endl;
   cout << "Obese: 30 or greater" << endl;
       
}
