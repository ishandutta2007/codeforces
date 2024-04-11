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
const int maxn=5e3+5;
int n,a[maxn],f[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		static int cnt[maxn];
		memset(f,-0x3f,sizeof f);
		f[0]=0;
		for(int i=1;i<=n;i++)
		{
			memset(cnt,0,sizeof(int)*(n+1));
			int mx=0;
			for(int j=i-1;j>=0;j--)
			{
				if(j!=i-1)cnt[a[j+1]]++,mx=max(mx,cnt[a[j+1]]);
				if(((j-i)&1)&&mx*2<=i-j-1&&(j==0||a[j]==a[i]))f[i]=max(f[i],f[j]+1);
			}
		}
		memset(cnt,0,sizeof(int)*(n+1));
		int mx=0;	
		int ans=0;
		for(int i=n;i>=1;i--)
		{
			// check [i+1,n] deleted?
			if(i!=n)cnt[a[i+1]]++,mx=max(mx,cnt[a[i+1]]);
			if(((n-i+1)&1)&&mx*2<=n-i)ans=max(ans,f[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}