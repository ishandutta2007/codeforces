#include<bits/stdc++.h>
using namespace std;
int n;
int c[2][2];
char S[100100],T[100100];
int main(){
	scanf("%d",&n);
	scanf("%s%s",S+1,T+1);
	for(int i=1;i<=n;++i)
		c[S[i]-'0'][T[i]-'0']++;
	long long ans=1ll*c[0][1]*c[1][0]+1ll*c[0][0]*c[1][1]+1ll*c[0][0]*c[1][0];
	printf("%lld",ans);
}