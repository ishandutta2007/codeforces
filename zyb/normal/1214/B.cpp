#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define lowbit(x) x&-x
int n,m,a,b,ans;
int main() {
    //freopen("0.in","r",stdin);
    scanf("%d%d%d",&a,&b,&n);
    int ans=0;
    for (int i=0;i<=n;i++) {
        if (i<=a&&n-i<=b) ans++;
    }
    printf("%d\n",ans);
}