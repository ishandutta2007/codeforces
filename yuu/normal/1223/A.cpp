#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin>>q;
    while(q--){
        cin>>n;
        int ans=0;
        if(n<3){
            ans=3-n;
            n=3;
        }
        if(n%2) ans++;
        cout<<ans<<'\n';
    }
}