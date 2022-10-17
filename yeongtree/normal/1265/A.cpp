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
        int n = s.size();
        bool __flag = false;
        for(int i = 1; i < n; ++i)
        {
            if(s[i - 1] == s[i] && s[i] != '?') {__flag = true; cout << "-1\n"; break;}
        }
        if(__flag) continue;

        bool flag[3];
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '?')
            {
                flag[0] = flag[1] = flag[2] = true;
                if(i > 0 && s[i - 1] == 'a') flag[0] = false;
                if(i > 0 && s[i - 1] == 'b') flag[1] = false;
                if(i > 0 && s[i - 1] == 'c') flag[2] = false;
                if(i < n - 1 && s[i + 1] == 'a') flag[0] = false;
                if(i < n - 1 && s[i + 1] == 'b') flag[1] = false;
                if(i < n - 1 && s[i + 1] == 'c') flag[2] = false;
                for(int j = 0; j < 3; ++j) if(flag[j])
                {
                    s[i] = 'a' + j;
                    break;
                }
            }
        }

        cout << s << '\n';
    }
}