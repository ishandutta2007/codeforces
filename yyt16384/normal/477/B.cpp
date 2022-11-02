#include <cstdio>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d\n",(6*n-1)*k);
	for (int i=0;i<n;++i)
		printf("%d %d %d %d\n",(6*i+1)*k,(6*i+2)*k,(6*i+3)*k,(6*i+5)*k);
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}