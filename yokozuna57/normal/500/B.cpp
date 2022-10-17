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

typedef long long LL;
typedef long double LD;
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
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define mp1(a,b,c) P1(a,P(b,c))
#define pque(a) priority_queue<a>
#define rpque(a) priority_queue<a,vector<a>,greater<a>>

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

int par[310],r[310];
void init(){ rep(i,310){ par[i]=i; r[i]=0; } }
int find(int x){ if(x==par[x])return x; return par[x]=find(par[x]); }
bool same(int x,int y){ return find(x)==find(y); }
void unit(int x,int y){ if(same(x,y))return; x=find(x); y=find(y); if(r[x]<r[y])par[x]=y; else { par[y]=x; if(r[x]==r[y])r[x]++; } }

int main(){
	int n;
	int p[310];
	int a[310][310];
	
	scanf("%d",&n);
	rep1(i,n)scanf("%d",&p[i]);
	rep1(i,n){
		scanf("\n");
		rep1(j,n){
			char c;
			scanf("%c",&c);
			a[i][j] = c-48;
		}
	}
	
	init();
	rep1(i,n){
		rep1(j,n){
			if(a[i][j] == 1){
				unit(i,j);
			}
		}
	}
	
	vector<int> vec[302];
	int k[302];
	
	rep1(i,n){
		vec[find(i)].pb(p[i]);
	}
	
	rep1(i,n){
		sor(vec[i]);
	}
	
	rep1(i,n){
		p[i] = vec[find(i)][k[find(i)]];
		k[find(i)] ++;
	}
	
	rep1(i,n){
		printf("%d%c",p[i],(i == n)?'\n':' ');
	}
}