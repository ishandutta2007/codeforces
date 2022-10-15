#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define IN inline ll
typedef long long ll;
ll n,m,k,s,T,x,y,l,r;
IN gcd(ll x,ll y){
    return !y?x:gcd(y,x%y);
}
int main(){
    cin>>n>>m>>T;
    k=gcd(n,m);n/=k;m/=k;
    //s=n/k*m;
    while(T--){
        cin>>x>>y>>l>>r;
        y--;r--;
        if(x==1)y/=n;
        else y/=m;
        if(l==1)r/=n;
        else r/=m;
        if(y==r)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
	return 0;
}