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
const int maxn=1e4+5;
int n;
bool vis[maxn];
int query(int pos){printf("? %d\n",pos);fflush(stdout);return read();}
vector<int>p;
int ans[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				p.clear();
				int now=query(i);
				while(!vis[now])
				{
					p.push_back(now);
					vis[now]=1;
					now=query(i);
				}
				p.push_back(now);
				for(int j=p.size()-1;j>=1;j--)
					ans[p[j-1]]=p[j];
			}
		}
		printf("! ");for(int i=1;i<=n;i++)printf("%d ",ans[i]);putchar('\n');
		fflush(stdout);
	}
	return 0;
}