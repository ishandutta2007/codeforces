#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int T;
int a[2005];
int pre[2005];
int suf[2005];
signed main(){
	T=read();
	while(T--)
	{
		int n,k;
		n=read();
		int res=0;
		memset(pre,0,sizeof(pre));
		memset(suf,0,sizeof(suf));
		for(int i=1;i<=n;i++)a[i]=read(),pre[i]=pre[i-1]^a[i];
		for(int i=n;i>=1;i--)suf[i]=suf[i+1]^a[i];
		int vis=0;
		for(int i=1;i<=n;i++)
		{
			if(pre[i]==suf[i+1])
			{
				vis=1;
				break;
			}
			for(int j=i+1;j<=n;j++)
			{
				if(pre[i]==suf[j]&&pre[i]==(pre[j-1]^pre[i]))
				{
					vis=1;
					break;
				}
			}
			if(vis)break;
		}
		if(vis)puts("YES");
		else puts("NO");
	}
	return 0;
}