#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, c, d, k;
        cin>>a>>b>>c>>d>>k;
        ((a-=1)/=c)+=1;
        ((b-=1)/=d)+=1;
        if(a+b>k) cout<<"-1\n";
        else cout<<a<<' '<<b<<'\n';
    }
}