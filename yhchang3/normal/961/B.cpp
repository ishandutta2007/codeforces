#include<bits/stdc++.h>
using namespace std;

const int M = 1e5+10;

int a[M],b[M],pre[M],prepre[M],suf[M];

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
        prepre[i]=prepre[i-1]+a[i];
    for(int i=1;i<=n;i++)
        pre[i]=pre[i-1]+b[i]*a[i];
    for(int i=n;i>=1;i--)
        suf[i]=suf[i+1]+b[i]*a[i];
    int ans = 0;
    for(int i=1;i+k-1<=n;i++)
        ans=max(ans,pre[i-1]+suf[i+k]+prepre[i+k-1]-prepre[i-1]);
    cout<<ans<<endl;
    
}