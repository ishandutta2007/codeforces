#include <bits/stdc++.h>
using namespace std;
int main(){
    int c, d, n, m, k;
    cin>>c>>d>>n>>m>>k;
    int ans=1e9;
    for(int j=0; j<=m; j++){
        int req=max(0, n*m-k-j*n);
        ans=min(ans, j*c+d*req);
    }
    cout<<ans<<'\n';
}