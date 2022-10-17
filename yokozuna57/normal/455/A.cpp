#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
using namespace std;

int main(){
	long long n;
	static long long a[100010];

	scanf("%I64d",&n);
	for(long long i=0;i<n;i++){
		scanf("%I64d",&a[i]);
	}

	static long long cnt[100010]={0};
	static long long dp[100010][2]={0};

	for(long long i=0;i<n;i++){
		cnt[a[i]]++;
	}

	for(long long i=1;i<=100000;i++){
		dp[i][0]=dp[i-1][1]+i*cnt[i];
		dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
	}

	printf("%I64d\n",max(dp[100000][0],dp[100000][1]));
}