#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
const int maxn=3e5+5;
int n,q;
char s[maxn];int sum[maxn];
vector<int>v[maxn<<2];
int main()
{
	T=read();
	while(T--)
	{
		n=read();q=read();scanf("%s",s+1);
		for(int i=0;i<=n*4;i++)v[i].clear();
		for(int i=1;i<=n;i++)
		{
			int now=0;
			if(s[i]=='+')
			{
				if(i&1)sum[i]=sum[i-1]+1;
				else sum[i]=sum[i-1]-1;
			}
			else
			{
				if(i&1)sum[i]=sum[i-1]-1;
				else sum[i]=sum[i-1]+1;
			}
		}
		for(int i=1;i<=n;i++)v[sum[i]+sum[i-1]+2*n].push_back(i);
		while(q--)
		{
			int l=read(),r=read();
			if(sum[r]-sum[l-1]==0)printf("0\n");
			else
			{
				auto it=lower_bound(v[sum[r]+sum[l-1]+2*n].begin(),v[sum[r]+sum[l-1]+2*n].end(),l);
				if(it!=v[sum[r]+sum[l-1]+2*n].end()&&*it<=r)printf("1\n");
				else printf("2\n");
			}
		}
	}
	return 0;
}