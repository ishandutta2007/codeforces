#include <bits/stdc++.h>
#define left Aria
using namespace std;
int n, k;
int last[35001];
int left[35001];
int a[35001];
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	int value, lazy;
	pointer left, right;
	segment_tree(int l, int r): l(l), r(r){
		m=(l+r)/2;
		value=-1e9;
		lazy=0;
		if(l!=r){
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
		} 
	}
	void down(){
		left->value+=lazy;
		right->value+=lazy;
		left->lazy+=lazy;
		right->lazy+=lazy;
		lazy=0;
	}
	void up(){
		value=max(left->value, right->value);
	}
	void update(int u, int v, int x){
		if(l>v||r<u) return;
		if(u<=l&&v>=r){
			value+=x;
			lazy+=x;
		}
		else{
			down();
			left->update(u, v, x);
			right->update(u, v, x);
			up();
		}
	}
	void set(int u, int x){
		if(l==r){
			value=x;
		}
		else{
			down();
			if(m>=u) left->set(u, x);
			else right->set(u, x);
			up();
		}
	}
	int get(int u, int v){
		if(l>v||r<u) return -1e9;
		else if(u<=l&&v>=r) return value;
		else{
			down();
			return max(left->get(u, v), right->get(u, v));
		}
	}
};
segment_tree::pointer tree;
int f[35001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++){
		left[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=1; i<=n; i++) f[i]=-1e9;
	for(int cnt=1; cnt<=k; cnt++){
		tree=new segment_tree(0, n);
		for(int i=0; i<=n; i++){
			if(i) tree->update(left[i], i-1, 1);
			int res=tree->get(0, i-1);
			tree->set(i, f[i]);
			f[i]=res;
		}
	}
	cout<<f[n]<<'\n';
	
}