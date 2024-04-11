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
const int dre_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dre_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int kaijou[10]={1,1,2,6,24,120,720,5040,40320,362880};

int main(){
	int n,m;
	int a;
	vector<P> vec;
	
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a);
		vec.pb(P(a,1));
	}
	scanf("%d",&m);
	rep(i,m){
		scanf("%d",&a);
		vec.pb(P(a,-1));
	}
	
	sor(vec);
	rev(vec);
	
	int max = 0,ret_a = 0,ret_b = 0,now = 0,cnt_a = 0,cnt_b = 0;
	rep(i,vec.size()){
		now += vec[i].sc;
		if(vec[i].sc > 0)cnt_a++;
		else cnt_b++;
		if(i == vec.size() -1 || vec[i].fr != vec[i+1].fr)if(max <= now){
			max = now;
			ret_a = cnt_a;
			ret_b = cnt_b;
		}
	}
	
	printf("%d:%d\n",2 * n + ret_a,2 * m + ret_b);
}