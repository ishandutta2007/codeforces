#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[200001];
int best[200001];
long long s[2001];
long long f[2001];
int main(){
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    {
        int a, b;
        for(int i=1; i<=m; i++){
            cin>>a>>b;
            best[a]=max(best[a], b);
        }
    }
    n=k;
    for(int i=1; i<=n; i++) s[i]=s[i-1]+a[i];
    for(int i=1; i<=n; i++) f[i]=1e18;
    for(int j=0; j<n; j++) for(int i=1; i+j<=n; i++) f[j+i]=min(f[j+i], f[j]+s[j+i]-s[j+best[i]]);
    cout<<f[n]<<'\n';
}