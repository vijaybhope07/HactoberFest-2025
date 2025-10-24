#include <bits/stdc++.h>
using namespace std;

void print7(int n) {
    int a;
    for (int i = 1; i <= n; i++) {
        a = 2 * i - 1;
        for (int j = 1; j <= 2 * n - 1; j++) {
            if (j <= n - i) {
                cout << " ";
            } else if (a != 0) {
                cout << "*";
                a--;
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    print7(n);
    return 0;
}