#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int INF = (int)1e5 + 5;

    int n, q; cin >> n >> q;
    string des; cin >> des;

//    vector<int> cts[26];
//    for(int i = 0; i < des.size(); ++i)
//        cts[des[i] - 'a'].push_back(i);
//    for(int i = 0; i < 26; ++i)
//        cts[i].push_back(INF);

    int next[26][INF + 2];
    for(int i = 0; i < 26; ++i)
    {
        int pnt = INF;
        for(int j = des.size() - 1; j >= 0; --j)
        {
            next[i][j + 1] = pnt;
            if(des[j] == i + 'a')
                pnt = j;
        }
        next[i][0] = pnt;
        next[i][INF + 1] = INF;
    }

    int obj[3][251];
    int dp[251][251][251], len[3]{};
    dp[0][0][0] = -1;

    while(q--)
    {
        char a; cin >> a;

        if(a == '+')
        {
            int reg; cin >> reg >> a; --reg; obj[reg][++len[reg]] = a - 'a';
            int flag[3]{}; flag[reg] = len[reg];

            for(int i = flag[0]; i <= len[0]; ++i)
            {
                for(int j = flag[1]; j <= len[1]; ++j)
                {
                    for(int k = flag[2]; k <= len[2]; ++k)
                    {
                        int fit = INF;
//                        if(i) fit = min(fit, *upper_bound(cts[obj[0][i]].begin(), cts[obj[0][i]].end() - 1, dp[i - 1][j][k]));
//                        if(j) fit = min(fit, *upper_bound(cts[obj[1][j]].begin(), cts[obj[1][j]].end() - 1, dp[i][j - 1][k]));
//                        if(k) fit = min(fit, *upper_bound(cts[obj[2][k]].begin(), cts[obj[2][k]].end() - 1, dp[i][j][k - 1]));
                        if(i) fit = min(fit, next[obj[0][i]][dp[i - 1][j][k] + 1]);
                        if(j) fit = min(fit, next[obj[1][j]][dp[i][j - 1][k] + 1]);
                        if(k) fit = min(fit, next[obj[2][k]][dp[i][j][k - 1] + 1]);
                        dp[i][j][k] = fit;
                    }
                }
            }
        }

        else {int reg; cin >> reg; --len[--reg];}

        cout << (dp[len[0]][len[1]][len[2]] == INF ? "NO\n" : "YES\n");
    }

    return 0;
}