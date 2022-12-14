#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
const int inf = 1e9;
typedef long long int ll;

int tag[maxn << 2], mn[maxn << 2];
ll sum[maxn << 2];
int a[maxn];

#define ls idx<<1
#define rs idx<<1|1

inline void pull(int idx){
	mn[idx] = min(mn[ls], mn[rs]);
	sum[idx] = sum[ls] + sum[rs];
}

inline void push(int idx,int l,int r){
	if(tag[idx] != 0){
		int mid = (l + r) >> 1;
		mn[ls] = mn[rs] = tag[idx];
		tag[ls] = tag[rs] = tag[idx];
		sum[ls] = 1LL * (mid - l + 1) *  tag[idx];
		sum[rs] = 1LL * (r - mid) * tag[idx];
		tag[idx] = 0;
	}
}

void build(int idx, int l, int r){
	if(l==r)	return mn[idx] = a[l], tag[idx] = 0, sum[idx] = a[l], void();
	int mid = (l + r) >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	pull(idx);
}

int search(int idx,int l,int r,int tar){
	if(l == r)	return mn[idx] <= tar ? l : inf;
	int mid = (l + r) >> 1;
	push(idx, l, r);
	if(mn[ls] <= tar)	return search(ls, l, mid, tar);
	else	return search(rs, mid + 1, r ,tar);
}

void modify(int idx,int l,int r,int L,int R,int tar){
	if(L > r || l > R)	return;
	if(L <= l && r <= R){
		tag[idx] = mn[idx] = tar;
		sum[idx] = 1LL * (r - l + 1) * tar;
		return;
	}
	int mid = (l + r) >> 1;
	push(idx,l,r);
	modify(ls,l,mid,L,R,tar), modify(rs,mid+1,r,L,R,tar);
	pull(idx);
}

int query(int idx,int l,int r,int lb,int &b){
	if(r < lb || mn[idx] > b)	return 0;
	if(l >= lb && sum[idx] <= b){
		b -= sum[idx];
		return r - l + 1;
	}
	int mid = (l + r) >> 1;
	push(idx,l,r);
	return query(ls,l,mid,lb,b) + query(rs,mid+1,r,lb,b);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	build(1,1,n);
	while(q--){
		int op, x, y;
		cin >> op >> x >> y;
		if(op == 1){
			int bound = search(1, 1, n, y);
			if(x >= bound)
				modify(1, 1, n, bound, x, y);
		}
		else{
			cout << query(1,1,n,x,y) << '\n';
		}
	}
}