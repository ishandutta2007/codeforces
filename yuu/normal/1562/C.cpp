#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    string s;
    cin>>n>>s;
    if(n==2){
        if(s[0]=='1') cout<<"2 2 1 1\n";
        else cout<<"1 1 2 2\n";
        return;
    }
    s='0'+s;
    int sz=n/2;
    for(int i=1; i<=sz; i++) if(s[i]=='0'){
        cout<<i<<' '<<n<<' '<<i+1<<' '<<n<<'\n';
        return;
    }
    for(int i=sz+1; i<=n; i++) if(s[i]=='0'){
        cout<<1<<' '<<i<<' '<<1<<' '<<i-1<<'\n';
        return;
    }
    cout<<1<<' '<<n-1<<' '<<2<<' '<<n<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
}