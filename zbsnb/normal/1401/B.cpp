#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int a,b,c;
        int d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        int tmp=min(c,e);
        c-=tmp;e-=tmp;
        int ans=2*tmp;
        int rest=c+a;
        if(rest<f)ans-=2*(f-rest);
        cout<<ans<<endl;
    }
}