#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        bool flag[26]{};
        string s; cin >> s;
        for(int i = 0; i < s.size(); ++i)
        {
            if(i + 1 != s.size() && s[i] == s[i + 1])
            {
                ++i;
            }
            else
            {
                flag[s[i] - 'a'] = true;
            }
        }
        for(int i = 0; i < 26; ++i) if(flag[i]) cout << (char)(i + 'a');
        cout << '\n';
    }

    return 0;
}