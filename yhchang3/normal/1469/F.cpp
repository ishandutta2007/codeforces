#include<bits/stdc++.h>
using namespace std;

#define ls idx<<1
#define rs idx<<1|1
template<int SZ> struct SEGTREE{
	long long int val[SZ],tag[SZ];
	inline void pull(int idx){
		val[idx]=val[ls]+val[rs];
	}
	inline void push(int idx,int l,int r){
		int mid=(l+r)>>1;
		tag[ls]+=tag[idx],tag[rs]+=tag[idx];
		val[ls]+=tag[idx]*(mid-l+1),val[rs]+=tag[idx]*(r-mid);
		tag[idx]=0;
	}
	void build(int idx,int l,int r){
		tag[idx]=0;
		if(l==r)	return val[idx]=0,void();
		int mid=(l+r)>>1;
		build(ls,l,mid),build(rs,mid+1,r),pull(idx);
	}
	void modify(int idx,int l,int r,int L,int R,long long int v){
		if(L>r||l>R)	return;
		if(L<=l&&r<=R)	return tag[idx]+=v,val[idx]+=v*(r-l+1),void();
		push(idx,l,r);
		int mid=(l+r)>>1;
		modify(ls,l,mid,L,R,v),modify(rs,mid+1,r,L,R,v),pull(idx);
	}
	long long int query(int idx,int l,int r,int L,int R){
		if(L>r||l>R)	return 0;
		if(L<=l&&r<=R)	return val[idx];
		push(idx,l,r);
		int mid=(l+r)>>1;
		long long int res=query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
		pull(idx);
		return res;
	}
	int query(int idx,int l,int r,int k){
		if(l == r)	return l;
		push(idx, l, r);
		int mid = (l + r) >> 1;
		int res = 0;
		if(val[ls] >= k)
			res = query(ls, l, mid, k);
		else
			res = query(rs, mid+1, r, k - val[ls]);
		pull(idx);
		return res;
	}
};

SEGTREE<2000010> ST;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> chain(n);
	for(int &x:chain)
		cin >> x;
	sort(chain.begin(), chain.end(), greater<int>());
	const int N = 5e5;
	ST.build(1, 0, N);
	ST.modify(1, 0, N, 0, 0, 1);
	int now = 0;
	int ans = 1e9;
	for(int c:chain) {
		while(!ST.query(1, 0, N, now, now)) now++;
		ST.modify(1, 0, N, now,  now, -1);
		int L = c / 2, R = c / 2;
		if(c % 2 == 0)	R--;
		ST.modify(1, 0, N, now + 2, now + L + 1, 1);
		ST.modify(1, 0, N, now + 2, now + R + 1, 1);
		if(ST.query(1, 0, N, 0, N) >= k)
			ans = min(ans, ST.query(1, 0, N, k));
	}
	if(ans == 1e9)
		ans = -1;
	cout << ans << endl;
}