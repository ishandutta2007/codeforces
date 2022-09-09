#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll l,r,m,x,y,n,i,cnt,a[50000],ans;
inline ll calc(ll x){
	static ll ans;
	for(ans=x;x;x/=10)ans+=x%10;
	return ans; 
}
int main(){
	cin>>n;
	for(l=1,r=n+500;l<r;){
		m=(l+r+1)>>1;
		if(calc(m)<n-500)l=m;
			else r=m-1;
	}
	x=l;
	for(l=1,r=n+500;l<r;){
		m=(l+r+1)>>1;
		if(calc(m)<n+500)l=m;
			else r=m-1;
	}
	y=l;
	for(i=x;i<=y;++i)if(calc(i)==n)++ans;cout<<ans<<endl;
	for(i=x;i<=y;++i)if(calc(i)==n)cout<<i<<" ";
	return 0;
}