#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int b, p, f, h, c;
        cin>>b>>p>>f;
        cin>>h>>c;
        b/=2;
        if(h<c){
            swap(h, c);
            swap(p, f);
        }
        int cnt=min(b, p);
        b-=cnt;
        int ans=cnt*h+min(b, f)*c;
        cout<<ans<<'\n';
    }
}