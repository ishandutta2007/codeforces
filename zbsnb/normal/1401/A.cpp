#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        if(a<=b)cout<<b-a<<endl;
        else if((a-b)&1) cout<<1<<endl;
        else cout<<0<<endl;
    }
}