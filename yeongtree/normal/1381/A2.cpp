#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        vector<int> ans;
        int f = 1;
        int a = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            if((s[a + i * f] == t[i]) == (f == 1)) continue;
            if(s[a] != s[a + i * f]) ans.push_back(0), s[0] = '0' + '1' - s[0];
            ans.push_back(i); a += i * f; f = -f;
        }
        cout << ans.size() << ' ';
        for(auto i : ans) cout << i + 1 << ' ';
        cout << '\n';
    }
}