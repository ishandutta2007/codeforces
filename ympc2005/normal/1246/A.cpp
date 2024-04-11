#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, p;

int main() {
    cin>>n>>p;

    for (int i = 1; i <= 40; i++) {
        ll m = n - i*p;

        if (m < 0) {
            continue;
        }

        int cnt = 0;

        for (int j = 0; j < 40; j++) {
            if (m&(1ll<<j)) {
                cnt++;
            }
        }

        if (cnt <= i && i <= m) {
            cout<<i<<'\n';
            exit(0);
        }
    }

    cout<<-1<<'\n';
}