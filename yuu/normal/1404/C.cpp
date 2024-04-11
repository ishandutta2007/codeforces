#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int n, q;
int a[300001];
int ans[300001];
class query{
public:
	int x, y, id;
	query(int x, int y, int id): x(x), y(y), id(id){}
};
vector <query> f;
int getValue(int u){
	if(a[u]<=u) return u-a[u];
	else return 1e9;
}
class segmentTree{
public:
	using pointer=segmentTree*;
	int l, r, m;
	pointer left, right;
	int lazy, value;
	segmentTree(int l, int r): l(l), r(r), m((l+r)/2), lazy(0){
		if(l!=r){
			left=new segmentTree(l, m);
			right=new segmentTree(m+1, r);
			value=min(left->value, right->value);
		}
		else{
			left=right=nullptr;
			value=getValue(l);
		}
	}
	void down(){
		left->lazy+=lazy;
		left->value+=lazy;
		right->lazy+=lazy;
		right->value+=lazy;
		lazy=0;
	}
	void up(){
		value=min(left->value, right->value);
	}
	void update(int u){
		if(r<=u) return;
		if(l>u){
			lazy--;
			value--;
		}
		else{
			down();
			left->update(u);
			right->update(u);
			up();
		}
	}
	void remove(int u){
		if(l==r){
			value=1e9;
		}
		else{
			down();
			if(m>=u) left->remove(u);
			else right->remove(u);
			up();			
		}
	}
	int get(){
		if(l==r) return l;
		down();
		if(right->value==0) return right->get();
		else return left->get();
	}
};
segmentTree::pointer tree;
int ft[300001];
int ftGet(int u){
	int ans=0;
	for(; u>0; u-=u&-u) ans+=ft[u];
	return ans;
}
int ftUpdate(int u){
	for(; u<=n; u+=u&-u) ft[u]++;
}
int get(){
	if(tree->value) return -1;
	return tree->get();
}
void solve(){
	cin>>n>>q;
	for(int i=1; i<=n; i++) cin>>a[i];
	tree=new segmentTree(1, n);
	for(int i=1, x, y; i<=q; i++){
		cin>>x>>y;
		x++;
		y=n-y;
		f.push_back(query(x, y, i));
	}
	sort(f.begin(), f.end(), [](query A, query B){
		return A.x<B.x;
	});
	for(int i=n; i>=1; i--){
		while(true){
			int pos=get();
			if(pos>=i){
				ftUpdate(pos);
				tree->update(pos);
				tree->remove(pos);
			}
			else break;
		}
		while((!f.empty())&&(f.back().x==i)){
			auto p=f.back();
			f.pop_back();
			ans[p.id]=ftGet(p.y);
		}
		if(f.empty()) break;
	}
	for(int i=1; i<=q; i++) cout<<ans[i]<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	// cin>>t;
	while(t--) solve();
}