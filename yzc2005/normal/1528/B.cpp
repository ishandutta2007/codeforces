#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,P=998244353;
int n,dp[N],d[N];
int main(){
  scanf("%d",&n),dp[1]=1;int s=1;
  for(int i=1;i<=n;++i)for(int j=i;j<=n;j+=i)++d[j];
  for(int i=2;i<=n;++i)dp[i]=(s+d[i])%P,s=(s+dp[i])%P;
  printf("%d\n",dp[n]);
  return 0;
}