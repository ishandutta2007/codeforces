#include<bits/stdc++.h>
#define N 200005
using namespace std;
#define P 1000000007
int n,m;
long long a[N],b[N];
long long ans;
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        x/=2;
        y/=2;
        a[2*(x&1)+(y&1)]++;
    }
    long long ans=0;
    for (int i=0;i<=3;i++)
    for (int j=i+1;j<=3;j++)
    for (int o=j+1;o<=3;o++) ans+=1ll*a[i]*a[j]*a[o];
    ans=1ll*n*(n-1)*(n-2)/6-ans;
    printf("%lld\n",ans);

}