#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline char getc() {
	return getchar();
	static char *p1, *p2, buf[1<<20];
	return p1==p2?(p2=(p1=buf)+fread(buf, 1, 1<<20, stdin), p1==p2?EOF:*p1++):*p1++;
}
inline int read() {
	int f=1, r=0; char c=getc();
	while (!isdigit(c)) f^=c=='-', c=getc();
	while (isdigit(c)) r=r*10+c-48, c=getc();
	return f?r:-r;
}
#define fi first
#define se second
template<class T> inline void ckmin(T &x, T y) {if (y<x) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1010, inf=1e9;
const ll INF=1e18;
inline int query(ll x) { return cout<<"? "<<x<<endl, read();}
int s_p, pr[N], v[N], val[N];
vector<pair<ll, int> >vec;
inline void init(int n) {
	for (int i=2; i<=n; i++) {
		if (!v[i]) {
			v[i]=i, pr[++s_p]=i, val[s_p]=1;
			while ((ll)val[s_p]*pr[s_p]<=inf) val[s_p]*=pr[s_p];
		}
		for (int j=1; j<=s_p && i*pr[j]<=n; j++) {
			v[i*pr[j]]=1;
			if (i%pr[j]==0) break;
		}
	}
	for (int l=1, r=0; l<s_p; l=r+1) {
		ll tmp=1;
		while (r<s_p-1 && (__int128)tmp*pr[r+1]<=INF) tmp*=pr[++r];
		vec.push_back({tmp, pr[r+1]});
		if ((int)vec.size()==22) break;
	}
}

inline void work() {
	int ans=1, cnt=0, p=1, v=1;
	for (auto &[X, P]:vec) {
		int x=query(X); cnt++;
		for (; pr[p]<P && cnt<22; p++) {
			if (x%pr[p]) continue;
			int y=query(val[p]), c=1;
			while (y%pr[p]==0) c++, y/=pr[p];
			ans*=c, cnt++, v*=y;
		}
		if (v>=inf/P/P/P) {cout<<"! "<<ans*2<<endl; return;}
		if (cnt==22) break;
	}
	cout<<"! "<<max(ans*2, 8)<<endl;
}
int main() {/*
#ifndef ONLINE_JUDGE
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	#endif*/
	init(1000);
	int test=read();
	while (test--) work();
	return 0;
}