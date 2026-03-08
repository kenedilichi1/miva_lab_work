#include <iostream>

using namespace std;

/*
    Base Case: 
            1.  n <= 1: Return n (0th and 1st terms are themselves).
    
    Recursive Case: 
        1.  Return the sum of recursive calls to (n-1) and (n-2).
*/
int recursiveFib(int n) {

	// If n is 1 or 0, then return n, 
  	// works for 0th and 1st terms
    if (n <= 1)
        return n;

    // Recurrence relation to find 
  	// the rest of the terms
    return recursiveFib(n - 1) + recursiveFib(n - 2);
}

int main() {
    int inputtedNumber;
    cout << "Enter the term number to find in Fibonacci sequence: ";
    cin >> inputtedNumber;
  
  	// Finding nth term
    cout << "The " << inputtedNumber << "th term in the Fibonacci sequence is: " << recursiveFib(inputtedNumber) << endl;
    return 0;
}