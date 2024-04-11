#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,a[101111],mf[101111],mg[101111];
ll f[101111],g[101111],ans;

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    
    mf[0]=f[0]=0;
    for (int i=1;i<=n;i++){
        mf[i]=max(mf[i-1]+1,a[i]);
        f[i]=f[i-1]+mf[i]-a[i];
    }
    mg[n+1]=g[n+1]=0;
    for (int i=n;i>0;i--){
        mg[i]=max(mg[i+1]+1,a[i]);
        g[i]=g[i+1]+mg[i]-a[i];
    }
    
    ans=min(f[n],g[1]);
    for (int i=1;i<n;i++){
        ans=min(ans,f[i]+g[i+1]+(mf[i]==mg[i+1]?1:0));
    }
    cout<<ans;
}