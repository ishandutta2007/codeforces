#include <bits/stdc++.h>
using namespace std;

int main () {
    vector<int> xx, yy;
    int x[6], y[6];
    for (int i = 0; i < 6; ++i) {
        cin >> x[i] >> y[i];
        x[i] <<= 1;
        y[i] <<= 1;
        xx.push_back(x[i]); xx.push_back(x[i] - 1); xx.push_back(x[i] + 1);
        yy.push_back(x[i]); yy.push_back(x[i] - 1); yy.push_back(x[i] + 1);
        xx.push_back(y[i]); xx.push_back(y[i] - 1); xx.push_back(y[i] + 1);
        yy.push_back(y[i]); yy.push_back(y[i] - 1); yy.push_back(y[i] + 1);
    }
    for (int i: xx) {
        for (int j: yy) {
            if (x[0] <= i && i <= x[1] && y[0] <= j && j <= y[1]) {
                if (x[2] <= i && i <= x[3] && y[2] <= j && j <= y[3]) continue;
                if (x[4] <= i && i <= x[5] && y[4] <= j && j <= y[5]) continue;
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}