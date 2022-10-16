#include <bits/stdc++.h>
using namespace std;
int n;
string s;
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	int mask;
	pointer left, right;
	segment_tree(int l, int r){
		this->l=l;
		this->r=r;
		m=(l+r)/2;
		if(l==r) mask=1<<s[l];
		else{
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
			mask=left->mask|right->mask;
		}
	}
	void update(int u){
		if(l==r){
			mask=1<<s[l];
		}
		else{
			if(m>=u) left->update(u);
			else right->update(u);
			mask=left->mask|right->mask;
		}
	}
	int get(int u, int v){
		if(l>v||r<u) return 0;
		if(u<=l&&v>=r) return mask;
		else{
			return left->get(u, v)|right->get(u, v);
		}
	}
};
segment_tree::pointer tree;
int main(){
	cin>>s;
	for(auto &x: s) x-='a';
	s='0'+s;
	tree=new segment_tree(1, s.size()-1);
	int q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t==2){
			int l, r;
			cin>>l>>r;
			cout<<__builtin_popcount(tree->get(l, r))<<'\n';
		}
		else{
			int p;
			cin>>p;
			cin>>s[p];
			s[p]-='a';
			tree->update(p);
		}
	}
}