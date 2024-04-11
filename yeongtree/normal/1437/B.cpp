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
        int n; string s; cin >> n >> s;
        int ans = 0;
        for(int i = 1; i < n; ++i)
        {
            if(s[i - 1] == s[i]) ++ans;
        }
        cout << (ans + 1) / 2 << '\n';
    }
}