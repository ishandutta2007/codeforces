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
	string s;
	string p;
	cin>>s>>p;
	
	int n=s.size();
	int m=p.size();
	
	int pre[2010]; rep(i,2010)pre[i]=-1;
	
	int dp0[2010];
	rep(i,n){
		if(s[i]!=p[0])continue;
		int k=0;
		for(int j=i;j<n;j++){
			if(s[j]==p[k]){
				k++;
				if(k==m){
					pre[j]=max(pre[j],i);
					break;
				}
			}
		}
	}
	
	/*rep(i,n){
		printf("%d\n",pre[i]);
	}*/
	
	static int dp[2010][2010]; rep(i,2010){ rep(j,2010)dp[i][j]=INF; dp[i][0]=0; }
	
	rep(i,n){
		rep1(j,n){
			if(i>0)dp[i][j]=dp[i-1][j];
			if(pre[i]!=-1){
				if(pre[i]!=0)dp[i][j]=min(dp[i][j],dp[pre[i]-1][j-1]+i-pre[i]+1-m);
				if(j==1) dp[i][j]=min(dp[i][j],i+1-m);
			}
		}
	}
	
	/*rep(i,n){
		rep(j,n){
			printf("%d ",dp[i][j]);
		}
		cout<<endl;
	}*/
	
	vector<int> ans;
	
	rep(i,n+1){
		if(dp[n-1][i]!=INF)ans.pb(dp[n-1][i]);
	}
	
	int ss=ans.size();
	//cout<<ss<<endl;
	//cout<<n-(ss-1)*m+1<<endl;
	
	int ret[2010];
	
	rep(i,n-(ss-1)*m+1){
		ret[i]=(ub(ans,i)-ans.begin())-1;
	}
	for(int i=n-(ss-1)*m+1;i<=n;i++){
		ret[i]=(n-i)/m;
	}
	
	rep(i,n)printf("%d ",ret[i]);
	printf("%d\n",ret[n]);
}