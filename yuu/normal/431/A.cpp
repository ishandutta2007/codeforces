#include <bits/stdc++.h>
using namespace std;
int a[4];
int main(){
    for(int i=0; i<4; i++) cin>>a[i];
    string s;
    cin>>s;
    int ans=0;
    for(char &c: s){
        c-='1';
        ans+=a[c];
    }
    cout<<ans<<'\n';
}