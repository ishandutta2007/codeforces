#include <algorithm>
#include <cstdio>
#include <cstring>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=100005;
int n,maxb,t;
int b[MAXN];
int f[MAXN];
int pos[MAXN];
void init()
{
	for (int i=0;i<n;++i)
		scanf("%d",&b[i]);
}
void solve()
{
	if (t>maxb) t=maxb;
	memset(f,0,sizeof(f));
	memset(pos,0x3f,sizeof(pos));
	pos[0]=0;
	for (int i=0;i<=t*n;++i)
	{
		int x=(i==t*n?maxb+1:b[i%n]);
		while (pos[f[x]]<x) ++f[x];
		pos[f[x]]=x;
	}
	printf("%d\n",f[maxb+1]-1);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("261D.in","r",stdin);
	freopen("261D.out","w",stdout);
#endif
	int k;
	scanf("%d%d%d%d",&k,&n,&maxb,&t);
	while (k--)
	{
		init();
		solve();
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}