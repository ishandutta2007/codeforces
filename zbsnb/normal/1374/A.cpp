#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int x,y,n;cin>>x>>y>>n;
        int b=(n-y)/x;
        cout<<(b*x+y)<<endl;
    }
}