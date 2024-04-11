#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll base=1000000007;
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	ll a;
	pointer left, right;
	segment_tree(int l, int r){
		this->l=l;
		this->r=r;
		m=(l+r)/2;
		a=0;
		if(l!=r){
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
		}
	}
	void update(int u, int v, ll x){
		if(l>v||r<u) return;
		if(u<=l&&v>=r){
			a+=x;
			while(a>=base) a-=base;
			return;
		}
		else{
			left->update(u, v, x);
			right->update(u, v, x);
		}
	}
	ll get(int u){
		if(l==r) return a;
		else{
			ll res=a;
			if(m>=u) res+=left->get(u);
			else res+=right->get(u);
			while(res>=base) res-=base;
			return res;
		}
	}
};
segment_tree::pointer a, b;
int n, q;
vector <int> g[300001];
int first[300001];
int last[300001];
int h[300001];
int cnt=0;
void dfs(int u){
	cnt++;
	first[u]=cnt;
	for(int v: g[u]){
		h[v]=h[u]+1;
		dfs(v);
	}
	last[u]=cnt;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=2, p; i<=n; i++){
		cin>>p;
		g[p].push_back(i);
	}
	dfs(1);
	a=new segment_tree(1, n);
	b=new segment_tree(1, n);
	cin>>q;
	for(int i=1, t, v, x, k; i<=q; i++){
		cin>>t>>v;
		if(t==2){
			cout<<(a->get(first[v])*h[v]+b->get(first[v]))%base<<'\n';
		}
		else{
			cin>>x>>k;
			a->update(first[v], last[v], base-k);
			b->update(first[v], last[v], (((ll)h[v])*k+x)%base);
		}
	}
}