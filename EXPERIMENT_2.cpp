#include <iostream>
using namespace std;
int main(){
    cout << "Welcome to the game" << endl;
    int a = 7;
    int b = 0;
    cout << "Do you want to play?" << endl << "if YES type y else n: ";
    char c;
    cin >> c;
    int count = 0;
    if(c == 'y' || c == 'Y'){ // added 'Y' for case insensitivity
        while(b != a){
            cout << "Please select a number b/w 1 to 10: ";
            cin >> b;
            if(b < 1 || b > 10){ // added input validation
                cout << "Invalid input. Please enter a number between 1 and 10." << endl;
                continue;
            }
            if(b == a){
                cout << "Your guess number is correct" << endl;
                count++;
                break;
            }
            else if(b > a){
                cout << "Your guess number is higher" << endl << "Try again!" << endl;
            }
            else{
                cout << "Your guess number is lower" << endl << "Try again!" << endl;
            }
            count++;
        }
        cout << "The no. of count in which we got our guess number: " << count << endl;
        cout << "Game ends...!" << endl;
    }
    else{
        cout << "We think you are not intrested in playing so thanks for your visit..!" << endl;
    }
    return 0; // added return statement
}