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
typedef pair<P,P> P2;

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
#define mp2(a,b,c,d) P2(P(a,b),P(c,d))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

struct seg{
	int s;
	P t;
	int l;
	int r;
	bool ch;
	seg* chl;
	seg* chr;
};

seg* init(){
	seg* ret = new seg;
	ret->l = 0;
	ret->r = 1<<30;
	ret->s = 0;
	ret->t = P(0,(1<<30)-1);
	ret->ch = false;
	return ret;
}

void mkch(seg* T){
	T->chl = new seg;
	T->chl->l = T->l;
	T->chl->r = (T->l+T->r)/2;
	T->chl->s = 0;
	T->chl->t = P(0,T->chl->r-1);
	T->chl->ch = false;
	T->chr = new seg;
	T->chr->l = (T->l+T->r)/2;
	T->chr->r = T->r;
	T->chr->s = 0;
	T->chr->t = P(0,T->chr->r-1);
	T->chr->ch = false;
	T->ch = true;
}

void add(int a,int b,int x,seg* T){
	if(b <= T->l || T->r <= a)return;
	if(a <= T->l && T->r <= b){
		T->s += x;
		T->t.fr += x;
		return;
	}
	if(!T->ch)mkch(T);
	add(a,b,x,T->chl);
	add(a,b,x,T->chr);
	T->t = max ( T->chl->t , T->chr->t );
	T->t.fr += T->s;
}

P query(int a,int b,seg* T){
	if(b <= T->l || T->r <= a)return P(-1,-1);
	if(a <= T->l && T->r <= b)return T->t;
	if(!T->ch)return P(T->s,min(b,T->r)-1);
	P vl = query(a,b,T->chl);
	P vr = query(a,b,T->chr);
	P ret = max(vl,vr);
	ret.fr += T->s;
	return ret;
}

vector<int> G[100010];
int color[100010];
bool dfs(int v,int c){
	if(color[v] == -c)return false;
	if(color[v] == c)return true;
	color[v] = c;
	bool ret = true;
	rep(i,G[v].size()){
		ret &= dfs(G[v][i],-c);
	}
	return ret;
}

struct UF{
	int par[100010],r[100010],cnt[100010];
	void init(){
		rep(i,100010){
			par[i] = i;
			r[i] = 0;
			cnt[i] = 1;
		}
	}
	int find(int x){
		if(par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
	void unit(int x,int y){
		if(same(x,y))return;
		x = find(x);
		y = find(y);
		if(r[x] < r[y]){
			par[x] = y;
			cnt[y] += cnt[x];
		}
		else {
			par[y] = x;
			cnt[x] += cnt[y];
			if(r[x] == r[y]){
				r[x] ++;
			}
		}
	}
}uf;

int main(){
	static int s,t;
	static int n,m;
	static int l[100010],r[100010],l_[100010],r_[100010];
	static int a[100010],b[100010];
	scanf("%d%d",&s,&t);
	scanf("%d%d",&n,&m);
	rep1(i,n){
		scanf("%d%d",&l[i],&r[i]);
	}
	rep(i,m){
		scanf("%d%d",&a[i],&b[i]);
		G[a[i]].pb(b[i]);
		G[b[i]].pb(a[i]);
	}
	
	bool nibu = true;
	rep1(i,n){
		if(color[i] == 0)nibu &= dfs(i,1);
	}
	if(!nibu){
		puts("IMPOSSIBLE");
		return 0;
	}
	
	uf.init();
	rep(i,m){
		uf.unit(a[i],b[i]);
	}
	
	vector<P2> Q;
	rep(i,100010){
		l_[i] = 0;
		r_[i] = 1000000000;
	}
	rep1(i,n){
		if(uf.find(i) != i){
			if(color[uf.find(i)]*color[i] == 1){
				l[uf.find(i)] = max(l[uf.find(i)],l[i]);
				r[uf.find(i)] = min(r[uf.find(i)],r[i]);
				if(l[uf.find(i)] > r[uf.find(i)]){
					puts("IMPOSSIBLE");
					return 0;
				}
			}
			else {
				l_[uf.find(i)] = max(l_[uf.find(i)],l[i]);
				r_[uf.find(i)] = min(r_[uf.find(i)],r[i]);
				if(l_[uf.find(i)] > r_[uf.find(i)]){
					puts("IMPOSSIBLE");
					return 0;
				}
			}
		}
	}
	rep1(i,n){
		if(uf.find(i) == i){
			Q.pb(mp2(l[i],uf.cnt[i],l_[i],r_[i]+1));
			Q.pb(mp2(r[i]+1,-uf.cnt[i],l_[i],r_[i]+1));
			Q.pb(mp2(l_[i],uf.cnt[i],l[i],r[i]+1));
			Q.pb(mp2(r_[i]+1,-uf.cnt[i],l[i],r[i]+1));
			int L = max(l[i],l_[i]);
			int R = min(r[i],r_[i]);
			if(L <= R){
				Q.pb(mp2(L,-uf.cnt[i],L,R+1));
				Q.pb(mp2(R+1,uf.cnt[i],L,R+1));
			}
		}
	}
	sor(Q);
	
	/*rep(i,Q.size()){
		printf("%d %d %d %d\n",Q[i].fr.fr,Q[i].fr.sc,Q[i].sc.fr,Q[i].sc.sc);
	}*/
	
	int n1=-1,n2=-1;
	seg* T = init();
	rep(i,Q.size()){
		P2 p = Q[i];
		if(i > 0 && p.fr.fr > Q[i-1].fr.fr){
			P q = query(max(0,s-(p.fr.fr-1)),min(1000000000,t-Q[i-1].fr.fr)+1,T);
			if(q.fr == n){
				n1 = q.sc;
				n2 = s-n1;
				if(n2 < Q[i-1].fr.fr || p.fr.fr <= n2 || n1+n2 < s || n1+n2 > t)n2 = t-n1;
				if(n2 < Q[i-1].fr.fr || p.fr.fr <= n2 || n1+n2 < s || n1+n2 > t)n2 = Q[i-1].fr.fr;
				if(n2 < Q[i-1].fr.fr || p.fr.fr <= n2 || n1+n2 < s || n1+n2 > t)n2 = p.fr.fr-1;
				break;
			}
		}
		add(p.sc.fr,p.sc.sc,p.fr.sc,T);
		/*if(i == Q.size()-1 || p.fr.fr < Q[i+1].fr.fr){
			printf("%d:",p.fr.fr);
			printf("%d ",query(100,101,T));
			printf("%d ",query(3,4,T));
			printf("%d ",query(4,5,T));
			printf("%d ",query(9,10,T));
			printf("%d ",query(10,11,T));
			printf("%d ",query(16,17,T));
			printf("%d ",query(26,27,T));
			cout << endl;
		}*/
	}
	
	if(n1 == -1 || n2 == -1){
		puts("IMPOSSIBLE");
		return 0;
	}
	puts("POSSIBLE");
	printf("%d %d\n",n1,n2);
	static int ans[100010];
	rep1(i,n){
		if(uf.find(i) != i)continue;
		if(n1 < l[i] || r[i] < n1)ans[i] = 2;
		else if(n2 < l_[i] || r_[i] < n2)ans[i] = 2;
		else ans[i] = 1;
	}
	rep1(i,n){
		if(color[i]*color[uf.find(i)] == 1){
			printf("%d",ans[uf.find(i)]);
			/*l[i] = l[uf.find(i)];
			r[i] = r[uf.find(i)];
			if(!(l[i] <= n1 && n1 <= r[i]))printf("2");
			else printf("1");*/
		}
		else if(color[i]*color[uf.find(i)] == -1){
			printf("%d",3-ans[uf.find(i)]);
			/*l[i] = l_[uf.find(i)];
			r[i] = r_[uf.find(i)];
			if(!(l[i] <= n2 && n2 <= r[i]))printf("1");
			else printf("2");*/
		}
	}
	cout << endl;
}