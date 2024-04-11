#include <bits/stdc++.h>
using namespace std;
int n;
int a[500001];
vector <int> p[500001];
vector <pair <pair <int, int>, int>> add[500002];
void addRect(int l, int r, int u, int v){
	if(u>v) return;
	// cerr<<l<<' '<<r<<' '<<u<<' '<<v<<'\n';
	add[l].push_back({{u, v}, 1});
	add[r+1].push_back({{u, v}, -1});
}
class segmentTree{
public:
	using pointer=segmentTree*;
	int l, r, m;
	int sum, value;
	pointer left, right;
	segmentTree(int l, int r): l(l), r(r), m((l+r)/2), sum(0), value(0){
		if(l!=r){
			left=new segmentTree(l, m);
			right=new segmentTree(m+1, r);
		}
	}
	void update(int u, int v, int x){
		if(l>v||r<u) return;
		if(u<=l&&v>=r){
			value+=x;
			if(value==0){
				if(l!=r) sum=left->sum+right->sum;
				else sum=0;
			}
			else sum=r-l+1;
		}
		else{
			left->update(u, v, x);
			right->update(u, v, x);
			if(value==0) sum=left->sum+right->sum;
			else sum=r-l+1;
		}
	}
};
segmentTree::pointer tree;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) p[a[i]].push_back(i);
	for(int i=1; i<=n; i++) if(!p[i].empty()){
		int prev=0;
		for(int j=0; j<p[i].size(); j++){
			int pj2=(j+2<p[i].size())?p[i][j+2]:(n+1);
			int pj3=(j+3<p[i].size())?p[i][j+3]:(n+1);
			addRect(prev+1, p[i][j], p[i][j], pj2-1);
			addRect(prev+1, p[i][j], pj3, n);
			prev=p[i][j];
		}
	}
	for(int i=1; i<=n; i++) addRect(i, n, 1, i);
	// cerr<<"OK\n";
	tree=new segmentTree(1, n);
	// cerr<<"OK\n";
	long long ans=n;
	ans*=n;
	for(int i=1; i<=n; i++){
		for(auto p: add[i]) tree->update(p.first.first, p.first.second, p.second);
		// cerr<<tree->sum<<'\n';
		ans-=tree->sum;
	}
	cout<<ans<<'\n';
}