#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;
        vector<int> ls[m];
        int cnt[n]{};
        for(int i = 0; i < m; ++i)
        {
            int x; cin >> x;
            for(int j = 0; j < x; ++j)
            {
                int y; cin >> y; --y;
                ls[i].push_back(y);
            }
            ++cnt[ls[i][0]];
        }
        bool flag = true;
        for(int i = 0; i < n; ++i) if(cnt[i] > (m + 1) / 2)
        {
            int t = cnt[i] - (m + 1) / 2;
            for(int j = 0; j < m; ++j) if(t && ls[j][0] == i)
            {
                if(ls[j].size() >= 2) ls[j][0] = ls[j][1], --t;
            }
            if(t) flag = false;
            break;
        }
        if(flag)
        {
            cout << "YES\n";
            for(int i = 0; i < m; ++i) cout << ls[i][0] + 1 << ' ';
            cout << '\n';
        }
        else cout << "NO\n";
    }
}