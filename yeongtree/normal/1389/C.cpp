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
        int ans = 0;
        for(char i = '0'; i <= '9'; ++i)
        {
            for(char j = '0'; j <= '9'; ++j)
            {
                bool flag = true;
                int cnt = 0;
                for(auto x : s) if((flag ? i : j) == x) flag = !flag, ++cnt;
                ans = max(ans, cnt / 2 * 2);
            }
        }
        for(char i = '0'; i <= '9'; ++i)
        {
            int cnt = 0;
            for(auto x : s) if(x == i) ++cnt;
            ans = max(ans, cnt);
        }
        cout << s.size() - ans << '\n';
    }
}