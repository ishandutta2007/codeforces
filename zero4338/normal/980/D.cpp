#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=5e3+5;
int n,a[maxn];
unordered_set<int>exi;
int ans[maxn];
int main()
{
	generate_n(a+1,n=read(),read);
	for(int i=1;i<=n;i++)
		for(int j=2;j*j<=abs(a[i]);j++)
			while(a[i]%(j*j)==0)a[i]/=j*j;
	for(int l=1;l<=n;l++)
	{
		exi.clear();
		for(int r=l;r<=n;r++)
		{
			if(a[r])exi.insert(a[r]);
			if(!exi.size())ans[1]++;
			else ans[exi.size()]++;
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}