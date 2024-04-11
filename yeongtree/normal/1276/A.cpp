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
        string s; cin >> s;
        int n = s.size();
        vector<int> ans;
        for(int i = 2; i < n; ++i)
        {
            if(s[i - 2] == 'o' && s[i - 1] == 'n' && s[i] == 'e')
                ans.push_back(i);
            if(s[i - 2] == 't' && s[i - 1] == 'w' && s[i] == 'o')
            {
                if(i < n - 2 && s[i + 1] == 'n' && s[i + 2] == 'e')
                    ans.push_back(i + 1), i += 2;
                else ans.push_back(i);
            }
        }
        cout << ans.size() << '\n';
        for(auto i : ans) cout << i << ' ';
        cout << '\n';
    }
}