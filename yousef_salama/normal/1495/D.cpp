#include <bits/stdc++.h>
using namespace std;

int main(){
    const int MOD = 998244353;

    int n, m;
    scanf("%d %d", &n, &m);
    
    vector < vector <int> > g(n, vector <int> (n, n));
    vector < vector <int> > h(n);

    for(int i = 0; i < n; i++)
        g[i][i] = 0;

    while(m--){
        int a, b;
        scanf("%d %d", &a, &b);
        a--, b--;

        g[a][b] = g[b][a] = 1;
        h[a].push_back(b);
        h[b].push_back(a);
    }

    for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << g[i][j] << ' ';
        cout << endl;
    }*/

    vector < vector <int> > res(n, vector <int> (n, -1));
    for(int x = 0; x < n; x++){
        vector < vector <int> > levels(n);
        for(int i = 0; i < n; i++)
            levels[g[x][i]].push_back(i);

        for(int y = 0; y <= x; y++){
            long long cur = 1;
            int ptr = -1;
            
            /*if(x == 2 && y == 2){
                for(int i = 0; i < n; i++){
                    cout << "level " << i << " ::: ";
                    for(int j : levels[i])
                        cout << j + 1 << ',' << g[x][j] << ',' << g[y][j] << ' ';
                    cout << endl;
                }
            }*/

            for(int j = n - 1; j >= 1; j--){
                /*if(j == 0){
                    if(ptr != -1){
                        if(g[y][levels[j][0]] != ptr)cur = 0;
                    }else{
                        if(g[y][levels[j][0]] != 0)cur = 0;
                    }
                    continue;
                }*/
                if(levels[j].empty())continue;

                //if(x == 2 && y == 2)cout << j << " >>> " << cur << ' ' << ptr << endl;

                long long c0 = 1, c1 = 0;
                bool found = false;

                for(int u : levels[j]){
                    if(g[y][u] == 0){
                        found = true;
                    }else if(g[y][u] == ptr){
                        int cnt0 = 0, cnt1 = 0;
                        for(int v : h[u]){
                            if(g[x][v] == g[x][u] - 1 && g[y][v] == g[y][u] - 1)cnt0++;
                            if(g[x][v] == g[x][u] - 1 && g[y][v] == g[y][u] + 1)cnt1++;
                        }
                        long long c0_ = c0 * cnt0 % MOD;
                        long long c1_ = (c0 * cnt1 + c1 * cnt0) % MOD;
                        c0 = c0_;
                        c1 = c1_;
                    }else{
                        int cnt = 0;
                        for(int v : h[u]){
                            if(g[x][v] == g[x][u] - 1 && g[y][v] == g[y][u] - 1)cnt++;
                        }
                        cur = cur * cnt % MOD;
                    }
                }
                //if(x == 2 && y == 2)cout << "<<<" << j << ' ' << cur << ' ' << ptr << endl;
                if(found){
                    ptr = 1;
                }else if(ptr != -1){
                    cur = cur * c1 % MOD;
                    ptr++;
                }
            }

            res[x][y] = res[y][x] = cur;
        }
    }

    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            if(y > 0)printf(" ");
            printf("%d", res[x][y]);
        }
        printf("\n");
    }

    return 0;
}