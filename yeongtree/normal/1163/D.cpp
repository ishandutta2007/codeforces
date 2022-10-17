#include <iostream>
//#include <algorithm>
#include <string>

using namespace std;

inline void bemax(int &x, const int &y)
{
    if(x < y) x = y;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string hay; cin >> hay;
    string pnd, nnd; cin >> pnd >> nnd;
    int s = pnd.size(), t = nnd.size();

    int ffs[s + 1]; ffs[0] = -1;
    int nxls[s][26];
    for(int i = 0; i < s; ++i)
    {
        for(int j = 0; j < 26; ++j)
        {
            int p = ffs[i];
            while(p >= 0 && (97 + j) != pnd[p]) p = ffs[p];
            nxls[i][j] = p + 1;
        }
        ffs[i + 1] = nxls[i][pnd[i] - 97];
        nxls[i][pnd[i] - 97] = i + 1;
    }
    int pnf = ffs[s];

    int fft[t + 1]; fft[0] = -1;
    int nxlt[t][26];
    for(int i = 0; i < t; ++i)
    {
        for(int j = 0; j < 26; ++j)
        {
            int p = fft[i];
            while(p >= 0 && (97 + j) != nnd[p]) p = fft[p];
            nxlt[i][j] = p + 1;
        }
        fft[i + 1] = nxlt[i][nnd[i] - 97];
        nxlt[i][nnd[i] - 97] = i + 1;
    }
    int nnf = fft[t];

    const int Inf = -1e5;

    int dp[s][t];
    for(auto &i : dp) for(auto &j : i) j = Inf;
    dp[0][0] = 0;

    for(auto &val : hay)
    {
        int tmp[s + 1][t + 1];
        for(auto &i : tmp) for(auto &j : i) j = Inf;

        if(val == '*')
        {
            for(int i = 0; i < s; ++i)
                for(int j = 0; j < t; ++j)
                    for(int k = 0; k < 26; ++k)
                        bemax(tmp[nxls[i][k]][nxlt[j][k]], dp[i][j]);
        }

        else
        {
            int k = val - 97;
            for(int i = 0; i < s; ++i)
                for(int j = 0; j < t; ++j)
                    bemax(tmp[nxls[i][k]][nxlt[j][k]], dp[i][j]);
        }

        for(int i = 0; i <= s; ++i) bemax(tmp[i][nnf], tmp[i][t] - 1);
        for(int j = 0; j < t; ++j) bemax(tmp[pnf][j], tmp[s][j] + 1);

        for(int i = 0; i < s; ++i)
            for(int j = 0; j < t; ++j)
                dp[i][j] = tmp[i][j];
    }

    int ans = Inf;
    for(auto &i : dp) for(auto &j : i) bemax(ans, j);

    cout << ans;
    return 0;
}