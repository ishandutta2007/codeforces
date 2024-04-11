#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=5e4+5;
int n,x,a[maxn];
int f[maxn];
int ans;
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		x=read();
		for(int i=1;i<=n;i++)a[i]-=x;
		ans=0;
		a[0]=1e9;a[n+1]=1e9;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=0)
			{
				if(a[i]+a[i-1]>=0)f[i]=f[i-1]+1;
				else f[i]=max(f[i-1],f[i-2]+1);
			}
			else
			{
				if(a[i]+a[i-1]<0)f[i]=max(f[i-2]+1,f[i-1]);
				else
				{
					if(i==1||a[i-2]>=0)f[i]=f[i-1]+1;
					else
					{
						if(a[i-2]+a[i-1]+a[i]>=0)f[i]=f[i-1]+1;
						else
						{
							f[i]=max(f[i-1],f[i-3]+2);
							f[i]=max(f[i],f[i-2]+1);
						}
					}
				}
			}
		}
		printf("%d\n",f[n]);
	}
	return 0;
}