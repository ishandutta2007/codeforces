#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        string s[n];
        for(auto &i : s) cin >> i;
        int cnt1 = 0, cnt2 = 0;
        for(auto &i : s)
        {
            if(i.size() & 1) ++cnt1;
            for(auto j : i) if(j == '0') ++cnt2;
        }
        if(cnt1 == 0 && (cnt2 & 1)) cout << n - 1 << '\n';
        else cout << n << '\n';
    }

    return 0;
}