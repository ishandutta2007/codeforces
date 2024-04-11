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
int n,a[maxn],pre[maxn],f[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		partial_sum(a+1,a+n+1,pre+1,bit_xor<>());
		map<int,pair<int,int>>mi;
		mi[0]={0,0};
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)f[i]=f[i-1];
			else
			{
				f[i]=f[i-1]+1;
				if(mi.count(pre[i]))f[i]=min(f[i],mi[pre[i]].first+i-mi[pre[i]].second-1);
			}
			if(!mi.count(pre[i])||mi[pre[i]].first-mi[pre[i]].second>f[i]-i)mi[pre[i]]={f[i],i};
		}
		printf("%d\n",f[n]);
	}
	return 0;
}