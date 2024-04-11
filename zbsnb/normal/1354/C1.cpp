#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double pi=acos(-1);
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cout<<setprecision(9)<<fixed;
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        double ans=tan(pi/2/n);
        cout<<1/ans<<endl;
    }
}