#include <iostream>

using namespace std;

int main()
{
    int n, m, k; cin >> n >> m >> k;
    int a[n], b[m];
    for(int &i : a) cin >> i; for(int &i : b) cin >> i;

    int mn = a[0];
    for(int i = 1; i < n; ++i) if(mn > a[i]) mn = a[i];
    int mx = b[0];
    for(int i = 1; i < m; ++i) if(mx < b[i]) mx = b[i];

    if(mn >= mx) cout << k;
    else cout << (k % mn) + (k / mn * mx);
    return 0;
}