#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> g[500001];
bool done[500001];
int child[500001];
void dfs(int u){
	done[u]=1;
	for(int &v: g[u]) if(done[v]){
		swap(v, g[u].back());
		g[u].pop_back();
		break;
	}
	child[u]=1;
	for(int v: g[u]){
		dfs(v);
		child[u]+=child[v];
	}
}
using ll=long long;
ll f[500001];
class line{
public:
	ll a, b;
	line(ll a=0, ll b=1e18): a(a), b(b){}
	ll at(ll x){
		return a*x+b;
	}
	ll get(ll x){
		return a*x+b;
	}
};
int cmp(ll a, ll b){
	return (a<b)?(-1):(a>b);
}
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	line L;
	pointer left, right;
	segment_tree(int l, int r){
		this->l=l;
		this->r=r;
		m=(l+r)/2;
		left=right=nullptr;
	}
	~segment_tree(){
		if(left!=nullptr){
			delete left;
			delete right;
		}
	}
	void update(line A){
		int bl=cmp(A.at(l), L.at(r));
		int br=cmp(A.at(r), L.at(r));
		if((bl!=-1)&&(br!=-1)) return;
		if((bl!=1)&&(br!=1)){
			L=A;
			return;
		}
		if(left==nullptr){
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
		}
		left->update(A);
		right->update(A);
	}
	ll get(int pos){
		ll res=L.get(pos);
		if(left!=nullptr){
			if(m>=pos) res=min(res, left->get(pos));
			else res=min(res, right->get(pos));
		}
		return res;
	}
};
segment_tree::pointer tree;
ll ans=1e18;
ll sqr(ll x){
	return x*x;
}
void cal(int u){
	if(g[u].empty()) f[u]=0;
	else{
		f[u]=1e18;
		for(int v: g[u]){
			cal(v);
			ll cnt=child[u]-child[v];
			f[u]=min(f[u], f[v]+cnt*(cnt-1)/2);
		}
		//choose a and b that minimize f[a]+f[b]+((n-child[a]-child[b]-1) choose 2)
		//f[b]+(c-child[b]) choose 2
		//(2*f[b]+c^2+child[b]^2-2*c*child[b]-c+child[b])/2
		tree=new segment_tree(0, n);
		for(int a: g[u]){
			ll c=n-child[a];
			ans=min(ans, f[a]+(tree->get(c)+c*c-c)/2);
			tree->update(line(-child[a]*2, f[a]*2+sqr(child[a])+child[a]));
		}
		delete tree;
		reverse(g[u].begin(), g[u].end());
		tree=new segment_tree(0, n);
		for(int a: g[u]){
			ll c=n-child[a];
			ans=min(ans, f[a]+(tree->get(c)+c*c-c)/2);
			tree->update(line(-child[a]*2, f[a]*2+sqr(child[a])+child[a]));
		}
		delete tree;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	if(n==2){
		cout<<2<<'\n';
		return 0;
	}
	for(int i=1, u, v; i<n; i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int rt=1;
	for(int i=1; i<=n; i++) if(g[i].size()>1){
		rt=i;
		break;
	}
	dfs(rt);
	cal(rt);
	ans=(sqr(n)-n)-ans;
	cout<<ans<<'\n';
}