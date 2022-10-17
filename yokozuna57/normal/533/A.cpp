#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

/*struct SEG{
	int siz;
	int s[1<<21],t[1<<21];
	void init(){
		siz = 1<<20;
		rep(i,siz*2-1){
			s[i] = 0 ;
			t[i] = 0 ;
		}
	}
	void updata(int a,int b,int x,int k,int l,int r){
		if(b <= l || r <= a)return;
		if(a <= l && r <= b){
			s[k] += x;
			t[k] += x;
			return;
		}
		updata(a,b,x,2*k+1,l,(l+r)/2);
		updata(a,b,x,2*k+2,(l+r)/2,r);
	}
	int query(int x,int k,int l,int r){
		if(s[k] >= x)return -1;*/
		

struct node{
	int s;
	int t;
	int l;
	int r;
	bool ch;
	node* chl;
	node* chr;
};

node* init(){
	node* ret = new node;
	ret->s = 0;
	ret->t = 0;
	ret->l = 0;
	ret->r = 1<<21;
	ret->ch = false;
	return ret;
}

void mkch(node* T){
	T->chl = new node;
	T->chl->s = 0;
	T->chl->t = 0;
	T->chl->l = T->l;
	T->chl->r = (T->l+T->r)/2;
	T->chl->ch = false;
	T->chr = new node;
	T->chr->s = 0;
	T->chr->t = 0;
	T->chr->l = (T->l+T->r)/2;
	T->chr->r = T->r;
	T->chr->ch = false;
	T->ch = true;
}

void updata(int a,int b,int x,node* T){
	if(b <= T->l || T->r <= a)return;
	if(a <= T->l && T->r <= b){
		T->s += x;
		T->t += x;
		return;
	}
	if(!T->ch)mkch(T);
	updata(a,b,x,T->chl);
	updata(a,b,x,T->chr);
	T->s = min ( T->chl->s , T->chr->s ) + T->t;
}

int query(int x,node* T){
	//cout << x << " " << T->l << " " << T->r << " " << T->s << endl;
	if(T->s >= x)return -1;
	if(!T->ch)return T->r-1;
	int vr = query(x-T->t,T->chr);
	if(vr != -1)return vr;
	return query(x-T->t,T->chl);
}

vector<int> G[500010];
int h[500010];
int c[500010],d[500010];
void dfs(int v,int p,int C,int D){
	if(D >= h[v]){
		D = h[v];
		if(h[C] >= D){
			D = h[C];
			C = v;
		}
	}
	c[v] = C;
	d[v] = D;
	rep(i,G[v].size()){
		if(G[v][i] == p)continue;
		dfs(G[v][i],v,C,D);
	}
}

int main(){
	static int n;
	static int k;
	static int s[500010];
	scanf("%d",&n);
	rep1(i,n)scanf("%d",&h[i]);
	rep(i,n-1){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].pb(b);
		G[b].pb(a);
	}
	scanf("%d",&k);
	rep(i,k)scanf("%d",&s[i]);
	
	vector<int> Z;
	rep1(i,n)Z.pb(h[i]);
	rep(i,k)Z.pb(s[i]);
	sor(Z); uniq(Z);
	rep1(i,n)h[i] = lb(Z,h[i]) - Z.begin();
	rep(i,k)s[i] = lb(Z,s[i]) - Z.begin();
	
	h[0] = INF+10;
	dfs(1,0,0,INF+10);
	
	static vector<int> vec[500010];
	rep1(i,n){
		vec[c[i]].pb(d[i]);
	}
	
	node* T = init();
	rep(i,k)updata(0,s[i]+1,-1,T);
	
	rep1(i,n){
		updata(0,h[i]+1,vec[i].size(),T);
	}
	if(T->s >= 0){
		puts("0");
		return 0;
	}
	
	int ret = INF+10;
	rep1(i,n){
		updata(0,h[i]+1,-vec[i].size(),T);
		int memo = query(0,T);
		rep(j,vec[i].size()){
			updata(0,vec[i][j]+1,1,T);
		}
		if(T->s >= 0)ret = min ( ret , Z[memo]-Z[h[i]] );
		rep(j,vec[i].size()){
			updata(0,vec[i][j]+1,-1,T);
		}
		updata(0,h[i]+1,vec[i].size(),T);
	}
	
	if(ret == INF+10)puts("-1");
	else cout << ret << endl;
}