#include <bits/stdc++.h>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

ll d[100100];

int main() {
    int n;
    cin >> n;
    for (int i = 2; i < (1<<(n+1)); i++) {
        cin >> d[i];
    }
    ll res = 0;
    for (int i = (1<<n)-1; i >= 1; i--) {
        res += max(d[i*2], d[i*2+1]) - min(d[i*2], d[i*2+1]);
        d[i] += max(d[i*2], d[i*2+1]);
    }
    cout << res << endl;
    return 0;
}