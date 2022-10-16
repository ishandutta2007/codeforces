#include <bits/stdc++.h>
using namespace std;
int n;
int a[10001];
void solve(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    if(a[n]==0){
        for(int i=1; i<=n+1; i++) cout<<i<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0; i<n; i++) if((a[i]==0)&&(a[i+1]==1)){
        for(int j=1; j<=i; j++) cout<<j<<' ';
        cout<<n+1<<' ';
        for(int j=i+1; j<=n; j++) cout<<j<<' ';
        cout<<'\n';
        return;
    }
    assert(false);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}