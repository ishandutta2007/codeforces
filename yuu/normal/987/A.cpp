#include <bits/stdc++.h>
using namespace std;
map <string, string> m;
int main(){
    m["purple"]="Power";
    m["green"]="Time";
    m["blue"]="Space";
    m["orange"]="Soul";
    m["red"]="Reality";
    m["yellow"]="Mind";
    int n;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        m.erase(s);
    }
    cout<<m.size()<<'\n';
    for(auto &x: m) cout<<x.second<<'\n';
}