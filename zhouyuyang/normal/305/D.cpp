#include<bits/stdc++.h>
#define GG return puts("0"),0;
#define For(i,j,k) for (int i=j;i<=k;i++)
#define mo 1000000007
using namespace std;
int n,m,K;
int s[1000005],p[1000005];
int main(){
	scanf("%d%d%d",&n,&m,&K);++K;
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x+K==y) s[x]=1;
		else if (x+1!=y) GG;
	}
	For(i,1,n) s[i]+=s[i-1];
	For(i,K,n) if (s[i]-s[i-1]&&s[i-K]) GG;
	p[0]=1;
	For(i,1,n) p[i]=p[i-1]*2%mo;
	int ans=(s[n]==0);
	For(i,1,n-K)
		if(s[i]==s[n]&&(i<=K||s[i-K]==0))
			ans=(ans+p[min(i,K)-s[i-1]-1])%mo;
	printf("%d\n",ans);
}