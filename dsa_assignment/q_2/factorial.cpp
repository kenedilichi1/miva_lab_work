#include <iostream>
#include <limits>

using namespace std;

/*
    Base Case: 
            1.  number < 0: Factorial is not defined for negative numbers (return -1).
            2.  number == 0 or number == 1: The factorial of both 0 and 1 is 1 (return 1).

    Recursive Case: 
        For any number greater than 1, the factorial can be calculated as:
        recursiveFactorial(number) = number * recursiveFactorial(number - 1)
*/

long long recursiveFactorial(int number){

    if(number < 0){
        return -1;
    }

    if(number == 0 || number == 1){
        return 1;
    } 

    return number * recursiveFactorial(number - 1);
}

int main() {
    int inputtedNumber;

    while (true) {
        cout << "Enter a non-negative integer (max 20): ";
        
        // Check if the input is actually an integer
        if (cin >> inputtedNumber && inputtedNumber >= 0 && inputtedNumber <= 20) {
            break; // Valid input, exit the loop
        } else {
            cout << "Invalid input. ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
        }
    }

    long long result = recursiveFactorial(inputtedNumber);
    cout << "The factorial of " << inputtedNumber << " is: " << result << endl;

    return 0;
}