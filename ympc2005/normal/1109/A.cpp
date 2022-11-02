#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

int n, a[N];

map <int, int> mp[2];

ll ans;

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    mp[0][0]++;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
        a[i] ^= a[i - 1];
        ans += mp[i&1][a[i]]++;
    }

    cout<<ans<<'\n';
}