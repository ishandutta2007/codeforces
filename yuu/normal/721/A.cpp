#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char c;
    int cnt=0;
    vector <int> ans;
    while(n--){
        cin>>c;
        if(c=='B') cnt++;
        else{
            if(cnt) ans.push_back(cnt);
            cnt=0;
        }
    }
    if(cnt) ans.push_back(cnt);
    cout<<ans.size()<<'\n';
    for(auto &x: ans) cout<<x<<' ';
}