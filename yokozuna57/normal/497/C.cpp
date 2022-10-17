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
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define mp1(a,b,c) P1(a,P(b,c))
#define mp2(a,b,c,d) P2(P(a,b),P(c,d))
#define pque(a) priority_queue<a>
#define rpque(a) priority_queue<a,vector<a>,greater<a>>

const int INF=1000000000;
const int dre_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dre_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

int main(){
	int n,m;
	vector<pair<P2,int>> vec;
	
	scanf("%d",&n);
	rep(i,n){
		int a,b;
		scanf("%d%d",&a,&b);
		vec.pb(pair<P2,int>(mp2(a,1,b,i),0));
	}
	scanf("%d",&m);
	rep(i,m){
		int c,d,k;
		scanf("%d%d%d",&c,&d,&k);
		vec.pb(pair<P2,int>(mp2(c,0,d,k),i+1));
	}
	
	sor(vec);
	
	static map<int,pair<int,vector<P>>> MAP;
	
	static int ret[100010];
	
	rep(i,vec.size()){
		P2 p=vec[i].fr;
		if(p.fr.sc == 0){
			if(MAP.find(p.sc.fr) != MAP.end())MAP[p.sc.fr].sc.pb(P(vec[i].sc,p.sc.sc));
			else {
				MAP[p.sc.fr].fr = 0;
				MAP[p.sc.fr].sc.pb(P(vec[i].sc,p.sc.sc));
			}
		}
		else {
			map<int,pair<int,vector<P>>>::iterator itr = MAP.lower_bound(p.sc.fr);
			if(itr == MAP.end()){
				puts("NO");
				return 0;
			}
			else {
				(*itr).sc.sc[(*itr).sc.fr].sc--;
				ret[p.sc.sc] = (*itr).sc.sc[(*itr).sc.fr].fr;
				if((*itr).sc.sc[(*itr).sc.fr].sc == 0){
					(*itr).sc.fr++;
					if((*itr).sc.fr == (*itr).sc.sc.size())MAP.erase(itr);
				}
			}
		}
	}
	
	puts("YES");
	rep(i,n){
		printf("%d%c",ret[i],(i == n-1)?'\n':' ');
	}
}