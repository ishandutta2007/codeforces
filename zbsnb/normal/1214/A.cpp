#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
    ll n,a,b;cin>>n>>a>>b;b*=5;
    ll lc=lcm(a,b);
    if(n>2*lc)n=n%lc+lc;
    ll ans=n;
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            ll tmp=n-a*i-b*j;
            if(tmp>=0){
                ans=min(ans,tmp);
            }
        }
    }
    cout<<ans<<endl;
}