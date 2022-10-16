#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        vector <int> a;
        a.resize(n);
        for(auto &x: a) cin>>x;
        int ans=1;
        for(int x: a) for(int y: a){
            if(abs(x-y)==1){
                ans=2;
                break;
            }
        }
        cout<<ans<<'\n';
    }
}