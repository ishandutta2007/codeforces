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
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define mp1(a,b,c) P1(a,P(b,c))
#define pque(a) priority_queue<a>
#define rpque(a) priority_queue<a,vector<a>,greater<a>>

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

int gcd(int x,int y){
	if(y == 0)return x;
	return gcd(y,x%y);
}

int main(){
	int n;
	int l[302],c[302];
	
	scanf("%d",&n);
	rep(i,n)scanf("%d",&l[i]);
	rep(i,n)scanf("%d",&c[i]);
	
	rpque(P) que;
	rep(i,n)que.push( P ( c[i] , l[i] ) );
	
	set<int> S;
	
	int ret = -1;
	while(!que.empty()){
		P p = que.top(); que.pop();
		if(p.sc == 1){
			ret = p.fr;
			break;
		}
		if(S.find(p.sc) != S.end())continue;
		S.insert(p.sc);
		rep(i,n){
			int g = gcd(p.sc,l[i]);
			if(g < p.sc){
				que.push( P ( p.fr + c[i] , g ) );
			}
		}
	}
	
	printf("%d\n",ret);
}