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

int par[200010],r[200010],lar[200010];
void init(){
	rep(i,200010){
		par[i] = i;
		r[i] = 0;
		lar[i] = 1;
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
		lar[y] += lar[x];
	}
	else{
		par[y] = x;
		lar[x] += lar[y];
		if(r[x] == r[y]){
			r[x] ++;
		}
	}
}

int main(){
	static int n;
	static int a[200010];
	scanf("%d",&n);
	rep1(i,n){
		scanf("%d",&a[i]);
	}
	
	init();
	bool used[200010];
	rep(i,200010){
		used[i] = false;
	}
	
	vector<P> vec;
	rep1(i,n){
		vec.pb( P ( a[i] , i ) );
	}
	sor(vec);
	rev(vec);
	
	int ans[200010];
	int k = 1;
	rep(i,vec.size()){
		P p = vec[i];
		used[p.sc] = true;
		if(used[p.sc-1]){
			unit(p.sc,p.sc-1);
		}
		if(used[p.sc+1]){
			unit(p.sc,p.sc+1);
		}
		for(;k <= lar[find(p.sc)];k ++){
			ans[k] = p.fr;
		}
	}
	
	rep1(i,n){
		printf("%d ",ans[i]);
	}
	puts("");
}