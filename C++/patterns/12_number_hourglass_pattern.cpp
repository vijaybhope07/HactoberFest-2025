#include <bits/stdc++.h>
using namespace std;

void print12(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            if (j <= i) {
                cout << j << " ";
            } else if (j >= 2 * n - i + 1) {
                cout << 2 * n - j + 1 << " ";
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
    print12(n);
    return 0;
}