#include<bits/stdc++.h>
using namespace std;

int val[2000010];
#define ls idx<<1
#define rs idx<<1|1
void build(int idx,int l,int r) {
	if(l == r) {
		val[idx] = (l == 0);
		return;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	val[idx] = max(val[ls], val[rs]);
}
void modify(int idx,int l,int r,int x,int v) {
	if(l == r) {
		val[idx] = max(val[idx], v);
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid)
		modify(ls,l,mid,x,v);
	else
		modify(rs,mid+1,r,x,v);
	val[idx] = max(val[ls], val[rs]);
}
int query(int idx,int l,int r,int L,int R) {
	if(l > R || L > r)	return 0;
	if(L <= l && r <= R)	return val[idx];
	int mid = (l + r) >> 1;
	return max(query(ls,l,mid,L,R), query(rs,mid+1,r,L,R));
}

int a[500010];
int nxt[500010];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i], nxt[i] = -1;
		build(1, 0, n);
		stack<int> st;
		vector<vector<pair<int,int>>> event(n + 1);
		for(int i=1;i<=n;i++) {
			while(st.size() && a[st.top()] <= a[i])
				nxt[st.top()] = i, st.pop();
			st.emplace(i);
		}
		event[1].emplace_back(0, 2);
		for(int i=1;i<=n;i++) {
			int cur = query(1,0,n,0,a[i]) + 1;
			modify(1,0,n,a[i],cur);
			if(nxt[i] != -1)
				event[nxt[i]].emplace_back(a[i], cur + 1);
			for(auto [u,v]:event[i])
				modify(1,0,n,u,v);
		}
		cout << query(1,0,n,0,n) - 1 << '\n';
	}
}