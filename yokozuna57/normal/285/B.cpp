#include<iostream>
using namespace std;

int main(){
	int n,s,t,a[100000+2],dp[100000+2];
	scanf("%d%d%d",&n,&s,&t);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dp[s]=0;
	while(1){
		if(s==t)break;
		if(dp[a[s]]!=NULL){dp[t]=-1; break;}
		dp[a[s]]=dp[s]+1;
		s=a[s];
	}
	printf("%d\n",dp[t]);
}