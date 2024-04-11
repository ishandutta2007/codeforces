#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int g[N << 2], c[N << 2], m[N << 2], s[N];

#define ls idx<<1
#define rs idx<<1|1

void build(int idx,int l,int r) {
	if(l == r) {
		g[idx] = m[idx] = s[l];
		c[idx] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(ls,l,mid), build(rs,mid+1,r);
	g[idx] = gcd(g[ls], g[rs]);
	if(m[ls] < m[rs])
		m[idx] = m[ls], c[idx] = c[ls];
	else if(m[ls] == m[rs])
		m[idx] = m[ls], c[idx] = c[ls] + c[rs];
	else
		m[idx] = m[rs], c[idx] = c[rs];
}

tuple<int,int,int> query(int idx,int l,int r,int L,int R) {
	if(l > R || L > r) 
		return make_tuple(0,1e9,0);
	if(L <= l && r <= R)
		return make_tuple(g[idx], m[idx], c[idx]);
	int mid = (l + r) >> 1;
	auto [gl, ml, cl] = query(ls,l,mid,L,R);
	auto [gr, mr, cr] = query(rs,mid+1,r,L,R);
	int G = gcd(gl, gr), M = 0, C = 0;
	if(ml < mr)
		M = ml, C = cl;
	else if(ml == mr)
		M = ml, C = cl + cr;
	else
		M = mr, C = cr;
	return make_tuple(G, M, C);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> s[i];
	build(1, 1, n);
	int T;
	cin >> T;
	while(T--) {
		int l, r;
		cin >> l >> r;
		auto [G, M, C] = query(1, 1, n, l, r);
		cout << r - l + 1 - (G == M ? C : 0) << '\n';
	}
}