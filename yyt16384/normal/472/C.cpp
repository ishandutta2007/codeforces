#include <cstdio>
#include <cstring>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=100005;
const int MAXL=55;
int n;
char s[MAXN][2][MAXL];
int a[MAXN];
void init()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i)
		scanf("%s%s",s[i][0],s[i][1]);
	for (int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		--a[i];
	}
}
void solve()
{
	char *min=NULL;
	for (int i=0;i<n;++i)
	{
		int x=a[i];
		char *p=NULL;
		for (int j=0;j<2;++j)
			if ((min==NULL||strcmp(min,s[x][j])<0)&&(p==NULL||strcmp(s[x][j],p)<0)) p=s[x][j];
		if (p==NULL)
		{
			printf("NO\n");
			return;
		}
		min=p;
	}
	printf("YES\n");
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}