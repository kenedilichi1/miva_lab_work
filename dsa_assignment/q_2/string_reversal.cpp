#include <iostream>
#include <string>

using namespace std;

/*
    Base Case: 
            1.  index == n: We have reached the end of the string, so we return (stop recursion).
    
    Recursive Case: 
        1.  Store the current character in a temporary variable 'temp'.
        2.  Make a recursive call to the next character (index + 1).
        3.  After the recursive call returns, print 'temp'. This way, characters are printed in reverse order as the stack unwinds.
*/
void recursiveStringReverse(char *str, int index, int n) 
{

    if(index == n) 
    {
        return;
    }

    char temp = str[index];    // Store the current character in this function's stack frame
    recursiveStringReverse(str, index+1, n);  // Move to the next character
    cout << temp;              
}

int main()
{
    string input;
    cout << "Enter a string to reverse: ";
    getline(cin, input); 

    int n = input.length();
    
    
    recursiveStringReverse(&input[0], 0, n);
    cout << endl;

    return 0;
}