#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    int x[10], y;
    set <int> s;
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>x[i];
    for(int i=0; i<m; i++){
        cin>>y;
        s.insert(y);
    }
    for(int i=0; i<n; i++){
        if(s.find(x[i])!=s.end()) cout<<x[i]<<' ';
    }
    
}