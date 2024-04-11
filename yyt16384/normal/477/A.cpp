#include <cstdio>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MOD=1000000007;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	int a,b;
	int ans;
	scanf("%d%d",&a,&b);
	ans=((long long)a*(a+1)/2%MOD*b%MOD+a)*((long long)b*(b-1)/2%MOD)%MOD;
	printf("%d\n",ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}