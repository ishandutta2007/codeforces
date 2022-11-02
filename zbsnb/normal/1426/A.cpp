#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        if(n<=2) cout<<1<<endl;
        else{
            n-=2;
            cout<<(n-1)/x+2<<endl;
        }
    }
}