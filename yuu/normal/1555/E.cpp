#include <bits/stdc++.h>
using namespace std;
int n, m;
class segment{
public:
	int l, r, w;
	segment(int l, int r, int w): l(l), r(r), w(w){}
	bool operator < (const segment &s) const noexcept{
		return w<s.w;
	}
};
vector <segment> v;

class segment_tree{
public:
segment_tree *left, *right;
	int l, r, m;
	int cover, count;
	segment_tree(int l, int r): l(l), r(r), m((l+r)/2){
		cover=0;
		count=r-l+1;
		if(l!=r){
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
		}
	}
	void make(int u, int v, int x){
		if(l>v||r<u) return;
		if(u<=l&&v>=r){
			cover+=x;
			if(cover) count=0;
			else if(l!=r) count=left->count+right->count;
			else count=1;
		}
		else{
			left->make(u, v, x);
			right->make(u, v, x);
			if(cover) count=0;
			else count=left->count+right->count;
		}
	}
};
segment_tree* tree;
void solve(){
	cin>>n>>m;
	m--;
	for(int i=1, l, r, w; i<=n; i++){
		cin>>l>>r>>w;
		r--;
		v.emplace_back(l, r, w);
	}
	sort(v.begin(), v.end());
	int ans=1e9;
	tree=new segment_tree(1, m);
	for(int i=0, j=0; i<v.size(); i++){
		while((j<v.size())&&(tree->count)){
			tree->make(v[j].l, v[j].r, 1);
			j++;
		}
		if(tree->count==0){
			ans=min(ans, v[j-1].w-v[i].w);
		}
		else break;
		tree->make(v[i].l, v[i].r, -1);
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	// cin>>t;
	t=1;
	while(t--) solve();
}