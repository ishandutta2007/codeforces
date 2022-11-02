#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

int fa[maxn];
int cnt;
int Find(int x){
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

int main(){
    int n, k;
    cin >> n >> k;
    cnt = 0;
    for(int i = 1;i <= n;i++){
        fa[i] = i;
    }
    for(int i = 1;i <= k;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        int fx = Find(u);
        int fy = Find(v);
        if(fx == fy)
            cnt++;
        fa[fx] = fy;
    }
    cout << cnt << endl;
    return 0;
}