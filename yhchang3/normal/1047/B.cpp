#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x,y;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        if(ans<x+y)
            ans=x+y;
    }
    cout<<ans<<endl;
}