#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
void solve(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) a[1]&=a[i];
    cout<<a[1]<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}