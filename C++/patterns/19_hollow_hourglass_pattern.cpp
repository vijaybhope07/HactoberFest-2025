#include <bits/stdc++.h>
using namespace std;

void print19(int n) {
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= 2 * n; j++) {
            if (j <= i) {
                cout << "* ";
            } else if (j >= 2 * n - i + 1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            if (j <= i) {
                cout << "* ";
            } else if (j >= 2 * n - i + 1) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    print19(n);
    return 0;
}