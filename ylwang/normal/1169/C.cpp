#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout<<#x<<" is "<<x<<endl;
ll a[300005],b[300005];
int n,m;
bool check(ll x){
    ll maxx=0;
    for(int i=1;i<=n;i++){
        b[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        if(b[i]<maxx){
            if(b[i]+x<maxx){
                return false;
            }
            else{
                b[i]=maxx;
            }
        }
        else if(b[i]>maxx){
            if(b[i]+x>=maxx+m){
                continue;
            }
            else{
                maxx=max(maxx,b[i]);
            }
        }
    }
    return true;
}
int main(){
   // int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    ll r=10000000;
    ll l=0;
    ll ans;
    while(l<=r){
        ll mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}