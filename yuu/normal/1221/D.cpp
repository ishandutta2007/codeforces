#include <bits/stdc++.h>
using namespace std;
int n;
int a[300001];
int b[300001];
long long f[300001][3];
void solve(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i]>>b[i];
    for(int i=1; i<=n; i++) for(int j=0; j<3; j++) f[i][j]=2e18;
    for(int i=1; i<=n; i++) for(int j=0; j<3; j++) for(int k=0; k<3; k++){
        if(a[i]+k!=a[i-1]+j) f[i][k]=min(f[i][k], f[i-1][j]+(b[i]*k));
    }
    cout<<min(min(f[n][0], f[n][1]), f[n][2])<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin>>q;
    while(q--) solve();
}