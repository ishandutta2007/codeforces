#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
typedef long long ll;
const int N=1000010;
ll a[N],n,ys[N],ans,c[N],vis[N];
ll gcd(ll x,ll y){
    return x==0?y:gcd(y%x,x);
}

signed main(){
    srand(19260817);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int num=1;num<=min(10ll,n);){
        memset(c,0,sizeof(c));
        ll pos=1ll*rand()*rand()%n+1,x=a[pos],cnt=0;
        if(vis[pos]) continue;
        vis[pos]=1;num++;
        for(ll j=1;j*j<=x;j++){
            if(x%j==0){
                ys[++cnt]=j;
                if(x/j!=j) ys[++cnt]=x/j;
            }
        }
        sort(ys+1,ys+cnt+1);
        for(int i=1;i<=n;i++){
            ++c[lower_bound(ys+1,ys+cnt+1,gcd(x,a[i]))-ys];
        }
        for(int i=1;i<=cnt;i++){
            for(int j=i+1;j<=cnt;j++){
                if(ys[j]%ys[i]==0) c[i]+=c[j];
            }
        }
        for(int i=cnt;i>=1;i--){
            if(c[i]*2>=n) ans=max(ans,ys[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}