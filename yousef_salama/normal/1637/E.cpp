#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);

        vector <int> vx;
        map <int, int> cnt;

        for(int i = 0; i < n; i++){
            int a;
            scanf("%d", &a);

            vx.push_back(a);
            cnt[a]++;
        }
        sort(vx.begin(), vx.end());
        vx.resize(unique(vx.begin(), vx.end()) - vx.begin());

        vector < vector <int> > g(vx.size());
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d %d", &u, &v);

            u = lower_bound(vx.begin(), vx.end(), u) - vx.begin();
            v = lower_bound(vx.begin(), vx.end(), v) - vx.begin();

            g[v].push_back(u);
        }

        long long res = 0;
        vector <int> d_cnt;
        vector < list <int> > d;
        vector <bool> bad(vx.size(), false);

        for(int v = 0; v < (int)vx.size(); v++){
            for(int u : g[v])
                bad[u] = true;
            int cnt_v = cnt[vx[v]];

            for(int i = 0; i < (int)d.size(); i++){
                auto j = d[i].begin();
                while(j != d[i].end() && bad[*j])j++;

                if(j != d[i].end())res = max(res, 1LL * (vx[v] + vx[*j]) * (cnt_v + d_cnt[i]));
            }

            bool found = false;
            for(int i = 0; i < (int)d.size(); i++)if(d_cnt[i] == cnt_v){
                found = true;

                auto j = d[i].begin();
                while(j != d[i].end() && (*j) >= v)j++;

                d[i].insert(j, v);
            }

            if(!found){
                d_cnt.push_back(cnt_v);
                d.push_back(list <int> ());
                d.back().push_back(v);
            }

            for(int u : g[v])
                bad[u] = false;
        }
        
        printf("%lld\n", res);
    }

    return 0;
}