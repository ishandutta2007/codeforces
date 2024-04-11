#include <bits/stdc++.h>
using namespace std;
int n, q;
string a;
int s[300001];
map <int, vector <int>> spec;
int find_pos(int l, int r){
    //(l-r%2)==0
    int val=s[r]+s[l-1];
    auto it=spec.find(val);
    assert(it!=spec.end());
    auto x=*lower_bound(it->second.begin(), it->second.end(), l);
    assert(x<=r);
    return x;
}
void solve(){
    cin>>n>>q>>a;
    a='0'+a;
    spec.clear();
    for(int i=1; i<=n; i++){
        int val = 1;
        if(i%2) val=-val;
        if(a[i]=='-') val=-val;
        s[i]=s[i-1]+val;
        spec[s[i]+s[i-1]].push_back(i);
    }
    for(int i=1, l, r; i<=q; i++){
        cin>>l>>r;
        if(s[r]==s[l-1]){
            cout<<0<<'\n';
            continue;
        }
        if((r-l)%2==0){
            cout<<1<<'\n';
            // cout<<find_pos(l, r)<<'\n';
        }
        else{
            cout<<2<<'\n';
            // cout<<l<<' '<<find_pos(l+1, r)<<'\n';
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
}