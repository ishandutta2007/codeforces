#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[5001];
int f[5002][5001];
int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    for(int i=1, j=1; i<=n; i++){
        while((j<n)&&(a[j+1]-a[i])<=5) j++;
        for(int x=0; x<k; x++) f[j+1][x+1]=max(f[j+1][x+1], f[i][x]+j-i+1);
        for(int x=1; x<=k; x++) f[i+1][x]=max(f[i+1][x], f[i][x]);
    }
    int ans=0;
    for(int x=1; x<=k; x++) ans=max(ans, f[n+1][x]);
    cout<<ans<<'\n';
}