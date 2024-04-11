#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define ll long long
#define int long long

signed main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        n=min(n,m);
        int cnt=m%n;
        int k=m/n;
        int ans=cnt*(k+1)*(k+1)+(n-cnt)*k*k;
        cout<<ans<<endl;
    }
}