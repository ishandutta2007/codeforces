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
const int maxn=1.5e5+5;
int n;
int a[maxn];
vector<int>pos[maxn];
bool vis[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		for(int i=1;i<=n;i++)
			pos[a[i]].clear(),vis[a[i]]=0;
		for(int i=1;i<=n;i++)
			pos[a[i]].push_back(i);
		int ret=-1;
		for(int i=1;i<=n;i++)
		{
			if(!vis[a[i]])
			{
				vis[a[i]]=1;
				for(int j=0;j+1<pos[a[i]].size();j++)
					ret=max(ret,pos[a[i]][j]+n-pos[a[i]][j+1]);
			}
		}
		printf("%d\n",ret);
	}
	return 0;
}