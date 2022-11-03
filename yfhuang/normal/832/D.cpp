#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
int n,q;

int vs[maxn * 2];

int dep[maxn];
vector<int> G[maxn];
int tot;
void dfs(int s,int d){
    vs[++tot] = s;
    dep[s] = d;
    for(int i = 0;i < G[s].size();i++){
        int v = G[s][i];
        dfs(v,d + 1);
        vs[++tot] = s;
    }
}

int L[maxn];
int d[20][maxn * 2];
void init(){
    for(int i = 1;i <= tot;i++){
        d[0][i] = dep[vs[i]];
    }
    for(int j = 1;j < 20;j++){
        for(int i = 1;i + (1 << j) - 1 <= tot;i++){
            d[j][i] = min(d[j - 1][i],d[j - 1][i + (1 << (j - 1))]);
        }
    }
}

int query(int l,int r){
    int k = 31 - __builtin_clz(r - l + 1);
    //cout << r << " " << l << " " << k << endl;
    return min(d[k][l],d[k][r - (1 << k) + 1]);
}

int dis(int a,int b){
    if(L[a] > L[b]) swap(a,b);
    return dep[a] + dep[b] - 2 * query(L[a],L[b]);
}

int main(){
    cin >> n >> q;
    for(int i = 2;i <= n;i++){
        int p;
        scanf("%d",&p);
        G[p].push_back(i);
    }
    tot = 0;
    dfs(1,0);
    for(int i = 1;i <= n;i++) L[i] = 1e9;
    for(int i = tot;i >= 1;i--) L[vs[i]] = i;
    init();
    int dist[5];
    int D[5];
    for(int i = 1;i <= q;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        dist[0] = dis(a,b);
        dist[1] = dis(a,c);
        dist[2] = dis(b,c);
        //cout << dist[0] << endl;
        D[0] = (dist[1] + dist[2] - dist[0]) / 2;

        D[1] = (dist[0] + dist[2] - dist[1]) / 2;
        D[2] = (dist[1] + dist[0] - dist[2]) / 2;
        sort(D,D + 3);
        printf("%d\n",D[2] + 1);
    }
    return 0;
}