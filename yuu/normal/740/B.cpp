#include <stdio.h>
using namespace std;
int a[101];
int f[101];
int n, m, u, v;
int main(){
    //freopen("B.INP", "r", stdin);
    scanf("%i%i", &n, &m);
    for(int i=1; i<=n; i++){
        scanf("%i", &a[i]);
        f[i]=f[i-1]+a[i];
    }
    int ans=0;
    for(int i=1; i<=m; i++){
        scanf("%i%i", &u, &v);
        if(f[v]-f[u-1]>0)
            ans+=f[v]-f[u-1];
    }
    printf("%d", ans);
}