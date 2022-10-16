#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	ll sz, value, sum;
	pointer left, right;
	segment_tree(int l, int r, int u){
		this->l=l;
		this->r=r;
		m=(l+r)/2;
		value=0;
		sz=1;
		sum=u;
		left=right=nullptr;
		if(l==r) return;
		if(m>=u) left=new segment_tree(l, m, u);
		else right=new segment_tree(m+1, r, u);
	}
	void up(){
		if(left==nullptr){
			if(right==nullptr){/*shouldn't happend*/}
			else{
				sz=right->sz;
				value=right->value;
				sum=right->sum;
			}
		}
		else{
			if(right==nullptr){
				sz=left->sz;
				value=left->value;
				sum=left->sum;
			}
			else{
				value=left->value+right->value+left->sum*right->sz;
				sz=left->sz+right->sz;
				sum=left->sum+right->sum;
			}
		}
	}
	friend pointer merge(pointer u, pointer v){
		if(u==nullptr) return v;
		if(v==nullptr) return u;
		u->left=merge(u->left, v->left);
		u->right=merge(u->right, v->right);
		u->up();
		return u;
	}
};
segment_tree::pointer tree[200002];
int r[200002];
int first[200002];
ll ans=0;
int root(int u){
	if(r[u]<0) return u;
	return r[u]=root(r[u]);
}
ll cost(int u){
	u=root(u);
	if(tree[u]==nullptr) return 0;
	return tree[u]->value+tree[u]->sum*first[u];
}
void unite(int u, int v){
	if(u<1||u>200000) return;
	if(v<1||v>200000) return;
	u=root(u);
	v=root(v);
	if(u==v) return;
	if(r[u]>r[v]) swap(u, v);
	ans-=cost(u);
	ans-=cost(v);
	r[u]+=r[v];
	r[v]=u;
	first[u]=min(first[u], first[v]);
	tree[u]=merge(tree[u], tree[v]);
	ans+=cost(u);
	unite(root(u), first[root(u)]+tree[root(u)]->sz);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=0; i<=200001; i++) r[i]=-1;
	for(int i=0; i<=200001; i++) first[i]=i;
	for(int i=1, a, b; i<=n; i++){
		cin>>a>>b;
		auto temp=new segment_tree(1, n, b);
		ans-=((ll)(a))*b;
		a=root(a);
		ans-=cost(a);
		tree[a]=merge(tree[a], temp);
		ans+=cost(a);
		unite(root(a), first[root(a)]+tree[root(a)]->sz);
		cout<<ans<<'\n';
	}
	// for(int i=1; i<=n; i++) cerr<<root(i)<<" \n"[i==n];
}