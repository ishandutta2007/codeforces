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

vector<int> G[200010];
set<int> depths;
void init(){
	depths.clear();
}
vector<int> vs;
int D = 0;
int A = -1,B = -1,C = -1;
void dfs(int v,int p,int d){
	vs.pb(v);
	rep(i,G[v].size()){
		if(G[v][i] == p)continue;
		dfs(G[v][i],v,d+1);
	}
	if(G[v].size() == 1)depths.insert(d);
	if(d > D){
		D = d;
		C = v;
		A = vs[d/2];
		B = vs[d/2+1];
	}
	vs.pop_back();
}

int f(int x){
	while(x%2 == 0)x /= 2;
	return x;
}

int main(){
	static int n;
	static int a[200010],b[200010];
	scanf("%d",&n);
	rep(i,n-1){
		scanf("%d%d",&a[i],&b[i]);
	}
	rep(i,n-1){
		G[a[i]].pb(b[i]);
		G[b[i]].pb(a[i]);
	}
	
	if(n == 2 || n == 3){
		puts("1");
		return 0;
	}
	
	dfs(1,-1,0);
	dfs(C,-1,0);
	int ans = 0;
	if(D%2 == 0){
		set<int> E;
		int X = A;
		init();
		rep(i,G[X].size()){
			init();
			dfs(G[X][i],X,1);
			if(depths.size() >= 2){
				puts("-1");
				return 0;
			}
			E.insert(*depths.begin());
		}
		//dfs(X,-1,0);
		if(E.size() >= 3){
			puts("-1");
			return 0;
		}
		ans = *E.begin();
		ans += *--E.end();
	}
	else {
		ans = 1;
		int X = A,Y = B;
		init();
		dfs(X,Y,0);
		if(depths.size() >= 2){
			puts("-1");
			return 0;
		}
		ans += *depths.begin();
		init();
		dfs(Y,X,0);
		if(depths.size() >= 2){
			puts("-1");
			return 0;
		}
		ans += *depths.begin();
	}
	printf("%d\n",f(ans));
	
	/*int ans = -1;
	rep1(i,n){
		if(G[i].size() <= 2)continue;
		init();
		dfs(i,-1,0);
		if(depths.size() == 1)continue;
		else {
			if(depths.size() >= 3 || (ans != -1 && ans != (*depths.begin())+(*--depths.end()))){
				puts("-1");
				return 0;
			}
			ans = (*depths.begin())+(*--depths.end());
		}
	}
	if(ans == -1){
		rep1(i,n){
			if(G[i].size() >= 2){
				init();
				dfs(i,-1,0);
				if(depths.size() == 1){
					printf("%d\n",f(*depths.begin()));
					return 0;
				}
				else {
					printf("%d\n",f((*depths.begin())+(*--depths.end())));
					return 0;
				}
			}
		}
	}
	printf("%d\n",f(ans));*/
}