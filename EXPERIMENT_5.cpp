#include <iostream>
#include <algorithm>  // For sort function
using namespace std;

int main() {
    string input;

    cout << "Enter a string: ";
    cin >> input;

    // Sort the string in alphabetical order
    sort(input.begin(), input.end());

    cout << "String in alphabetical order: " << input << endl;

    return 0;
}