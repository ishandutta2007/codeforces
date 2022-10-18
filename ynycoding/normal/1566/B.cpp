#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=100005;
int T, n, f[N], pr[2];
char s[N], t[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s+1);
		n=strlen(s+1);
		pr[0]=pr[1]=0;
		for(int i=1; i<=n; ++i)
		{
			pr[s[i]-'0']=i;
			f[i]=f[i-1]+1;
			if(pr[0])
			{
				f[i]=std::min({(pr[0]<i?f[pr[0]]:2), (pr[1]?f[std::min(pr[0], pr[1])]+1:1), 2});
			}
			else f[i]=0;
		}
		printf("%d\n", f[n]);
	}
	return 0;
}