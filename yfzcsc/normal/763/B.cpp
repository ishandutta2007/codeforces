#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    cout<<"YES"<<endl;
    while(n--){
        int x,y,a,b;cin>>x>>y>>a>>b;
        cout<<1+(x&1)+2*(y&1)<<endl;
    }
}