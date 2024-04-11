#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    cin>>s;
    for(int i=1; i<s.size(); i++) if(s[i]!=s[i-1]){
        cout<<i<<' '<<i+1<<'\n';
        return;
    }
    cout<<"-1 -1\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}