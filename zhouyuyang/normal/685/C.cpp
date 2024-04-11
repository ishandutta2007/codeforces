#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define inf ((ll)4e18)
#define fi first
#define se second
#define N 100005
using namespace std;
ll x[N],y[N],z[N];
ll A,B,C;
int n;
void upd(pll &s,ll l,ll r){
	s.fi=max(s.fi,l);
	s.se=min(s.se,r);
	if (s.fi%2) s.fi++;
	if (s.se%2) s.se--;
}
bool solve(ll mid){
	for (int r=0;r<2;r++){
		pll a(-inf,inf),b,c,d;
		b=c=d=a;
		for (int i=1;i<=n;i++){
			ll p=-x[i]+y[i]+z[i];
			upd(a,p-mid-r,p+mid-r);
			p=x[i]-y[i]+z[i];
			upd(b,p-mid-r,p+mid-r);
			p=x[i]+y[i]-z[i];
			upd(c,p-mid-r,p+mid-r);
			p=x[i]+y[i]+z[i];
			upd(d,p-mid-3*r,p+mid-3*r);
		}
		upd(d,a.fi+b.fi+c.fi,a.se+b.se+c.se);
		if (a.fi>a.se||b.fi>b.se||c.fi>c.se||d.fi>d.se) continue;
		ll sa=min(a.se,d.fi-b.fi-c.fi);
		ll sb=min(b.se,d.fi-c.fi-sa);
		ll sc=d.fi-sa-sb;
		A=(sb+sc)/2+r;
		B=(sa+sc)/2+r;
		C=(sa+sb)/2+r;
		return 1;
	}
	return 0;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%I64d%I64d%I64d",&x[i],&y[i],&z[i]);
		ll l=0,r=inf,ans;
		while (l<=r){
			ll mid=(l+r)>>1;
			if (solve(mid))
				ans=mid,r=mid-1;
			else l=mid+1;
		}
		solve(ans);
		printf("%I64d %I64d %I64d\n",A,B,C);
	}
}