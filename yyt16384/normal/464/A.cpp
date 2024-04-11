#include <cstdio>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=1005;
const int MAXP=26;
int n,p;
char s[MAXN];
void init()
{
	scanf("%d%d%s",&n,&p,s);
}
int getpos()
{
	int r=n-1;
	while (r>=0)
	{
		int fl=0;
		for (int i=s[r]+1;i<p+'a';++i)
			if ((r<1||i!=s[r-1])&&(r<2||i!=s[r-2]))
			{
				fl=1;break;
			}
		if (fl) break;
		--r;
	}
	return r;
}
void work(int x)
{
	while (!((x<1||s[x]!=s[x-1])&&(x<2||s[x]!=s[x-2]))) ++s[x];
}
void solve()
{
	int p=getpos();
	if (p==-1)
	{
		printf("NO\n");
		return;
	}
	++s[p];
	for (int i=p+1;i<n;++i) s[i]='a';
	for (int i=p;i<n;++i) work(i);
	printf("%s\n",s);
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