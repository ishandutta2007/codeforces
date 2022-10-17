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
        string s; cin >> s;
        int n = (int)s.size();
        int ans = 0;
        for(int i = 0; i < n - 1; ++i) if(s[i] != '?')
        {
            if(s[i] == s[i + 1])
            {
                ++ans;
                s[i + 1] = '?';
            }
            if(i < n - 2 && s[i] == s[i + 2])
            {
                ++ans;
                s[i + 2] = '?';
            }
        }
        cout << ans << '\n';
    }
}