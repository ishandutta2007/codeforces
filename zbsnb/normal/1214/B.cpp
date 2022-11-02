#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

int main(){
    ll n,a,b;cin>>a>>b>>n;
    ll ans=0;
    for(int i=0;i<=n;i++){
        ll tmp=n-i;
        if(i<=a&&tmp<=b)ans++;
    }
    cout<<ans<<endl;
}