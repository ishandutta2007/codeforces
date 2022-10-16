#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        if(x%2==0) cout<<x/2<<'\n';
        else cout<<1+(x-3)/2<<'\n';
    }
}