#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        int tmp1=max(2*a,b);
        int tmp2=max(2*b,a);
        cout<<min(tmp1*tmp1,tmp2*tmp2)<<endl;
    }
}