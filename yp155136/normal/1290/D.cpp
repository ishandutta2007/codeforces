#include <bits/stdc++.h>
using namespace std;

const int N = 1036;
bool a[N];

bool ask(int x) {
    cout << "? " << x + 1 << endl;
    char c; cin >> c;
    if (c == 'Y') return false;
    else return true;
}

int main () {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        a[i] = true;
    }
    //k: block size
    for (int i = 0; i < n / k; ++i) {
        cout << "R" << endl;
        int del = 0;
        for (int j = 0; j < n / k; ++j) {
            int now = (i + del + (n / k)) % (n / k);
            for (int x = k * now; x < k * (now + 1); ++x) {
                if (a[x]) {
                    a[x] = ask(x);
                }
            }
            if (del < 0) del = -del;
            else {
                ++del;
                del = -del;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i];
    }
    cout << "! " << ans << endl;
}