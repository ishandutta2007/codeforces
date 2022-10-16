#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, h;
    cin>>n>>h;
    int ans=n;
    for(int i=0, x; i<n; i++){
        cin>>x;
        ans+=x>h;
    }
    cout<<ans<<'\n';
}