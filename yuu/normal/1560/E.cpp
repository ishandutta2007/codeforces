#include <bits/stdc++.h>
using namespace std;
string t;
int cnt[256];
bool done[256];
string make(string s, string order){
    string res;
    for(int c='a'; c<='z'; c++) done[c]=0;
    for(auto &&c: order){
        for(auto &&f: s) if(!done[f]){
            res+=f;
        }
        done[c]=1;
    }
    return res;
}
void solve(){
    cin>>t;
    for(int c='a'; c<='z'; c++) cnt[c]=0;
    for(int c='a'; c<='z'; c++) done[c]=0;
    for(auto &&c: t) cnt[c]++;
    int letter_count=0;
    for(int c='a'; c<='z'; c++) letter_count+=(cnt[c]!=0);
    string order;
    for(int i=t.size()-1; i>=0; i--) if(!done[t[i]]){
        order+=t[i];
        done[t[i]]=1;
    }
    reverse(order.begin(), order.end());
    int original_size=0;
    for(int i=0; i<order.size(); i++){
        if(cnt[order[i]]%(i+1)){
            cout<<-1<<'\n';
            return;
        }
        else original_size+=cnt[order[i]]/(i+1);
    }
    string s=t.substr(0, original_size);
    if(make(s, order)!=t){
        cout<<-1<<'\n';
    }
    else cout<<s<<' '<<order<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}