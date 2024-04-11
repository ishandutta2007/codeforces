#include <bits/stdc++.h>
using namespace std;

long long f(
    vector < vector <int> >& g,
    vector <long long>& s,
    vector < map <int, long long> >& dp,
    int u,
    int k
){
    if(dp[u].count(k)){
        return dp[u][k];
    }

    long long res = s[u] * k;
    vector <long long> options;

    for(int v : g[u]){
        long long z0 = f(g, s, dp, v, k / (int)g[u].size());
        res += z0;

        if(k % (int)g[u].size() != 0){
            long long z1 = f(g, s, dp, v, k / (int)g[u].size() + 1);
            options.push_back(z1 - z0);
        }
    }

    if(!g[u].empty()){
        int rem = k % (int)g[u].size();
        if(rem != 0){
            sort(options.rbegin(), options.rend());
            for(int i = 0; i < rem; i++)
                res += options[i];
        }
    }

    // cout << u + 1 << ',' << k << " ===> " << res << endl;

    return (dp[u][k] = res);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector < vector <int> > g(n);
        for(int i = 1; i < n; i++){
            int p;
            cin >> p;
            p--;

            g[p].push_back(i);
        }

        vector <long long> s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];

        vector < map <int, long long> > dp(n);

        cout << f(g, s, dp, 0, k) << '\n';
    }

    return 0;
}