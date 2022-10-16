#include <bits/stdc++.h>
using namespace std;
int a, b, c;
void solve(){
    cin>>a>>b>>c;
    if(a>b) swap(a, b);
    int n=(b-a)*2;
    if((b>n)||(c>n)){
        cout<<-1<<'\n';
        return;
    }
    int ans=c-n/2;
    if(ans<=0) ans+=n;
    cout<<ans<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}