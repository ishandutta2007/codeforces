#include<bits/stdc++.h>
#define For(i, j, k) for(int i = (j); i <= (k); i++)
using namespace std;
inline int read() {
	int x = 0; char c = ' ';
	for(; !isdigit(c); c = getchar());	
	for(; isdigit(c); c = getchar()) x = x * 10 - '0' + c;
	return x;
}
#define pii pair < int, int >
const int MAXN = 4e5 + 5; int cnt = 0;
struct Segment_tree {
	static const int N = MAXN << 2;
	int a[N], sz;
	#define ls (k << 1)
	#define rs (k << 1 | 1)
	#define mid ((l + r) >> 1)
	void clear(int n) {For(i, 1, 4 * n) a[i] = 0; }
	void update(int k, int l, int r, int pos, int val) {
		cnt++;
		if(l == r) return a[k] += val, void();
		pos <= mid ? update(ls, l, mid, pos, val) : update(rs, mid+1, r, pos, val);
		a[k] = a[ls] + a[rs];
	}
	int query(int k, int l, int r, int ql, int qr) {
//		cerr << "Query : " << k << ' ' << l << ' ' << r << ' ' << ql << ' ' << qr << endl;
		cnt++;
		if(l == ql && r == qr) return a[k];
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		if(mid < ql) return query(rs, mid+1, r, ql, qr);
		return query(ls, l, mid, ql, mid) + query(rs, mid+1, r, mid+1, qr);	
	}
}tr1, tr2;
pii a[MAXN]; int disc[MAXN], t;
int n;
int main() {
	#ifndef ONLINE_JUDGE 
		freopen("pro.in", "r", stdin);
		freopen("pro.out", "w", stdout);
	#endif
	int T = read();
	while(T--) {
		
		n = read();  t = 0;
		For(i, 1, n) disc[++t] = a[i].first = read(), disc[++t] = a[i].second = read();
		sort(disc + 1, disc + 1 + t); t = unique(disc + 1, disc + 1 + t) - disc - 1;
		For(i, 1, n) a[i].first = lower_bound(disc + 1, disc + 1 + t, a[i].first) - disc;
		For(i, 1, n) a[i].second = lower_bound(disc + 1, disc + 1 + t, a[i].second) - disc;tr1.clear(t + 2); tr2.clear(t + 2);
		For(i, 1, n) {
			tr1.update(1, 0, t + 1, a[i].second, 1);
			tr2.update(1, 0, t + 1, a[i].first, 1);
//			cerr << cnt << endl;
		}
		int ans = (1 << 30);
		For(i, 1, n) {
			ans = min(ans, tr1.query(1, 0, t + 1, 0, a[i].first - 1) + tr2.query(1, 0, t + 1, a[i].second + 1, t + 1));
//			cerr << cnt << endl;
		}
		printf("%d\n", ans);
	}
	
	return 0;	
}