#include <bits/stdc++.h>
using namespace std;
set <int> p[100001];
int a[100001];
int b[100001];
int n, m;
class fenwick_tree{
public:
	vector <int> p;
	vector <long long> ft;
	fenwick_tree(){
		p.push_back(0);//1 indexed
	}
	void signup(int x){
		p.push_back(x);
	}
	void prepare(){
		sort(p.begin(), p.end());
		p.erase(unique(p.begin(), p.end()), p.end());
		ft.resize(p.size());
		for(auto &x: ft) x=0;
	}
	void update(int u, long long x){
		for(u=lower_bound(p.begin(), p.end(), u)-p.begin(); u<p.size(); u+=u&-u) ft[u]+=x;
	}
	long long get(int u){
		long long res=0;
		for(u=upper_bound(p.begin(), p.end(), u)-p.begin()-1; u>0; u-=u&-u) res+=ft[u];
		return res;
	}
} ft[100001];
void signup(int u, int t){
	for(; u<=n; u+=u&-u) ft[u].signup(t);
}
void signup(int u, int v, int t){
	signup(u, t);
	signup(v+1, t);
}
void update(int u, int t, long long x){
	for(; u<=n; u+=u&-u) ft[u].update(t, x);
}
void update(int u, int v, int t, long long x){
	update(u, t, x);
	update(v+1, t, -x);
}
long long get(int u, int t){
	long long res=0;
	for(; u>0; u-=u&-u) res+=ft[u].get(t);
	return res;
}
void signup_segment(int u, int v){
	signup(1, u, v);
}
void initial_signup(){
	for(int i=1; i<=n; i++){
		int x=0;
		for(int y: p[i]){
			if(x)	signup_segment(x, y);
			x=y;
		}
	}
}
void prepare(){
	for(int i=1; i<=n; i++) ft[i].prepare();
	for(int i=1; i<=n; i++){
		int x=0;
		for(int y: p[i]){
			if(x)	update(1, x, y, y-x);
			x=y;
		}
	}
}
class query{
public:
	int t, x, y;
	void input(){
		cin>>t>>x>>y;
	}
	void signup(){
		if(t==2) return;
		{
			auto u=p[b[x]].find(x);
			auto r=u;
			r++;
			if(r!=p[b[x]].end()) signup_segment(x, *r);
			auto l=u;
			if(u!=p[b[x]].begin()){
				l--;
				if(l!=p[b[x]].end()) signup_segment(*l, x);
			}
			if((u!=p[b[x]].begin())&&(r!=p[b[x]].end())) signup_segment((*l), (*r));
		}
		p[b[x]].erase(x);
		b[x]=y;
		p[b[x]].insert(x);
		{
			auto u=p[b[x]].find(x);
			auto r=u;
			r++;
			if(r!=p[b[x]].end()) signup_segment(x, *r);
			auto l=u;
			if(u!=p[b[x]].begin()){
				l--;
				if(l!=p[b[x]].end()) signup_segment(*l, x);
			}
			if((u!=p[b[x]].begin())&&(r!=p[b[x]].end())) signup_segment((*l), (*r));
		}
	}
	void apply(){
		if(t==2) cout<<get(x, y)<<'\n';
		else{
			{
				auto u=p[b[x]].find(x);
				auto r=u;
				r++;
				if(r!=p[b[x]].end()) update(1, x, *r, x-(*r));
				auto l=u;
				if(u!=p[b[x]].begin()){
					l--;
					if(l!=p[b[x]].end()) update(1, *l, x, (*l)-x);
				}
				if((u!=p[b[x]].begin())&&(r!=p[b[x]].end())) update(1, (*l), (*r), (*r)-(*l));
			}
			p[b[x]].erase(x);
			b[x]=y;
			p[b[x]].insert(x);
			{
				auto u=p[b[x]].find(x);
				auto r=u;
				r++;
				if(r!=p[b[x]].end()) update(1, x, *r, (*r)-x);
				auto l=u;
				if(u!=p[b[x]].begin()){
					l--;
					if(l!=p[b[x]].end()) update(1, (*l), x, x-(*l));
				}
				if((u!=p[b[x]].begin())&&(r!=p[b[x]].end())) update(1, (*l), (*r), (*l)-(*r));
			}
		}
	}
} q[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) b[i]=a[i];
	for(int i=1; i<=n; i++) p[b[i]].insert(i);
	for(int i=1; i<=m; i++) q[i].input();
	initial_signup();
	for(int i=1; i<=m; i++) q[i].signup();
	for(int i=1; i<=n; i++) b[i]=a[i];
	for(int i=1; i<=n; i++) p[i].clear();
	for(int i=1; i<=n; i++) p[b[i]].insert(i);
	prepare();
	for(int i=1; i<=m; i++)	q[i].apply();
}