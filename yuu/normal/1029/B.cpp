#include <bits/stdc++.h>
using namespace std;
int a[200001];
int f[200001];
int n;
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    f[1]=1;
    int ans=1;
    for(int i=2; i<=n; i++){
        if(a[i]<=a[i-1]*2) f[i]=f[i-1]+1;
        else f[i]=1;
        ans=max(ans, f[i]);
    }
    cout<<ans;
}