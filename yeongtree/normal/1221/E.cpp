#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int a, b; cin >> a >> b;
        string s; cin >> s;
        vector<int> v;
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == 'X')
            {
                if(i > 0 && s[i - 1] == '.')
                {
                    v.push_back(cnt);
                    cnt = 0;
                }
                cnt = 0;
            }
            else ++cnt;
        }
        if(s.back() == '.') v.push_back(cnt);

        int lag = 0;
        int flag = 0;
        int fflag = 0;
        int k = 0;
        for(auto i : v)
        {
            if(b <= i && i < a) ++lag;
            else if(a <= i && i < 2 * b) ++flag;
            else if(a <= i) ++fflag, k = i;
        }

        if(lag) cout << "NO\n";
        else if(fflag >= 2) cout << "NO\n";
        else if(fflag)
        {
            if(a < 2 * b)
            {
                if((flag & 1) && 2 * a <= k && k < a + 3 * b - 1) cout << "YES\n";
                else if(flag & 1) cout << "NO\n";
                else if(k < a + 2 * b - 1) cout << "YES\n";
                else if(3 * a <= k && k < a + 4 * b - 1) cout << "YES\n";
                else cout << "NO\n";
            }
            else
            {
                if(k < a + 2 * b - 1) cout << "YES\n";
                else cout << "NO\n";
            }
        }
        else
        {
            if(flag & 1) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}