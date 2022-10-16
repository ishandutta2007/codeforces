#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(){
    cin>>n>>m;
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0, a, b; j<m; j++){
            cin>>a>>b;
            ans+=a||b;
        }
    }
    cout<<ans<<'\n';
}