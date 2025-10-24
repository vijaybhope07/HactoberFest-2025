#include <bits/stdc++.h>
using namespace std;

void print22(int n) {
    int x1, x2, y1, y2;
    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            x1 = i;
            x2 = 2 * n - 2 - i;
            y1 = j;
            y2 = 2 * n - 2 - j;
            cout << n - min(min(x1, x2), min(y1, y2));
        }
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    print22(n);
    return 0;
}