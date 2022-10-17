#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

const int Q = (int)1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nn, T; cin >> nn >> T;
    string s, t; cin >> s >> t;
    vector<string> V;
    V.push_back(s);
    for(int i = 0; i < nn; ++i)
    {
        V.push_back(V.back() + t[i] + V.back());
        if((int)V.back().size() > 1010101) break;
    }
    int pow[1010101];
    pow[0] = 1;
    for(int i = 1; i < 1010101; ++i) pow[i] = pow[i - 1] * 2 % Q;
    int rpow[1010101];
    rpow[0] = 1;
    for(int i = 1; i < 1010101; ++i) rpow[i] = 1ll * rpow[i - 1] * 500'000'004 % Q;

    int tcnt[nn + 1][26]{};
    for(int i = 1; i <= nn; ++i)
    {
        for(int j = 0; j < 26; ++j) tcnt[i][j] = tcnt[i - 1][j];
        int k = t[i - 1] - 'a';
        tcnt[i][k] = (tcnt[i][k] + pow[nn - i]) % Q;
    }

    vector<vector<int>> F, BF;
    for(auto str : V)
    {
        int n = str.size();
        F.push_back(vector<int>(n + 1));
        int pt = 0;
        for(int i = 1; i < n; ++i)
        {
            while(pt > 0 && str[pt] != str[i]) pt = F.back()[pt];
            if(str[pt] == str[i]) ++pt;
            F.back()[i + 1] = pt;
        }
        reverse(str.begin(), str.end());
        BF.push_back(vector<int>(n + 1));
        pt = 0;
        for(int i = 1; i < n; ++i)
        {
            while(pt > 0 && str[pt] != str[i]) pt = BF.back()[pt];
            if(str[pt] == str[i]) ++pt;
            BF.back()[i + 1] = pt;
        }
    }
//    for(int i = 0; i < 3; ++i)
//    {
//        for(auto j : F[i]) cout << j << ' ';
//        cout << endl;
//    }

    while(T--)
    {
        int l; cin >> l;
        string str; cin >> str;
        int n = str.size();
        vector<int> G(n + 1);
        int pt = 0;
        for(int i = 1; i < n; ++i)
        {
            while(pt > 0 && str[pt] != str[i]) pt = G[pt];
            if(str[pt] == str[i]) ++pt;
            G[i + 1] = pt;
        }

        int t = 0;
        while(t < l && n > (int)V[t].size()) ++t;
        int m = V[t].size();
        if(n > m) { cout << "0\n"; continue; }

        int ans = 0;
        int cnt = 0;

        pt = 0;
        for(int i = 0; i < m; ++i)
        {
            while(pt > 0 && str[pt] != V[t][i]) pt = G[pt];
            if(str[pt] == V[t][i]) ++pt;
            if(pt == n) ++cnt, pt = G[pt];
        }
        ans += 1ll * cnt * pow[l - t] % Q;

        int chc[n]{};
        pt = 0;
        for(int i = 0; i < n; ++i)
        {
            while(pt > 0 && V[t][pt] != str[i]) pt = F[t][pt];
            if(V[t][pt] == str[i]) ++pt;
        }
        while(1)
        {
            if(pt != n) chc[n - pt - 1]++;
            if(pt == 0) break;
            pt = F[t][pt];
        }

        reverse(str.begin(), str.end());
        reverse(V[t].begin(), V[t].end());
        for(auto &i : G) i = 0;
        pt = 0;
        for(int i = 1; i < n; ++i)
        {
            while(pt > 0 && str[pt] != str[i]) pt = G[pt];
            if(str[pt] == str[i]) ++pt;
            G[i + 1] = pt;
        }

        pt = 0;
        for(int i = 0; i < n; ++i)
        {
            while(pt > 0 && V[t][pt] != str[i]) pt = BF[t][pt];
            if(V[t][pt] == str[i]) ++pt;
        }
        while(1)
        {
            if(pt != n) chc[pt]++;
            if(pt == 0) break;
            pt = BF[t][pt];
        }

        reverse(str.begin(), str.end());
        reverse(V[t].begin(), V[t].end());

        for(int i = 0; i < n; ++i) if(chc[i] == 2)
        {
            int k = str[i] - 'a';
            ans += 1ll * ((Q + tcnt[l][k] - tcnt[t][k]) % Q) * rpow[nn - l] % Q;
            ans %= Q;
        }

        cout << ans << '\n';
    }
}