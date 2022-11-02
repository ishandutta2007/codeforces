#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        if(n%k==0) cout<<1<<endl;
        else if(n>k) cout<<2<<endl;
        else cout<<(k+n-1)/n<<endl;
    }
}