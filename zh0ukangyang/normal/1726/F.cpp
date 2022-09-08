#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f)) 
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7, mod = 998244353;
int n, t;

const int M = 9e6 + 7;
int ch[M][2], rt, tot;
bool tag[M];
ll mn[M], cm[M];
void make (int &x, int L, int R) { 
	if (!x) x = ++tot, mn[x] = -R, cm[x] = 0; 
}
void mark (int &x) {
	if(!x) x = ++ tot;
	tag[x] = 1, mn[x] = cm[x] = 1e18;
}
void push (int x) {
	if(tag[x]) mark (ch[x][0]), mark(ch[x][1]), tag[x] = 0;
}
void change (int &x, int L, int R, int p, ll w) {
	if (!x) x = ++tot, mn[x] = -R;
	if (L == R) return mn[x] = min(mn[x], w - R), cm[x] = min(cm[x], w), void ();
	int mid = (L + R) >> 1;
	make (ch[x][0], L, mid);
	make (ch[x][1], mid + 1, R);
	push (x);
	if (p <= mid) change (ch[x][0], L, mid, p, w);
	else change (ch[x][1], mid + 1, R, p, w);
	mn[x] = min(mn[ch[x][0]], mn[ch[x][1]]);
	cm[x] = min(cm[ch[x][0]], cm[ch[x][1]]);
}
ll query (int &x, int L, int R, int l, int r) {
	if (!x) x = ++tot, mn[x] = -R;
	ll ret = 1e18;
	if (l <= L && R <= r) return ret = mn[x], mark(x), ret;
	int mid = (L + R) >> 1;
	make (ch[x][0], L, mid);
	make (ch[x][1], mid + 1, R);
	push (x);
	if(l <= mid) ret = min(ret, query (ch[x][0], L, mid, l, r));
	if(r > mid) ret = min(ret, query (ch[x][1], mid + 1, R, l, r));
	mn[x] = min(mn[ch[x][0]], mn[ch[x][1]]);
	cm[x] = min(cm[ch[x][0]], cm[ch[x][1]]);
	return ret; 
}
ll Get (int l, int r) { 
	return query (rt, 0, t - 1, l, r) + r + 1;
}
ll calc (int l, int r) {
	if(l <= r) return Get (l, r);
	return min(Get(l, t - 1) + r + 1, Get(0, r));
}


int g[N], c[N], d[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> t;
	L(i, 1, n) 
		cin >> g[i] >> c[i];
	ll s = 0;
	L(i, 2, n) 
		cin >> d[i], s += d[i];
	L(i, 2, n) 
		d[i] = (d[i] + d[i - 1]) % t;
	L(i, 1, n) 
		c[i] = (c[i] + d[i]) % t;
	L(i, 1, n) 
		c[i] = (t - c[i]) % t;
	L(i, 1, n) {
		int l = (c[i] + g[i]) % t, r = (c[i] + t - 1) % t;
		change(rt, 0, t - 1, (r + 1) % t, calc(l, r));
	} 
	cout << cm[rt] + s << '\n'; 
	return 0;
}