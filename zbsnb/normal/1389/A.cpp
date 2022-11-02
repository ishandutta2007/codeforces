#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        if(b<2*a)cout<<"-1"<<" "<<"-1"<<endl;
        else cout<<a<<" "<<(2*a)<<endl;
    }
}