#include <bits/stdc++.h>
using namespace std;
int n,k,x,l;
long long ans,a[200001],s1[200001],s2[200001];
int main(){
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)s1[i]=s1[i-1]|a[i];
    for(int i=n;i;i--)s2[i]=s2[i+1]|a[i];
    for(int i=1;i<=n;i++){
        long long y=a[i];
        for(int j=1;j<=k;j++)y*=x;
        ans=max(ans,s1[i-1]|y|s2[i+1]);
    }
    return cout<<ans,0;
}