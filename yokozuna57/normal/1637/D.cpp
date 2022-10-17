#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

template<class T> T T_INF(){ return 1000000000000000000; }
template<> int T_INF<int>(){ return 1000000000; }

const int INF=1000000000;

int n;
int a[102],b[102];
int s[102];

int dp[102][10010];

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		for(int i=0;i<n;i++)scanf("%d",&b[i]);
		s[0]=0;
		for(int i=0;i<n;i++){
			s[i+1]=s[i]+a[i]+b[i];
		}
		
		for(int i=0;i<=n;i++)for(int j=0;j<10010;j++)dp[i][j]=INF;
		dp[0][0]=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<10010;j++){
				if(dp[i][j]==INF)continue;
				if(j+a[i]<10010)dp[i+1][j+a[i]]=min(dp[i+1][j+a[i]],dp[i][j]+a[i]*j+b[i]*(s[i]-j));
				if(j+b[i]<10010)dp[i+1][j+b[i]]=min(dp[i+1][j+b[i]],dp[i][j]+b[i]*j+a[i]*(s[i]-j));
			}
		}
		int ret=INF;
		for(int j=0;j<10010;j++)ret=min(ret,dp[n][j]);
		ret*=2;
		for(int i=0;i<n;i++)ret+=(n-1)*(a[i]*a[i]+b[i]*b[i]);
		printf("%d\n",ret);
	}
}