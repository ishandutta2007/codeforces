#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

struct node{
	long long mxeven, mneven, mxodd, mnodd;
	node(){}
	node(long long mxeven, long long mneven, long long mxodd, long long mnodd): mxeven(mxeven), mneven(mneven), mxodd(mxodd), mnodd(mnodd){}
	node operator +(const node& b) const{
		long long mxeven_ = max(mxeven + b.mxeven, mxodd - b.mnodd);
		long long mneven_ = min(mneven + b.mneven, mnodd - b.mxodd);
		long long mxodd_ = max(mxeven + b.mxodd, mxodd - b.mneven);
		long long mnodd_ = min(mneven + b.mnodd, mnodd - b.mxeven);
		return node(mxeven_, mneven_, mxodd_, mnodd_);
	}
} tree[4 * MAXN];

int n;

void mset(int i, int L, int R, int u, int val){
	if(u < L || R < u)return;
	
	if(L == R){
		tree[i] = node(0, 0, val, val);
		return;
	}else{
		int mid = (L + R) / 2;
		
		mset(2 * i, L, mid, u, val);
		mset(2 * i + 1, mid + 1, R, u, val);
		
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
}

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int q;
		scanf("%d %d", &n, &q);
		
		vector <int> a(n);
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			mset(1, 0, n - 1, i, a[i]);
		}
		
		printf("%lld\n", max(tree[1].mxeven, tree[1].mxodd));
		
		while(q--){
			int l, r;
			scanf("%d %d", &l, &r);
			l--, r--;
			
			mset(1, 0, n - 1, l, a[r]);
			mset(1, 0, n - 1, r, a[l]);
			
			swap(a[l], a[r]);
			
			printf("%lld\n", max(tree[1].mxeven, tree[1].mxodd));
		}
	}
	return 0;
}