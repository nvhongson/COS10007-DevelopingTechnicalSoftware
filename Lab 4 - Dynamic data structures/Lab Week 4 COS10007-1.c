#include <iostream>

using namespace std;

// function prototypes
int doubleByValue(int);
void doubleByReference(int&);

int main() {
    int count = 5; //hardcoded this for output 
    cout << "Original value of count: " << count << endl;
    
    // double the value of count using doubleByValue
    int newCount = doubleByValue(count);
    cout << "Value of count after doubleByValue: " << newCount << endl;
    
    // double the value of count using doubleByReference
    doubleByReference(count);
    cout << "Value of count after doubleByReference: " << count << endl;
    
    return 0;
}

// function that doubles a value passed by value
int doubleByValue(int count) {
    return count * 2;
}

// function that doubles a value passed by reference
void doubleByReference(int& count) {
    count *= 2;
}
