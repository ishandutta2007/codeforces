#include <bits/stdc++.h>
using namespace std;

const int MAGIC = 400;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> vx;
        vector < vector <int> > v(n);
        
        for(int i = 0; i < n; i++){
            int k;
            scanf("%d", &k);
            v[i].resize(k);

            for(int j = 0; j < k; j++){
                scanf("%d", &v[i][j]);
                vx.push_back(v[i][j]);
            }
        }

        sort(vx.begin(), vx.end());
        vx.resize(unique(vx.begin(), vx.end()) - vx.begin());

        int m = vx.size();

        for(int i = 0; i < n; i++)
        for(int j = 0; j < (int)v[i].size(); j++)
            v[i][j] = lower_bound(vx.begin(), vx.end(), v[i][j]) - vx.begin();

        vector < vector <int> > g(m);
        for(int i = 0; i < n; i++)
        for(int x : v[i])
            g[x].push_back(i);

        vector <bool> vis(m, false);

        int x1 = -1, x2 = -1;
        for(int i = 0; i < n && x1 == -1; i++)if(v[i].size() > MAGIC){
            for(int x : v[i])
                vis[x] = true;
            
            for(int j = 0; j < n && x1 == -1; j++)if(i != j){
                int cnt = 0;
                for(int x : v[j])
                    cnt += vis[x];
                
                if(cnt >= 2){
                    x1 = i;
                    x2 = j;
                }
            }

            for(int x : v[i])
                vis[x] = false;
        }

        if(x1 != -1){
            printf("%d %d\n", x1 + 1, x2 + 1);
            continue;
        }
        /*
        vector <bool> vis2(m, false);

        for(int i = 0; i < m && x1 == -1; i++)if(g[i].size() > MAGIC){
            for(int x : g[i])
                vis2[x] = true;
            
            for(int j = 0; j < m && x1 == -1; j++)if(i != j){
                int a = -1, b = -1;
                for(int x : g[j]){
                    if(vis2[x]){
                        if(a == -1)a = x;
                        else b = x;
                    }
                }

                if(b != -1){
                    x1 = a;
                    x2 = b;
                }
            }
        }

        if(x1 != -1){
            printf("%d %d\n", x1 + 1, x2 + 1);
            continue;
        }*/

        vector <int> ind(m, -1);
        for(int i = 0; i < m && x1 == -1; i++){
            for(int j : g[i])if(v[j].size() <= MAGIC){
                for(int x : v[j]){
                    if(x == i)continue;
                    if(ind[x] != -1){
                        x1 = ind[x];
                        x2 = j;
                        break;
                    }else ind[x] = j;
                }
                if(x1 != -1)break;
            }

            for(int j : g[i])if(v[j].size() <= MAGIC)
            for(int x : v[j])
                ind[x] = -1;
        }

        if(x1 != -1){
            printf("%d %d\n", x1 + 1, x2 + 1);
            continue;
        }
        printf("-1\n");
    }
    return 0;
}