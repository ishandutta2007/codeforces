#include <bits/stdc++.h>
using namespace std;
void solve(){
    int l, r;
    cin>>l>>r;
    if(l==r){
        cout<<0<<'\n';
        return;
    }
    int val = max(l, (r+1)/2);
    cout<<max(r%val, (r-1)%val)<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
}