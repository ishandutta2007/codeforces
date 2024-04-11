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

int siz,SEG[400010],PRE[400010];

void init(int n){
	siz=1;
	while(siz<n)siz*=2;	
	rep(i,siz*2-1){SEG[i]=0; PRE[i]=-1;}
}

void updata(int a,int b,int x,int y,int k,int l,int r){
	if(b<=l||r<=a)return;
	if(a<=l&&r<=b){
		if(SEG[k]<x){
			SEG[k]=x;
			PRE[k]=y;
		}
	}
	else {
		updata(a,b,x,y,2*k+1,l,(l+r)/2);
		updata(a,b,x,y,2*k+2,(l+r)/2,r);
	}
}

P query(int a){
	a+=siz-1;
	P ret=P(SEG[a],PRE[a]);
	while(a>0){
		a=(a-1)/2;
		if(ret.fr<SEG[a]){
			ret=P(SEG[a],PRE[a]);
		}
	}
	return ret;
}

int main(){
	LL n,d;
	static LL h[100010];
	cin>>n>>d;
	rep(i,n)scanf("%I64d",&h[i]);
	
	vector<LL> Z;
	rep(i,n)Z.pb(h[i]);
	sor(Z);
	uniq(Z);
	
	static int g[100010];
	rep(i,n)g[i]=lb(Z,h[i])-Z.begin();
	
	static int dp[100010];
	static int pre[100010];
	
	init(n);
	
	rep(i,n){
		P p=query(g[i]);
		dp[i]=p.fr+1;
		pre[i]=p.sc;
		
		updata(0,ub(Z,Z[g[i]]-d)-Z.begin(),dp[i],i,0,0,siz);
		updata(lb(Z,Z[g[i]]+d)-Z.begin(),siz,dp[i],i,0,0,siz);
	}
	
	int MAX=0,k=-1;
	vector<int> ans;
	rep(i,n){
		if(MAX<dp[i]){
			MAX=dp[i];
			k=i;
		}
	}
	ans.pb(k+1);
	while(pre[k]!=-1){
		k=pre[k];
		ans.pb(k+1);
	}
	rev(ans);
	
	printf("%d\n",MAX);
	rep(i,ans.size()-1){
		printf("%d",ans[i]);
		printf(" ");
		////
	}
	printf("%d\n",ans[ans.size()-1]);
}