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
const int maxn=105;
int n;
int a[maxn];
bool exi[3];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		exi[0]=exi[1]=exi[2]=0;
		sort(a+1,a+n+1);n=unique(a+1,a+n+1)-(a+1);
		exi[1]=exi[2]=0;
		for(int i=1;i<=n;i++)exi[a[i]%3]=1;
		int ans=1e9;
		if(!exi[1]&&!exi[2])ans=min(ans,a[n]/3);
		if(!exi[1]||!exi[2])ans=min(ans,a[n]/3+1);
		if(a[1]!=1)
		{
			if(a[n]%3==2||a[n]%3==0)ans=min(ans,a[n]/3+2);
			if(a[n]%3==1)
			{
				if(a[n-1]==a[n]-1)ans=min(ans,a[n]/3+2);
				else ans=min(ans,a[n]/3+1);
			}
		}
		ans=min(ans,(int)ceil(1.0*(a[n]-3)/3)+2);
		printf("%d\n",ans);
	}
	return 0;
}