#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;

int n, m;

int q;
typedef long long LL;
vector<int> rG[maxn];
int out[maxn];

LL getans(int x){
    return 1LL * rG[x].size() * out[x];
}

int main(){
    cin >> n >> m; 
    LL now = 0;
    for(int i = 1;i <= m;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        if(a < b)
            swap(a, b);
        rG[b].push_back(a);
        out[a]++;
    }
    for(int i = 1;i <= n;i++){
        now += getans(i);
    }
    cout << now << endl;
    int q;
    cin >> q;
    for(int i = 1;i <= q;i++){
        int u;
        scanf("%d", &u);
        now -= getans(u);
        for(auto v : rG[u]){
            now -= getans(v);
            out[v]--;
            rG[v].push_back(u);
            now += getans(v);
            out[u]++;
        }
        rG[u].clear();
        printf("%lld\n", now);
    }
    return 0;
}