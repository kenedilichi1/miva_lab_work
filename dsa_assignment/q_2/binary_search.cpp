#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A recursive binary search function. It returns
// location of x in given array arr[low..high] is present,
// otherwise -1

/*
    Base Case: 
            1.  low > high: The search range has collapsed, meaning the element is not in the array (return -1).
            2.  arr[mid] == target: We found the element! (return the index).

    Recursive Case: 
        1.  If target < arr[mid], call the function again on the left half (low to mid - 1).
        2.  If target > arr[mid], call the function again on the right half (mid + 1 to high).
*/
int recursiveBinarySearch(vector<int> &arr, int lowest_index, int highest_index, int search_element) {
    

    if (lowest_index > highest_index) {
            return -1;
    }

    int mid = lowest_index + (highest_index - lowest_index) / 2;

    // If the element is present at the middle
    // itself
    if (arr[mid] == search_element){
        return mid;
    }

    // If element is smaller than mid, then
    // it can only be present in left subarray
    if (arr[mid] > search_element){

        return recursiveBinarySearch(arr, lowest_index, mid - 1, search_element);
    }
    
    // Else the element can only be present
    // in right subarray    
    return recursiveBinarySearch(arr, mid + 1, highest_index, search_element);
 
}

int main() {
    vector<int> arr = {91,2, 5, 8,23, 12, 16, 38, 56, 72};

    vector<int> copiedArr(arr.begin(), arr.end());

    sort(copiedArr.begin(), copiedArr.end());

    int query = 10;
    int n = copiedArr.size();
    cout << "Search for 23: Index " << recursiveBinarySearch(copiedArr, 0, n - 1, 23) << endl;

    // Test Case 2: Element at the boundary (Edge Case)
    cout << "Search for 2: Index " << recursiveBinarySearch(copiedArr, 0, n - 1, 2) << endl;

    // Test Case 3: Element not present (Edge Case)
    cout << "Search for 100: Index " << recursiveBinarySearch(copiedArr, 0, n - 1, 100) << endl;

    // Test Case 4: Empty array (Edge Case)
    vector<int> emptyVec;
    cout << "Search in empty array: " << recursiveBinarySearch(emptyVec, 0, (int)emptyVec.size() - 1, 5) << endl;
    return 0;
}