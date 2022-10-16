#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n, x, a, b;
    cin>>t;
    while(t--){
        cin>>n>>x>>a>>b;
        int ans=abs(a-b);
        ans=min(n-1, ans+x);
        cout<<ans<<'\n';
    }
}