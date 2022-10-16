#include <bits/stdc++.h>
using namespace std;
set <string> s;
int main(){
    int n;
    cin>>n;
    while(n--){
        string t;
        cin>>t;
        if(s.find(t)==s.end()){
            cout<<"NO\n";
            s.insert(t);
        }
        else cout<<"YES\n";
    }
}