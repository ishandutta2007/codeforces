#include <bits/stdc++.h>
using namespace std;
int n;
vector <string> po2;
void solve(){
    cin>>n;
    string s=to_string(n);
    int res=1000;
    for(auto &&t: po2){
        int id=0;
        int ans=t.size()+s.size();
        for(auto &&c: s){
            if(t[id]==c){
                id++;
                ans-=2;
                if(id == t.size()) break;
            }
        }
        res=min(res, ans);
    }
    cout<<res<<'\n';
}
int main(){
    uint64_t x=1;
    for(int i=0; i<=62; i++){
        po2.push_back(to_string(x<<i));
    }
    int t=1;
    cin>>t;
    while(t--) solve();
}