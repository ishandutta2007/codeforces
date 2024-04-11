#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=r*10+(c&15), c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=5e5+7, M=1e6+7;
int n, a[N], cnt[M];
int mn[N], mx[N];
ll ans;
vector<int>vec[M];
void divide(int l, int r) {
	if (l==r) return;
	int mid=(l+r)>>1; divide(l, mid), divide(mid+1, r);
	mn[mid]=mx[mid]=a[mid], mn[mid+1]=mx[mid+1]=a[mid+1];
	for (int i=mid-1; i>=l; i--) mn[i]=min(mn[i+1], a[i]), mx[i]=max(mx[i+1], a[i]);
	for (int i=mid+2; i<=r; i++) mn[i]=min(mn[i-1], a[i]), mx[i]=max(mx[i-1], a[i]);
	for (int i=mid+1, now=mid, nowl=mid; i<=r; i++) {
		while (now>=l && mx[now]<=mx[i]) cnt[mn[now--]]++;
		while (nowl>now && mn[nowl]>=mn[i]) cnt[mn[nowl--]]--;
		for (int x:vec[mx[i]]) {
			if (x>=mn[i]) break;
			ans+=cnt[x];
		}
		if (mx[i]%mn[i]==0) ans+=mid-nowl;
	}
	for (int i=l; i<=mid; i++) cnt[mn[i]]=0;
	for (int i=mid, now=mid+1, nowr=mid+1; i>=l; i--) {
		while (now<=r && mx[now]<mx[i]) cnt[mn[now++]]++;
		while (nowr<now && mn[nowr]>=mn[i]) cnt[mn[nowr++]]--;
		for (int x:vec[mx[i]]) {
			if (x>=mn[i]) break;
			ans+=cnt[x];
		}
		if (mx[i]%mn[i]==0) ans+=nowr-mid-1;
	}
	for (int i=mid+1; i<=r; i++) cnt[mn[i]]=0;
}
inline void work() {
	n=read();
	for (int i=1; i<=n; i++) a[i]=read();
	ans=n, divide(1, n), printf("%lld\n", ans);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
#endif
	n=1e6;
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j+=i) vec[j].push_back(i);
	for (int T=read(); T; T--) work();
	return 0;
}