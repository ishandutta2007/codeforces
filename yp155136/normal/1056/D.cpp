#include <bits/stdc++.h>
using namespace std;

const int N = 100006;

vector<int> G[N];

int sz[N];
int cnt[N];

#define SZ(x) ((int)(x).size())

void dfs(int now) {
    if (SZ(G[now]) == 0) {
        sz[now] = 1;
    }
    else {
        for (int i:G[now]) {
            dfs(i);
            sz[now] += sz[i];
        }
    }
    cnt[ sz[now] ]++;
}

int ans[N];

int main () {
    int n;
    scanf("%d",&n);
    for (int i=2;i<=n;++i) {
        int p;
        scanf("%d",&p);
        G[p].push_back(i);
    }
    dfs(1);
    int pre=0;
    for (int i=1;i<=n;++i) {
        for (int x=pre+1;x<=pre+cnt[i];++x) {
            ans[x] = i;
        }
        pre += cnt[i];
    }
    for (int i=1;i<=n;++i) {
        printf("%d%c",ans[i]," \n"[i==n]);
    }
}