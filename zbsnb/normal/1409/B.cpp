#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int a,b,x,y,n;cin>>a>>b>>x>>y>>n;
        if(n>=a-x+b-y) cout<<(x*y)<<endl;
        else{
            int C=1e18;
            if(n<=a-x) C=min(C,(a-n)*b);
            if(n<=b-y) C=min(C,(b-n)*a);
            if(n>a-x) C=min(C,x*(b-(n-(a-x))));
            if(n>b-y) C=min(C,y*(a-(n-(b-y))));
            cout<<C<<endl;
        }
    }
}