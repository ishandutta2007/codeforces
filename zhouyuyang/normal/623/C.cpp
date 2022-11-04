#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
ll lmn[N],lmx[N],rmn[N],rmx[N];
int n;
struct jdb{
	ll x,y;
}a[N];
bool cmp(jdb a,jdb b){
	return a.x!=b.x?a.x<b.x:a.y<b.y;
}
ll sgr(ll x){
	return x*x;
}
bool check(ll mid){
	int r=1;
	for (int l=1;l<=n;l++){
		if (a[l].x>0) break;
		for (;r<n&&sgr(a[r+1].x-a[l].x)<=mid&&abs(a[r+1].x)<=abs(a[l].x);) r++;
		for (;abs(a[r].x)>abs(a[l].x);) r--;
		ll low=min(lmn[l-1],rmn[r+1]);
		ll high=max(lmx[l-1],rmx[r+1]);
		if (sgr(high-low)<=mid&&max(sgr(high),sgr(low))+max(sgr(a[l].x),sgr(a[r].x))<=mid)
			return 1;
	}
	int l=n;
	for (int r=n;r;r--){
		if (a[r].x<0) break;
		for (;l>1&&sgr(a[l-1].x-a[r].x)<=mid&&abs(a[l-1].x)<=abs(a[r].x);) l--;
		for (;abs(a[l].x)>abs(a[r].x);) l++;
		ll low=min(lmn[l-1],rmn[r+1]);
		ll high=max(lmx[l-1],rmx[r+1]);
		if (sgr(high-low)<=mid&&max(sgr(high),sgr(low))+max(sgr(a[l].x),sgr(a[r].x))<=mid)
			return 1;
	}
	return 0;
}
int main(){
	ll xmn,xmx,ymn,ymx;
	xmn=ymn=1e16; xmx=ymx=-1e16;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%I64d%I64d",&a[i].x,&a[i].y);
		xmn=min(xmn,a[i].x);
		xmx=max(xmx,a[i].x);
		ymn=min(ymn,a[i].y);
		ymx=max(ymx,a[i].y);
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		lmn[i]=min(a[i].y,lmn[i-1]);
		lmx[i]=max(a[i].y,lmx[i-1]);
	}
	for (int i=n;i;i--){
		rmn[i]=min(a[i].y,rmn[i+1]);
		rmx[i]=max(a[i].y,rmx[i+1]);
	}
	ll l=-1,r=min(sgr(xmx-xmn),sgr(ymx-ymn)),ans=r;
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%I64d",ans);
}