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

struct UF{
	int siz;
	int par[200010],r[200010];
	void init(int n){
		siz = n;
		rep1(i,n){
			par[i] = i;
			r[i] = 0;
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
		siz --;
		if(r[x] < r[y]){
			par[x] = y;
		}
		else {
			par[y] = x;
			if(r[x] == r[y]){
				r[x] ++;
			}
		}
	}
}uf,u;

int main(){
	int n;
	static int a[200010];
	scanf("%d",&n);
	rep1(i,n)scanf("%d",&a[i]);
	
	int root = -1;
	int cnt = 1;
	uf.init(n);
	rep1(i,n){
		uf.unit(i,a[i]);
		if(i == a[i]){
			cnt = 0;
			root = i;
		}
	}
	int ans = cnt + uf.siz-1;
	
	static vector<int> V[200010];
	rep1(i,n)V[uf.find(i)].pb(i);
	vector<int> x;
	rep1(i,n)if(i == uf.find(i))x.pb(i);
	
	if(root == -1){
		u.init(n);
		rep(i,V[uf.find(x[0])].size()){
			int v = V[uf.find(x[0])][i];
			if(u.same(v,a[v])){
				a[v] = v;
				root = v;
				break;
			}
			else u.unit(v,a[v]);
		}
	}
	u.init(n);
	rep(i,x.size()){
		if(uf.same(x[i],root))continue;
		int y = uf.find(x[i]);
		rep(i,V[y].size()){
			int v = V[y][i];
			if(u.same(v,a[v])){
				a[v] = root;
				break;
			}
			else u.unit(v,a[v]);
		}
	}
	
	cout << ans << endl;
	rep1(i,n)printf("%d%c",a[i],(i==n)?'\n':' ');
}