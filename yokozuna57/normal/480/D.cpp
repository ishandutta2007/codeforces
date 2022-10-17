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
#define bs(vec,a) binary_search(vec.begin(),vec.end(),a)
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

int n;
int in[505],out[505],w[505],s[505],v[505];
int dp[505][1010];
int dp0[1010][1010];
bool used[505];

bool com(int x,int y){
	return out[x]<=out[y];
}

void solver(int a){
	vector<int> vec;
	rep1(i,n){
		if(in[a]<=in[i]&&out[i]<=out[a]&&i!=a){
			if(!used[i])solver(i);
			vec.pb(i);
		}
	}
	
	sort(vec.begin(),vec.end(),com);
	rep(i,1010)rep(j,1010)dp0[i][j]=0;
	
	/*cout<<a<<endl;
	cout<<vec.size()<<":";
	rep(i,vec.size())printf("%d ",vec[i]);
	cout<<endl;*/
	
	int t=in[a]+1;
	rep(i,vec.size()){
		for(;t<out[vec[i]];t++){
			rep(j,s[a]+1){
				dp0[t][j]=max(dp0[t][j],dp0[t-1][j]);
			}
		}
		rep(j,s[a]+1)dp0[out[vec[i]]][j]=max(dp0[out[vec[i]]][j],dp0[in[vec[i]]][j]+dp[vec[i]][j]);
		
	/*if(a==0){
		rep(i,out[0]+1){
			rep(j,s[0]+1){
				printf("%d ",dp0[i][j]);
			}
			printf("\n");
		}
	}*/
		
	}
	for(;t<=out[a];t++){
		rep(j,s[a]+1){
			dp0[t][j]=max(dp0[t][j],dp0[t-1][j]);
		}
	}
	
	/*if(a==0){
		rep(i,out[0]+1){
			rep(j,s[0]+1){
				printf("%d ",dp0[i][j]);
			}
			printf("\n");
		}
	}*/
	
	rep(i,1001){
		if(i>=w[a]){
			if(i>0)dp[a][i]=max(dp[a][i-1],dp0[out[a]][i-w[a]]+v[a]);
			else dp[a][i]=dp0[out[a]][i-w[a]]+v[a];
		}
		else dp[a][i]=0;
	}
	
	used[a]=true;
}

int main(){
	cin>>n>>s[0];
	in[0]=0;
	out[0]=2*n;
	w[0]=0;
	v[0]=0;
	rep1(i,n){
		scanf("%d%d%d%d%d",&in[i],&out[i],&w[i],&s[i],&v[i]);
	}
	
	rep(i,n+1)used[i]=false;
	solver(0);
	
	/*rep(i,n+1){
		rep(j,5){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}*/
	
	printf("%d\n",dp[0][s[0]]);
}