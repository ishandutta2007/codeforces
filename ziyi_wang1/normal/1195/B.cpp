#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define IN inline ll
typedef long long ll;
ll n,m;
IN divided(ll x,ll y){
	if(x==y)return x;
	re mid=(x+y)>>1;
	if(1ll*((n-mid)*(n-mid+1)/2ll)-mid>m)x=mid+1;
	else y=mid;
	return divided(x,y);
}
int main(){
	cin>>n>>m;
	cout<<divided(0,n);
    return 0;
}