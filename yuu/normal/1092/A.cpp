#include <bits/stdc++.h>
using namespace std;
string s;
int n, k;
void solve(){
    cin>>n>>k;
    for(int i=0; i<n; i++) cout<<s[i%k];
    cout<<'\n';
}
int main(){
    for(char c='a'; c<='z'; c++) s+=c;
    int t;
    cin>>t;
    while(t--) solve();
}