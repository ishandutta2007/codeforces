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
	int n;
	static int a[100010];
	static int b[100010];
	a[0] = 0;
	b[0] = 0;
	
	scanf("%d",&n);
	rep1(i,n){
		a[i] = a[i-1];
		b[i] = b[i-1];
		int x;
		scanf("%d",&x);
		if(x == 1)a[i]++;
		else b[i]++;
	}
	a[n+1] = a[n];
	b[n+1] = b[n];
	
	
	vector<P> ans;
	rep1(t,n){
		//cout << t << ":" << endl;
		int s_1 = 0,s_2 = 0;
		int loc = 0;
		while(loc < n){
			//cout << loc << endl;
			int l_1 = lower_bound(a,a+n+1,a[loc]+t) - a;
			int l_2 = lower_bound(b,b+n+1,b[loc]+t) - b;
			if(l_1 == l_2)break;
			if(l_1 < l_2)s_1++;
			else s_2++;
			loc = min(l_1,l_2);
		}
		//cout << loc << endl;
		if(loc == n){
			if(s_1 < s_2 && b[n] - b[n-1] == 1)ans.pb(P(s_2,t));
			if(s_1 > s_2 && a[n] - a[n-1] == 1)ans.pb(P(s_1,t));
		}
	}
	
	sor(ans);
	
	printf("%d\n",ans.size());
	rep(i,ans.size()){
		printf("%d %d\n",ans[i].fr,ans[i].sc);
	}
}