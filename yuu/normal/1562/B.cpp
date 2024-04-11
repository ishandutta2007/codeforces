#include <bits/stdc++.h>
using namespace std;
int cnt[256];
vector <int> done({1, 4, 6, 8, 9});
bool prime[10000];
bool generate(const string& s, int pos, int size=0, int val=0){
    if(pos==s.size()){
        if(!prime[val]){
            cout<<size<<'\n'<<val<<'\n';
            return 1;
        }
        else return 0;
    }
    else{
        if(generate(s, pos+1, size, val)) return 1;
        if(generate(s, pos+1, size+1, val*10+(s[pos]%16))) return 1;
        return 0;
    }
}
void solve(){
    int k;
    string s;
    cin>>k>>s;
    for(int i=1; i<10; i++) cnt[i]=0;
    for(auto &&c: s) cnt[c%16]++;
    for(auto &&x: done) if(cnt[x]){
        cout<<"1\n"<<x<<'\n';
        return;
    }
    for(int i=2; i<10; i++) if(cnt[i]>=2){
        cout<<2<<'\n';
        cout<<i<<i<<'\n';
        return;
    }
    //2357 unique
    generate(s, 0);
}
int main(){
    prime[0]=1;
    prime[1]=0;
    for(int i=2; i<10000; i++) prime[i]=1;
    for(int i=2; i<10000; i++) if(prime[i]){
        for(int j=i+i; j<10000; j+=i) prime[j]=0;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
}