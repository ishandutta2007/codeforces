#include <bits/stdc++.h>
#define left Kafuu
#define right Chino
using namespace std;
int n;
int a[400001];
int left[400001];
int right[400001];
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m, val, lazy;
	pointer left, right;
	segment_tree(int l, int r){
		this->l=l;
		this->r=r;
		m=(l+r)/2;
		val=lazy=0;
		if(l!=r){
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
		}
	}
	void down(){
		left->val+=lazy;
		right->val+=lazy;
		left->lazy+=lazy;
		right->lazy+=lazy;
		lazy=0;
	}
	void up(){
		val=max(left->val, right->val);
	}
	int get(int u, int v){
		if(l>v||r<u) return 0;
		if(u<=l&&v>=r) return val;
		else{
			down();
			return max(left->get(u, v), right->get(u, v));
		}
	}
	void update(int u, int v, int x){
		if(l>v||r<u) return;
		if(u<=l&&v>=r){
			val+=x;
			lazy+=x;
		}
		else{
			down();
			left->update(u, v, x);
			right->update(u, v, x);
			up();
		}
	}
};
segment_tree::pointer tree;
void update(int i, int x){
	tree->update(left[i], right[i], x);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) a[i+n]=a[i];
	tree=new segment_tree(1, n+n);
	{
		deque <int> q;
		for(int i=1; i<=n+n; i++){
			while((!q.empty())&&a[i]<a[q.back()]) q.pop_back();
			if(q.empty()) left[i]=1;
			else left[i]=q.back()+1;
			q.push_back(i);
		}
	}
	{
		deque <int> q;
		for(int i=n+n; i>=1; i--){
			while((!q.empty())&&a[i]<a[q.back()]) q.pop_back();
			if(q.empty()) right[i]=n+n;
			else right[i]=q.back()-1;
			q.push_back(i);
		}
	}
	for(int i=1; i<=n; i++) update(i, 1);
	int ans=n+1;
	int best=0;
	for(int i=n+1; i<=n+n; i++){
		update(i-n, -1);
		update(i, 1);
		int res=tree->get(i-n+1, i);
		// cerr<<res<<'\n';
		if(res<ans){
			ans=res;
			best=i-n;
		}
	}
	if(best==n) best=0;
	cout<<ans<<' '<<best<<'\n';
}