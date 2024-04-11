#include <cstdio>
#include <cstring>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXLS=2005;
const int MAXLP=505;
int ls,lp;
char s[MAXLS];
char p[MAXLP];
int matchend[MAXLS];
int f[MAXLS][MAXLS];
int g[MAXLS][MAXLS];
int cg[MAXLS];
void init()
{
	scanf("%s%s",s,p);
	ls=strlen(s);lp=strlen(p);
	for (int i=0;i<ls;++i)
	{
		int j=i;
		for (int k=0;k<lp;++k)
		{
			while (j<ls&&s[j]!=p[k]) ++j;
			++j;
		}
		if (j>ls) matchend[i]=-1;
		else matchend[i]=j;
	}
}
void solve()
{
	for (int i=0;i<=ls;++i)
	{
		for (int j=0;j<=i;++j)
		{
			if (g[i][j]>cg[j]) cg[j]=g[i][j];
			if (cg[j]>f[i][j]) f[i][j]=cg[j];
		}
		if (i==ls) break;
		for (int j=0;j<=i;++j)
		{
			if (f[i][j]>f[i+1][j+1])
				f[i+1][j+1]=f[i][j];
			if (matchend[i]!=-1&&f[i][j]+1>g[matchend[i]][j+lp])
				g[matchend[i]][j+lp]=f[i][j]+1;
		}
	}
	for (int i=ls;i>=0;--i)
		printf("%d ",f[ls][i]);
	printf("\n");
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