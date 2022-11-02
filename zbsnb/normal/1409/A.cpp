#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        if(a==b)cout<<0<<endl;
        else cout<<((abs(a-b)-1)/10+1)<<endl;
    }
}