#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
const double pi=acos(-1);
struct P{
	ll x,y;
	P(ll _x=0,ll _y=0):x(_x),y(_y){}
	P operator-(const P&rhs) {
		return P(x-rhs.x,y-rhs.y);
	}
	double geta() {
		return atan2(y,x);
	}
}a[N];
int n,i,j,k,x,y;
double z[N];
unsigned long long ans;
int main(){
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i].x>>a[i].y;
	for(i=1;i<=n;++i){
		int xb=0;
		for(j=1;j<=n;++j)if(i!=j)z[++xb]=(a[j]-a[i]).geta();
		sort(z+1,z+xb+1);
		for(j=1;j<=xb;++j)z[j+xb]=z[j]+2*pi;
		for(j=k=1;j<=xb;++j){
			if(k<j)k=j;
			for(;k<xb*2 && z[k+1]-z[j]<=pi;++k);
			x=k-j;y=xb-1-x;
			ans+=(1ll*x*(x-1)/2)*(1ll*y*(y-1)/2);
		}
	}
	cout<<ans/2;
	return 0;
}