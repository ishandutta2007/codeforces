#include <iostream>

using namespace std;

bool LCS(const string &s, const string &t, int x, int y)
{
    if(x == s.size()) return true;
    if(y == t.size()) return false;

    if(s[x] == t[y]) return LCS(s, t, x + 1, y + 1);
    return LCS(s, t, x, y + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        string s, t, p; cin >> s >> t >> p;

        int cnt[26]{}; bool flag1 = false;
        for(char c : s) ++cnt[c - 97];
        for(char c : p) ++cnt[c - 97];
        for(char c : t) --cnt[c - 97];
        for(int i : cnt) if(i < 0) flag1 = true;
        if(flag1) {cout << "NO\n"; continue;}

        if(LCS(s, t, 0, 0)) cout << "YES\n";
        else cout << "NO\n";
    }
}