#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int cnt=0;
    for(char c: s) cnt+=(c=='a');
    int ans=s.size();
    ans=min(ans, cnt*2-1);
    cout<<ans<<'\n';
}