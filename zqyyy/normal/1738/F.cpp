#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int f=1, r=0; char c=getchar();
	while (!isdigit(c)) f^=c=='-', c=getchar();
	while (isdigit(c)) r=(r<<1)+(r<<3)+(c&15), c=getchar();
	return f?r:-r;
}
template<class T> inline void ckmin(T &x, T y) {if (x>y) x=y;}
template<class T> inline void ckmax(T &x, T y) {if (x<y) x=y;}
const int N=1007, mod=998244353, inf=0x3f3f3f3f;
inline void inc(int &x, int y) {x+=y; if (x>=mod) x-=mod;}
inline void dec(int &x, int y) {x-=y; if (x<0) x+=mod;}
inline void mul(int &x, int y) {x=(ll)x*y%mod;}
inline int qpow(int a, int b) {
	int res=1;
	for (; b; b>>=1, mul(a, a)) if (b&1) mul(res, a);
	return res;
}
inline int query(int x) {
	cout<<"? "<<x<<endl;
	return read();
}
int n, deg[N], pa[N], sz[N], sum[N];
int find(int x) {return pa[x]^x?pa[x]=find(pa[x]):x;}
struct cmp {
	bool operator ()(const int &x, const int &y) const {
		return deg[x]^deg[y]?deg[x]>deg[y]:x<y;
	}
};
inline void clear() {}
inline void work() {
	n=read();
	for (int i=1; i<=n; i++) deg[i]=sum[i]=read(), pa[i]=i, sz[i]=1;
	set<int, cmp>s;
	for (int i=1; i<=n; i++) s.insert(i);
	while (!s.empty()) {
		int x=*s.begin(); s.erase(s.begin());
		while (sum[x]>sz[x]*sz[x]) {
			int y=query(x);
			if (find(y)!=y) {
				y=find(y);
				if (sum[y]+sum[x]>(sz[x]+sz[y])*(sz[x]+sz[y])) continue;
				else {pa[x]=y, sz[y]+=sz[x], sum[y]+=sum[x]; break;}
			}
			pa[y]=x, sz[x]+=sz[y], sum[x]+=sum[y], s.erase(y);
		}
	}
	cout<<"! ";
	for (int i=1; i<=n; i++) cout<<find(i)<<" "; cout<<endl;
}
int main() {
//#ifndef ONLINE_JUDGE
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
//#endif
	int test=read();
	while (test--) work(), clear();
	return 0;
}