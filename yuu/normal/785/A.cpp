#include <bits/stdc++.h>
using namespace std;
int val[256];
int main(){
    val['T']=4;
    val['C']=6;
    val['O']=8;
    val['D']=12;
    val['I']=20;
    int n;
    cin>>n;
    string s;
    int ans=0;
    while(n--){
        cin>>s;
        ans+=val[s[0]];
    }
    cout<<ans<<'\n';
}