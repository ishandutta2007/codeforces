#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=100005;
int n;
int x[MAXN];
int y[MAXN];
int rx[MAXN];
int ry[MAXN];
void init()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%d%d",&x[i],&y[i]);
	memcpy(rx,x,sizeof(rx));
	memcpy(ry,y,sizeof(ry));
	std::sort(rx,rx+n);
	std::sort(ry,ry+n);
}
void solve()
{
	int mid=(n-1)/2;
	int d;
	d=rx[mid+1]-rx[mid];
	if (n%2) d=std::min(d,rx[mid]-rx[mid-1]);
	d=std::min(d,ry[mid+1]-ry[mid]);
	if (n%2) d=std::min(d,ry[mid]-ry[mid-1]);
	long long sum=0;
	int f1=0,f2=0,f3=(n%2==0);
	for (int i=0;i<n;++i)
		sum+=abs(rx[i]-rx[mid])+abs(ry[i]-ry[mid]);
	for (int i=0;i<n;++i)
	{
		if (x[i]>rx[mid]&&y[i]>ry[mid]) f1=1;
		if (x[i]>rx[mid]&&y[i]<=ry[mid]) f2=1;
		if (x[i]==rx[mid]&&y[i]==ry[mid]) f3=1;
	}
	if (f1&&f2&&f3) sum-=d;
	printf(LLFORMAT"d\n",sum*2);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("329E.in","r",stdin);
	freopen("329E.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}