#include<bits/stdc++.h>
using namespace std;
#define ll long long
	
ll T, n, xi[101000], yi[101000], zi[101000];
	
ll calc(ll x,ll y,ll z){
	ll res=0;
	for (int i=1;i<=n;++i) res=max(res,abs(xi[i]-x)+abs(yi[i]-y)+abs(zi[i]-z));
	return res;
}
	
int main(){
	for (cin>>T;T--;){
		cin>>n;
		for (int i=1;i<=n;++i) scanf("%lld%lld%lld",&xi[i],&yi[i],&zi[i]);
		if (n==1){
			printf("%lld %lld %lld\n",xi[1],yi[1],zi[1]);
			continue;
		}
		ll x=0, y=0, z=0, ans=calc(x,y,z);
		for (ll d=1e18;d;){
			bool fl=1;
			for (ll dx=-d;fl&&dx<=d;dx+=d)
				for (ll dy=-d;fl&&dy<=d;dy+=d)
					for (ll dz=-d;fl&&dz<=d;dz+=d){
						ll t=calc(x+dx,y+dy,z+dz);
						if (t<ans) ans=t, x+=dx, y+=dy, z+=dz, fl=0;
					}
			if (fl) d>>=1;
		}
		for (int fl=1;fl;){
			fl=0;
			for (ll xx=x-3;xx<=x+3;++xx)
				for (ll yy=y-3;yy<=y+3;++yy)
					for (ll zz=z-3;zz<=z+3;++zz){
						ll t=calc(xx,yy,zz);
						if (t<ans) ans=t, x=xx, y=yy, z=zz, fl=1;
					}
		}
		printf("%lld %lld %lld\n",x,y,z);
	}
}