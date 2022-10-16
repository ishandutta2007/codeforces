#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100001];
int b[100001];
void solve(){
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) b[i]=a[i];
    sort(b+1, b+n+1);
    for(int i=1; i<=n; i++) a[i]=lower_bound(b+1, b+n+1, a[i]) - b;
    a[0]=-1;
    for(int i=1; i<=n; i++) if(a[i]!=a[i-1]+1) k--;
    if(k<0) cout<<"No\n";
    else cout<<"Yes\n";
}
int main(){
    int t;
    cin>>t;
    while(t--) solve();
}