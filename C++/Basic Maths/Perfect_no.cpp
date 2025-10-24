#include <iostream>
using namespace std;

bool isPerfect(int num) {
    if (num <= 0) {
        return false;
    }
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (cin.fail() || num <= 0) {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }
    if (isPerfect(num))
        cout << num << " is a perfect number." << endl;
    else
        cout << num << " is not a perfect number." << endl;
    return 0;
}
