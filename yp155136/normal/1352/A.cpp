#include <bits/stdc++.h>
using namespace std;

void go() {
    int n; cin >> n;
    vector<int> v;
    int pre = 1;
    while (n > 0) {
        int x = n % 10;
        n /= 10;
        if (x != 0) {
            v.push_back(x * pre);
        }
        pre *= 10;
    }
    cout << v.size() <<endl;
    for (int i: v) cout << i << ' ';
    cout << endl;
}

int main () {
    int T; cin >> T;
    while (T--) {
        go();
    }
}