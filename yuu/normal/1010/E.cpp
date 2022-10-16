#include <bits/stdc++.h>
using namespace std;
int xmax, ymax, zmax;
int fx, lx, fy, ly, fz, lz;
int n, m, k;
bool middle(int u, int v, int t){
	return ((u<=v)&&(v<=t));
}
class segment_tree{
public:
	using pointer=segment_tree*;
	int l, r, m;
	int zlow, zhigh;
	pointer left, right;
	segment_tree(int l, int r){
		this->l=l;
		this->r=r;
		m=(l+r)/2;
		zlow=1;
		zhigh=zmax;
		if(l!=r){
			left=new segment_tree(l, m);
			right=new segment_tree(m+1, r);
		}
	}
	void update_low(int u, int v, int z){
		if(l>v||r<u) return;
		if(u<=l&&v>=r){
			zlow=max(zlow, z);
		}
		else{
			left->update_low(u, v, z);
			right->update_low(u, v, z);
		}
	}
	void update_high(int u, int v, int z){
		if(l>v||r<u) return;
		if(u<=l&&v>=r){
			zhigh=min(zhigh, z);
		}
		else{
			left->update_high(u, v, z);
			right->update_high(u, v, z);
		}
	}
	bool check(int u, int z){
		if(z>zhigh||z<zlow) return 0;
		if(l==r) return 1;
		if(m>=u) return left->check(u, z);
		else return right->check(u, z);
	}
};
segment_tree::pointer tree;
class momment{
public:
	int x, y, z;
	void input(){
		cin>>x>>y>>z;
	}
	bool is_always_open(){
		return middle(fx, x, lx)&&middle(fy, y, ly)&&middle(fz, z, lz);
	}
	bool update(){
		if(middle(fy, y, ly)){
			if(middle(fz, z, lz))	return 0;
			if(z>lz) tree->update_high(1, ymax, z-1);
			else tree->update_low(1, ymax, z+1);
		}
		else{
			int l, r;
			if(y<fy){
				l=1, r=y;
			}
			else{
				l=y;
				r=ymax;
			}
			if(middle(fz, z, lz))	tree->update_high(l, r, 0);
			else{
				if(z>lz) tree->update_high(l, r, z-1);
				else tree->update_low(l, r, z+1);
			}
		}
		return 1;
	}
};
vector <momment> f[500001];
vector <momment> g[500001];
vector <momment> open;
vector <momment> closed;
vector <pair <momment, int>> query;
int ans[100000];
string verdict[]={"CLOSED", "UNKNOWN", "OPEN"};
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>xmax>>ymax>>zmax;
	cin>>n>>m>>k;
	open.resize(n);
	for(auto &x: open) x.input();
	closed.resize(m);
	for(auto &x: closed) x.input(); 
	query.resize(k);
	int cnt=0;
	for(auto &x: query){
		x.first.input(); 
		x.second=cnt;
		cnt++;
	}
	fx=xmax+1;
	fy=ymax+1;
	fz=zmax+1;
	for(auto &a: open){
		fx=min(fx, a.x);
		lx=max(lx, a.x);
		fy=min(fy, a.y);
		ly=max(ly, a.y);
		fz=min(fz, a.z);
		lz=max(lz, a.z);
	}
	for(auto &x: closed) if(x.is_always_open()){
		cout<<"INCORRECT\n";
		return 0;
	}
	cout<<"CORRECT\n";
	for(auto &x: closed) f[x.x].push_back(x);
	{
		tree=new segment_tree(1, ymax);
		for(int x=fx; x<=lx; x++)	for(auto a: f[x])	if(!a.update()) goto line0;//this can't happend
		line0:;
	}
	for(auto &x: query){
		if(x.first.is_always_open()) ans[x.second]=2;
		else if(middle(fx, x.first.x, lx)){
			ans[x.second]=tree->check(x.first.y, x.first.z);
		}
		else{
			g[x.first.x].push_back(x.first);
			g[x.first.x].back().x=x.second;
		}
	}
	{
		tree=new segment_tree(1, ymax);
		for(int x=fx; x<=xmax; x++){
			for(auto a: f[x])	if(!a.update()) goto line1;
			for(auto a: g[x])	ans[a.x]=tree->check(a.y, a.z);
		}
		line1:;
	}
	{
		tree=new segment_tree(1, ymax);
		for(int x=lx; x>=1; x--){
			for(auto a: f[x])	if(!a.update()) goto line2;
			for(auto a: g[x])	ans[a.x]=tree->check(a.y, a.z);
		}
		line2:;
	}
	for(int i=0; i<k; i++) cout<<verdict[ans[i]]<<'\n';
}