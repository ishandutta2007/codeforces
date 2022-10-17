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

int main(){
	static int n;
	static int f[100010];
	scanf("%d",&n);
	rep1(i,n)scanf("%d",&f[i]);
	
	static int k = 1;
	static int g[100010],h[100010];
	
	rep1(i,n){
		if(f[f[i]] != f[i]){
			puts("-1");
			return 0;
		}
		if(f[i] == i){
			g[i] = k;
			h[k] = i;
			k ++;
		}
	}
	rep1(i,n){
		g[i] = g[f[i]];
	}
	
	printf("%d\n",k-1);
	rep1(i,n){
		printf("%d%c",g[i],(i==n)?'\n':' ');
	}
	rep1(i,k-1){
		printf("%d%c",h[i],(i==k-1)?'\n':' ');
	}
}