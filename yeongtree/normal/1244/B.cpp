#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        string s; cin >> s;
        int ans = n;
        int l = 0;
        while(l < n && s[l] == '0') ++l;
        if(l != n) ans = min(ans, l);
        int r = 0;
        while(r < n && s[n - r - 1] == '0') ++r;
        if(r != n) ans = min(ans, r);
        if(ans == n) cout << n << '\n';
        else cout << 2 * (n - ans) << '\n';
    }

    return 0;
}