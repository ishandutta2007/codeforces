#include <bits/stdc++.h>
using namespace std;
string s[100001];
int n, w, q;
bool done[11];
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	pair <int, int> f[11];
	pointer left, right;
	void find(int u){
		if(done[u]) return;
		done[u]=1;
		if(s[l][u]=='<'){
			if(u==1) f[u]={l, 0};
			else{
				find(u-1);
				f[u]=f[u-1];
			}
		}
		else if(s[l][u]=='>'){
			if(u==w) f[u]={l, w+1};
			else{
				find(u+1);
				f[u]=f[u+1];
			}
		}
		else f[u]={l-1, u};
	}
	void make(){
		for(int i=1; i<=w; i++) f[i]={-1, -1};
		for(int i=1; i<=w; i++) done[i]=0;
		for(int i=1; i<=w; i++) find(i);
	}
	void combine(){
		for(int i=1; i<=w; i++){
			f[i]=right->f[i];
			if(f[i].first==left->r) f[i]=left->f[f[i].second];
		}
	}
	segment_tree (int l, int r): l(l), r(r){
		m=(l+r)/2;
		if(l==r){
			make();
		}
		else{
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
			combine();
		}
	}
	void update(int u){
		if(l==r) make();
		else{
			if(m>=u) left->update(u);
			else right->update(u);
			combine();
		}
	}
	pair <int, int> get(int u, int v){
		if(l==r){
			return f[v];
		}
		else{
			if(m>=u) return left->get(u, v);
			else{
				auto res=right->get(u, v);
				if(res.first==m) res=left->f[res.second];
				return res;
			}
		}
	}
};
segment_tree::pointer tree;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>w>>q;
	for(int i=1; i<=n; i++){
		cin>>s[i];
		s[i]='0'+s[i];
	}
	tree=new segment_tree(1, n);
	for(int i=1; i<=q; i++){
		char c;
		int x, y;
		cin>>c>>x>>y;
		if(c=='C'){
			cin>>c;
			s[x][y]=c;
			tree->update(x);
		}
		else{
			auto res=tree->get(x, y);
			cout<<res.first<<' '<<res.second<<'\n';
		}
	}
}