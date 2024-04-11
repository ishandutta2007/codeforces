#include <bits/stdc++.h>
using namespace std;
int a[11][11];
int main(){
    int n;
    cin>>n;
    int ans=1;
    for(int i=1; i<=n; i++) a[1][i]=1;
    for(int i=2; i<=n; i++) for(int j=1; j<=n; j++) ans=max(ans, a[i][j]=a[i][j-1]+a[i-1][j]);
    cout<<ans<<'\n';
}