#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7,P=1e9+7;

int n;

char s[N];

int pre[N],suf[N],ten[N];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	ten[0]=1;
	for(int i=1;i<=n;i++)
		ten[i]=(ten[i-1]*10ll+1)%P;
	for(int i=1;i<=n;i++)
		pre[i]=(pre[i-1]*10ll+s[i]-'0')%P;
	for(int i=n,j=1;i>=1;i--,j=j*10ll%P)
		suf[i]=(suf[i+1]+1ll*(s[i]-'0')*j%P)%P;
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+1ll*suf[i]*(i-1)%P)%P;
	for(int i=1;i<=n;i++)
		ans=(ans+1ll*pre[i]*ten[n-i-1]%P)%P;
	printf("%d\n",ans);
}