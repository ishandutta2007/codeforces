#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
ll a[10],n,b[100010],pos[10],cnt;
ll ans=1e18;
int main(){
    for(int i=1;i<=6;i++) scanf("%lld",&a[i]);
    sort(a+1,a+7);cnt=unique(a+1,a+7)-a-1;
    cin>>n;
    for(int j=1;j<=n;j++) scanf("%lld",&b[j]);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cnt;j++){
            ll minx=b[i]-a[j],maxn=0,last=0;
            if(b[1]-a[1]<minx) goto fail;
            for(int k=2;k<=cnt;k++){
                last=lower_bound(b+last+1,b+n+1,minx+a[k])-b-1;
                maxn=max(maxn,b[last]-a[k-1]);
            }
            for(int k=cnt;k>=1;k--){
                if(b[n]-a[k]>=minx){
                    maxn=max(maxn,b[n]-a[k]);
                    break;
                }
            }
            ans=min(ans,maxn-minx);
            fail:;
        }
    }
    cout<<ans<<endl;
    return 0;
}