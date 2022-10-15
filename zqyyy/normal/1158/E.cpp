#include <bits/stdc++.h>
namespace {
    using namespace std;
	const int N=1007;
	struct seg {
		int l, r; vector<int>d;
		seg(int _l=0, int _r=0, vector<int>_d={}):l(_l), r(_r), d(_d) {}
		inline void push_back(int x) {d.push_back(x);}
	};
	int n, fa[N], D[N];
	bool vis[N], a[N], b[N], flg[N];
	inline void qry() {
	    printf("? ");
	    for (int i=1; i<=n; i++) printf("%d ", D[i]); cout<<endl;
		for (int i=1; i<=n; i++) scanf("%1d", &flg[i]);
	}
	vector<int>d[N];
	inline void solve1() {
		vector<seg>now={seg(0, n)};
		for (int i=2; i<=n; i++) now[0].push_back(i);
		d[0].push_back(1), vis[1]=true;
		while (!now.empty()) {
			vector<seg>nxt; int sz=now.size();
			for (int o=0; o<2 && o<sz; o++) {
				for (int i=1; i<=n; i++) D[i]=0;
				for (int i=o; i<sz; i+=2) {
					int l=now[i].l, r=now[i].r, mid=(l+r+1)>>1;
					for (int x:d[l]) D[x]=mid-l;
				}
				qry();
				for (int i=1; i<=n; i++) a[i]=flg[i];
				for (int i=1; i<=n; i++) D[i]=0;
				for (int i=o; i<sz; i+=2) {
					int l=now[i].l, r=now[i].r, mid=(l+r+1)>>1;
					for (int x:d[l]) D[x]=mid-l-1;
				}
				qry();
				for (int i=1; i<=n; i++) b[i]=flg[i];
				for (int i=o; i<sz; i+=2) {
					int l=now[i].l, r=now[i].r, mid=(l+r+1)>>1;
					for (int x:now[i].d) if (a[x] && !b[x]) d[mid].push_back(x), vis[x]=true;
					if (mid-l>=2) {
						nxt.push_back(seg(l, mid-1));
						for (int x:now[i].d) if (!vis[x] && a[x] && b[x]) nxt.back().push_back(x);
					}
					if (r-mid+1>=2) {
						nxt.push_back(seg(mid, r));
						for (int x:now[i].d) if (!vis[x] && !a[x] && !b[x]) nxt.back().push_back(x);
					}
				}
			}
			swap(now, nxt);
			sort(now.begin(), now.end(), [&](const seg &x, const seg &y){return x.l<y.l;});
		}
	}
	inline void solve2() {
		int lg=__lg(n);
		for (int o=0; o<=2; o++)
			for (int j=lg; ~j; j--) {
				for (int i=1; i<=n; i++) D[i]=0;
				for (int i=o; i<n; i+=3)
					for (int x:d[i]) if (x>>j&1) D[x]=1;
				qry();
				for (int i=o+1; i<n; i+=3)
					for (int x:d[i]) if (flg[x]) fa[x]|=1<<j;
			}
	    cout<<"!"<<endl;
		for (int i=2; i<=n; i++) cout<<fa[i]<<" "<<i<<endl;
	}
}
int main() {cin>>n, solve1(), solve2();}