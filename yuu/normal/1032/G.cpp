#include <bits/stdc++.h>
using namespace std;
pair <int, int> best(pair <int, int> a, pair <int, int> b){
	return make_pair(min(a.first, b.first), max(a.second, b.second));
}
int n;
int a[300001];
pair <int, int> p[19][300001];
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	pair <int, int> value;
	pointer left, right;
	segment_tree(int l, int r, pair <int, int> *p): l(l), r(r){
		m=(l+r)/2;
		if(l==r) value=p[l];
		else{
			left=new segment_tree(l, m, p);
			right=new segment_tree(m+1, r, p);
			value=best(left->value, right->value);
		}
	}
	void make_tree(pair <int, int> *p){
		if(l==r) value=p[l];
		else{
			left->make_tree(p);
			right->make_tree(p);
			value=best(left->value, right->value);
		}
	}
	pair <int, int> get(int u, int v){
		if(l>v||r<u) return make_pair(1e9, -1e9);
		else if(u<=l&&v>=r) return value;
		else return best(left->get(u, v), right->get(u, v));
	}
	pair <int, int> get(pair <int, int> p){
		return get(p.first, p.second);
	}
};
segment_tree::pointer tree;
pair <int, int> now[300001];
int ans[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) a[i+n]=a[i];
	for(int i=1; i<=n; i++) a[i+n+n]=a[i];
	for(int i=1; i<=n*3; i++){
		p[0][i].first=max(1, i-a[i]);
		p[0][i].second=min(n+n+n, i+a[i]);
	}
	tree=new segment_tree(1, n*3, p[0]);
	int mx=0;
	for(int i=1, len=4; len<=n; i++, len*=2){
		mx=i;
		for(int x=1; x<=n*3; x++)	p[i][x]=tree->get(p[i-1][x]);
		tree->make_tree(p[i]);
	}
	for(int i=n+1; i<=n+n; i++) now[i]=make_pair(i, i);
	for(int j=mx; j>=0; j--){
		tree->make_tree(p[j]);
		for(int i=n+1; i<=n+n; i++){
			auto nx=tree->get(now[i]);
			if(nx.second-nx.first+1<n){
				ans[i]|=1<<j;
				now[i]=nx;
			}
		}
	}
	for(int i=n+1; i<=n+n; i++){
		if(n>1) ans[i]++;
		cout<<ans[i]<<" \n"[i==n+n];
	}
}