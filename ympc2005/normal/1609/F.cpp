#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char buf[100000],*p1=buf,*p2=buf,ch;
ll result;
#define getc() p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
inline ll read(){
    ch=getc();result=0;
    while (ch<'0'||ch>'9') ch=getc();
    while (ch>='0'&&ch<='9') result=result*10+(ch^48),ch=getc();
    return result;
}

typedef pair <int, int> pii;

const int N = 1e6 + 10;

int n, b[N], s[N], top, m, ha[N], hd[N], tot, st[N<<2], ed[N<<2], nex[N<<2];

ll a[N], ans;

pii mx[N], mn[N];

vector <int> id[65];

namespace Seg {	
	int add[N<<2], mx[N<<2], cx[N<<2];
	
	void up_(int o) {
		int lc = o<<1, rc = o<<1|1;
		
		if (mx[lc] > mx[rc]) {
			mx[o] = mx[lc];
			cx[o] = cx[lc];
		} else if (mx[lc] < mx[rc]) {
			mx[o] = mx[rc];
			cx[o] = cx[rc];
		} else {
			mx[o] = mx[lc];
			cx[o] = cx[lc] + cx[rc];
		}
	}
	
	void add_(int o, int k) {
		mx[o] += k;
		add[o] += k;
	}
	
	void down_(int o) {
		if (add[o]) {
			add_(o<<1, add[o]);
			add_(o<<1|1, add[o]);
			add[o] = 0;
		}
	}
	
	void upd_(int o, int l, int r, int x, int y, int k) {
		if (x <= l && r <= y) {
			add_(o, k);
			return;
		}
		
		int mid = (l + r)>>1;
		down_(o);
		
		if (x <= mid) {
			upd_(o<<1, l, mid, x, y, k);
		}
		
		if (mid < y) {
			upd_(o<<1|1, mid + 1, r, x, y, k);
		}
		
		up_(o);
	}
	
	void build_(int o, int l, int r) {
		cx[o] = r - l + 1;
		mx[o] = add[o] = 0;
		
		if (l == r) {
			return;
		}
		
		int mid = (l + r)>>1;
		build_(o<<1, l, mid);
		build_(o<<1|1, mid + 1, r);
	}
}

void add_(int i, int j, int k) {
	nex[++tot] = ha[i];
	st[tot] = j, ed[tot] = k;
	ha[i] = tot;
}

void del_(int i, int j, int k) {
	nex[++tot] = hd[i];
	st[tot] = j, ed[tot] = k;
	hd[i] = tot;
}

void solve_(int k) {
	for (int i = 1; i <= n; i++) {
		ha[i] = hd[i] = 0;
	}
	
	tot = 0;
	
	Seg :: build_(1, 1, n);
	
	for (int i : id[k]) {
		add_(mn[i].first, i, mn[i].second);
		del_(i, i, mn[i].second);
		add_(mx[i].first, i, mx[i].second);
		del_(i, i, mx[i].second);
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = ha[i]; j; j = nex[j]) {
			Seg :: upd_(1, 1, n, st[j], ed[j], 1);
		}
		
		if (Seg :: mx[1] == 2) {
			ans += Seg :: cx[1];
		}
		
		for (int j = hd[i]; j; j = nex[j]) {
			Seg :: upd_(1, 1, n, st[j], ed[j], -1);
		}
	}
}

int main() {
	n = read();
	
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		b[i] = __builtin_popcountll(a[i]);
		
		m = max(m, b[i]);
		id[b[i]].push_back(i);
	}
	
	top = 0;
	
	for (int i = 1; i <= n; i++) {
		while (top && a[s[top]] <= a[i]) {
			mx[s[top--]].second = i - 1;
		}
		
		mx[i].first = s[top] + 1;
		s[++top] = i;
	}
	
	for (int i = 1; i <= top; i++) {
		mx[s[i]].second = n;
	}
	
	top = 0;
	
	for (int i = 1; i <= n; i++) {
		while (top && a[s[top]] > a[i]) {
			mn[s[top--]].second = i - 1;
		}
		
		mn[i].first = s[top] + 1;
		s[++top] = i;
	}
	
	for (int i = 1; i <= top; i++) {
		mn[s[i]].second = n;
	}
	
	for (int i = 0; i <= m; i++) {
		solve_(i);
	}
	
	printf("%lld\n", ans);
}