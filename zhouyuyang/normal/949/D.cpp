#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x); i<=(y); i++)
#define per(i,x,y) for(int i=(x); i>=(y); i--)
#define N 200010
#define ll long long
using namespace std;
int n,d,b,h,l,r,x1,x2,w;
ll f[N],g[N],tot,now,a[N];
int main() {
	scanf("%d%d%d",&n,&d,&b);
	rep(i,1,n) scanf("%d",&a[i]);
	h=n/2; tot=h*b;
	rep(i,1,n) { f[i]=f[i-1]+min(tot,a[i]); tot-=min(tot,a[i]); }
	tot=h*b;
	per(i,n,1) { g[i]=g[i+1]+min(tot,a[i]); tot-=min(tot,a[i]); }
	w=h; r=0; now=0;
	rep(i,1,w) {
		r=min(r+d+1,n);
		if(now+b<=f[r]) now+=b; else x1++;
	}
	w=n-h+1; l=n+1; now=0;
	per(i,n,w) {
		l=max(l-d-1,1);
		if(now+b<=g[l]) now+=b; else x2++;
	}
	printf("%d",max(x1,x2));
	return 0;
}