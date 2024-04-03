#include <iostream>
using namespace std;

int main() {
    const int maxSize = 20;
    int numbers[maxSize];
    int count = 0;

    cout << "Enter a series of one-digit positive numbers (-1 to end):" << endl;

    // Read numbers until -1 is entered or the array is full
    while (count < maxSize) {
        int num;
        cin >> num;

        if (num == -1)
            break;

        if (num >= 0 && num <= 9) {
            numbers[count] = num;
            count++;
        } else {
            cout << "Invalid number! Please enter a one-digit positive number or -1 to end." << endl;
        }
    }

    // Display the entered numbers
    cout << "Entered numbers: ";
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    int sum1 = 0;
    int sum2 = 0;
    for (int i = count - 1; i >= 0; i--) {
        int digit = numbers[i];

        if ((count - i) % 2 == 0) {
            int doubledDigit = digit * 2;
            if (doubledDigit > 9) {
                // Add the digits of the doubled number
                doubledDigit = (doubledDigit % 10) + (doubledDigit / 10);
            }
            sum1 += doubledDigit;
        } else {
            sum2 += digit;
        }
    }

    int totalSum = (sum1 + sum2) * 9;
    int checksum = totalSum % 10;

    cout << "Sum of doubled numbers: " << sum1 << endl;
    cout << "Sum of all other numbers: " << sum2 << endl;
    cout << "Total sum: " << totalSum << endl;
    cout << "Checksum: " << checksum << endl;

    return 0;
}
