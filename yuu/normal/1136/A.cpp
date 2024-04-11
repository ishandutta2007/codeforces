#include <bits/stdc++.h>
using namespace std;
int n, k;
int l[101];
int r[101];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>l[i]>>r[i];
    cin>>k;
    int ans=0;
    for(int i=1; i<=n; i++) ans+=r[i]>=k;
    cout<<ans<<'\n';
}