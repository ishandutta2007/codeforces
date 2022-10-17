#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

const int M=1000000007;

int main(){
	int n,k;
	scanf("%d%d",&n,&k);

	static int dp[2005][2005]={0};
	for(int i=1;i<=n;i++)dp[1][i]=1;
	for(int i=1;i<k;i++){
		for(int j=1;j<=n;j++){
			for(int t=j;t<=n;t+=j){
				dp[i+1][t]+=dp[i][j];
				dp[i+1][t]%=M;
			}
		}
	}

	int ret=0;
	for(int i=1;i<=n;i++){ ret+=dp[k][i]; ret%=M; }

	printf("%d\n",ret);
}