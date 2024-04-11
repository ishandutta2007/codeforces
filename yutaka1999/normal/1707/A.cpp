#include <bits/stdc++.h>
#define SIZE 100005
using namespace std;

int A[SIZE];
int dp[SIZE];

void solve(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	dp[n-1]=1;
	for(int i=n-2;i>=0;i--){
		if(A[i]<=dp[i+1]) dp[i]=dp[i+1];
		else dp[i]=dp[i+1]+1;
	}
	for(int i=0;i<n;i++){
		if(A[i]<=q) printf("1");
		else if(dp[i]<=q){
			printf("1");
			q--;
		} else{
			printf("0");
		}
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
}