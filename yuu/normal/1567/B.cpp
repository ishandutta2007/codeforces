#include <bits/stdc++.h>
using namespace std;
int pref_xor[300001];
void solve(){
    int a, b;
    cin>>a>>b;
    if(pref_xor[a-1]==b){
        cout<<a<<'\n';
        return;
    }
    if((pref_xor[a-1]^b)!=(a)){
        cout<<a+1<<'\n';
        return;
    }
    cout<<a+2<<'\n';
}
int main(){
    for(int i=1; i<=300000; i++) pref_xor[i]=pref_xor[i-1]^i;

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}