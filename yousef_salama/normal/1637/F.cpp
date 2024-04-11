#include <bits/stdc++.h>
using namespace std;

struct dp_result{
    long long cost, max;

    dp_result(): cost(0), max(0){}
    dp_result(long long cost, long long max): cost(cost), max(max){}
};

dp_result combine(const dp_result& a, const dp_result& b){
    return dp_result(a.cost + b.cost, max(a.max, b.max));
}

dp_result propagate(const dp_result& a, long long h){
    return dp_result(a.cost + max(0LL, h - a.max), max(a.max, h));
}

struct tree{
    int n;
    vector < vector <int> > g, gd;
    vector <int> h;

    vector < vector <dp_result> > dp_pref, dp_suf;
    vector <dp_result> dp_upwards;

    tree(int n): n(n), g(n), gd(n), h(n), dp_pref(n), dp_suf(n), dp_upwards(n){}

    void dfs_direct(int u, int parent){
        for(int v : g[u]){
            if(v == parent)continue;
            
            gd[u].push_back(v);
            dfs_direct(v, u);
        }
    }

    void dfs_dp(int u){
        for(int v : gd[u])dfs_dp(v);

        dp_pref[u].push_back(dp_result());
        for(int i = 0; i < (int)gd[u].size(); i++)
            dp_pref[u].push_back(combine(dp_pref[u].back(), propagate(dp_pref[gd[u][i]].back(), h[gd[u][i]])));

        dp_suf[u].resize(gd[u].size() + 1);
        for(int i = (int)gd[u].size() - 1; i >= 0; i--)
            dp_suf[u][i] = combine(dp_suf[u][i + 1], propagate(dp_pref[gd[u][i]].back(), h[gd[u][i]]));
    }

    void dfs_dp_upwards(int u, int parent, int ind){
        if(parent != -1){
            dp_upwards[u] = propagate(combine(dp_upwards[parent], 
                            combine(dp_pref[parent][ind], dp_suf[parent][ind + 1])), h[parent]);
        }

        for(int i = 0; i < (int)gd[u].size(); i++)
            dfs_dp_upwards(gd[u][i], u, i);
    }

    long long calc(){
        dfs_direct(0, -1);
        dfs_dp(0);
        dfs_dp_upwards(0, -1, -1);

        int mx = *max_element(h.begin(), h.end());

        long long res = 1LL << 60;
        for(int i = 0; i < n; i++)
            res = min(res, propagate(combine(dp_pref[i].back(), dp_upwards[i]), h[i]).cost + mx);
            
        return res;
    }
};

int main(){
    int n;
    scanf("%d", &n);

    tree T(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &T.h[i]);

    for(int i = 0; i < n - 1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;

        T.g[u].push_back(v);
        T.g[v].push_back(u);
    }

    printf("%lld\n", T.calc());

    return 0;
}