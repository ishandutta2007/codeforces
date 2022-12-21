#include<bits/stdc++.h>
#define N 100005
#define P 1000000
using namespace std;
int n,m,a[15];
int f[P*2+5];
inline void dfs(int i,int s) {
    if (i>n) {
        f[s+P]++;
        return ;
    }
    dfs(i+1,s);
    dfs(i+1,s+a[i]);
    dfs(i+1,s-a[i]);
}
int main() {
    int test;
    scanf("%d",&test);
    while (test--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        dfs(1,0);
        int ans=0;
        if (f[P]>1) ans=1;
        for (int i = -1000000;i<=1000000;i++) {
            f[i+P]=0;
        }
        if (ans) puts("YES");
        else puts("NO");
    }
}