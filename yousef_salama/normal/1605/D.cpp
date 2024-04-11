#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector <int> g[MAXN];
vector <int> even, odd;

void dfs(int u, int parent = -1, int color = 0){
    if(color == 0)even.push_back(u);
    else odd.push_back(u);

    for(int v : g[u]){
        if(v == parent)continue;
        dfs(v, u, color ^ 1);
    }
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
            g[i].clear();
        even.clear();
        odd.clear();

        for(int i = 0; i < n - 1; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            u--, v--;

            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1, 0);

        vector <int> permutation(n, -1);
        vector <bool> taken(n + 1, false);

        if(even.size() > odd.size())swap(even, odd);
        
        for(int i = 1, j = 0; (1 << i) - 1 <= n; i++){
            if((int)even.size() & (1 << (i - 1))){
                for(int k = 0; k < (1 << (i - 1)); k++){
                    permutation[even[j]] = (1 << (i - 1)) + k;
                    taken[(1 << (i - 1)) + k] = true;
                    j++;
                }
            }
        }

        for(int i = 1, j = 0; i <= n; i++){
            if(!taken[i]){
                permutation[odd[j]] = i;
                j++;
            }
        }

        for(int i = 0; i < n; i++){
            if(i > 0)printf(" ");
            printf("%d", permutation[i]);
        }
        printf("\n");
    }

    return 0;
}