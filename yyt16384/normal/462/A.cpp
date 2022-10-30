#include <cstdio>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=105;
int n;
char a[MAXN][MAXN];
void init()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i) scanf("%s",a[i]);
}
void solve()
{
	const int DR[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
	int fl=1;
	for (int i=0;i<n;++i)
		for (int j=0;j<n;++j)
		{
			int sum=0;
			for (int k=0;k<4;++k)
			{
				int nx=i+DR[k][0],ny=j+DR[k][1];
				if (nx>=0&&nx<n&&ny>=0&&ny<n) sum+=(a[nx][ny]=='o');
			}
			if (sum%2) fl=0;
		}
	if (fl) printf("YES\n");
	else printf("NO\n");
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}