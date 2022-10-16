#include <bits/stdc++.h>
using namespace std;
int n;
int p, q, r;
vector <pair <int, int>> f[500002];
pair <int, int> low[500002];
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	int low, high;
	long long sum;
	pointer left, right;
	segment_tree(int l, int r){
		this->l=l;
		this->r=r;
		m=(l+r)/2;
		low=high=sum=0;
		if(l!=r){
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
		}
	}
	void assign(int x){
		low=x;
		high=x;
		sum=x;
		sum*=(r-l+1);
	}
	void down(){
		if(low==high){
			left->assign(low);
			right->assign(high);
		}
	}
	void up(){
		low=min(left->low, right->low);
		high=max(left->high, right->high);
		sum=left->sum+right->sum;
	}
	void update(int u, int v, int x){
		if(l>v||r<u) return;
		if(low>=x) return;
		if(u<=l&&v>=r){
			if(high<=x){
				assign(x);
				return;
			}
		}
		down();
		left->update(u, v, x);
		right->update(u, v, x);
		up();
	}
	long long get(int u, int v, int x){
		if(l>v||r<u) return 0;
		if(u<=l&&v>=r){
			if(high<=x)	return ((long long)x)*(r-l+1);
			else if(low>=x)	return sum;
		}
		down();
		return left->get(u, v, x)+right->get(u, v, x);
	}
};
segment_tree::pointer tree;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>p>>q>>r;
	tree=new segment_tree(1, q);
	for(int i=1, a, b, c; i<=n; i++){
		cin>>a>>b>>c;
		f[a].push_back({b, c});
	}
	for(int i=p; i>=1; i--){
		low[i]=low[i+1];
		for(auto x: f[i]){
			low[i].first=max(low[i].first, x.first);
			low[i].second=max(low[i].second, x.second);
		}
	}
	long long ans=0;
	for(int i=1; i<=p; i++){
		ans-=tree->get(low[i].first+1, q, low[i].second);
		ans+=((long long)q-low[i].first)*r;
		for(auto &x: f[i]) tree->update(1, x.first, x.second);
	}
	cout<<ans<<'\n';
}


/*
let (x, y, z) be the card that can win all card in the collection

for all card (a, b, c) with a>=x then y>b and z>c
so y>maxb and z>maxc for something
for all card with a<=x then x>b or y>c
let store f[i] as answer for when y=i
the array is alway sorted decreasingly -> binary search for the first change 
*/