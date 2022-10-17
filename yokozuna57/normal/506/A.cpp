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

int main(){
	int n,d;
	int t[30010] = {};
	int s[30010] = {};
	
	scanf("%d%d",&n,&d);
	rep(i,n){
		int a;
		scanf("%d",&a);
		t[a] ++;
	}
	rrep(i,30005){
		s[i] = t[i]+s[i+1];
	}
	
	int ret = 0;
	int loc = 0;
	for(int i = d; i >= 2; i--){
		loc += i;
		if(loc > 30000)break;
		ret += t[loc];
	}
	if(loc+1 <= 30000)ret += s[loc+1];
	if(n <= ret){
		printf("%d\n",ret);
		return 0;
	}
	
	rpque(P1) que;
	que.push ( mp1 ( d , d , 0 ) );
	int a = -1,b = -1;
	while(!que.empty()){
		P1 p = que.top(); que.pop();
		//printf("%d %d %d\n",p.fr,p.sc.fr,p.sc.sc);
		if(p.fr > 30000)break;
		if(p.fr == a && p.sc.fr == b)continue;
		a = p.fr;
		b = p.sc.fr;
		if(p.sc.fr <= 2){
			ret = max ( ret , -p.sc.sc+s[p.fr] );
			continue;
		}
		if(-p.sc.sc+s[p.fr] <= ret)continue;
		
		ret = max ( ret , -p.sc.sc + t[p.fr] );
		if(p.sc.fr > 1)que.push( mp1 ( p.fr+p.sc.fr-1 , p.sc.fr-1 , p.sc.sc-t[p.fr] ) );
		que.push( mp1 ( p.fr+p.sc.fr , p.sc.fr , p.sc.sc-t[p.fr] ) );
		que.push( mp1 ( p.fr+p.sc.fr+1 , p.sc.fr+1 , p.sc.sc-t[p.fr] ) );
	}
	
	printf("%d\n",ret);
}