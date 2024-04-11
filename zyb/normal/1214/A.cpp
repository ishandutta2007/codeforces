#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define lowbit(x) x&-x
int n,m,a,b,ans;
int main() {
    //freopen("0.in","r",stdin);
    scanf("%d%d%d",&n,&a,&b);
    b*=5;
    if (a<b) swap(a,b);
    int ans=n%b;
    for (;n>=0;n-=a) ans=min(ans,n%b);
    printf("%d\n",ans);
}