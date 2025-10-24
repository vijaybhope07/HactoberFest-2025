#include <bits/stdc++.h>
using namespace std;

void print8(int n) {
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    print8(n);
    return 0;
}