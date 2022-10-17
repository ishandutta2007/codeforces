#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int N = s.size();
    int cnt[N + 1][26]{};
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < 26; ++j) cnt[i + 1][j] = cnt[i][j];
        ++cnt[i + 1][s[i] - 'a'];
    }

    int T; cin >> T;
    while(T--)
    {
        int x, y; cin >> x >> y; --x; --y;
        if(x == y) cout << "Yes\n";
        else if(s[x] != s[y]) cout << "Yes\n";
        else
        {
            int pt = 0;
            for(int i = 0; i < 26; ++i) if(cnt[x][i] != cnt[y + 1][i]) ++pt;
            if(pt >= 3) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}