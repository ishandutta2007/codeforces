#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e5+5;
int n;
char a[maxn],b[maxn];
int cnt[4];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		scanf("%s%s",a+1,b+1);
		cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++)cnt[((a[i]-'0')<<1)+b[i]-'0']++;
		int ans=1e9;
		if(cnt[1]==cnt[2])ans=min(ans,cnt[1]*2);
		if(cnt[0]==cnt[3]-1)ans=min(ans,1+cnt[0]*2);
		if(ans==1e9)puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}