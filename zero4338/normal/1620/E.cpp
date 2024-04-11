#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=5e5+5;
int n;
int q;
int a[maxn];
vector<int>pos[maxn];
int main()
{
	q=read();
	for(int i=1;i<=q;i++)
	{
		int opt=read();
		if(opt==1)
		{
			n++;pos[read()].push_back(n);
		}
		else
		{
			int x=read(),y=read();if(x==y)continue;
			if(pos[x].size()>pos[y].size())swap(pos[x],pos[y]);
			for(int &i:pos[x])pos[y].push_back(i);
			pos[x].clear();
		}
	}
	for(int i=1;i<=5e5;i++)
		for(int &j:pos[i])a[j]=i;
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}