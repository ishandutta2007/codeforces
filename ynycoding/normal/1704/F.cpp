#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=510005;
int T, n, sum, ct;
int f[N];
char s[N];
int cyc[20][2][20]={
	{{1, 4, 4, 6, 6, 4, 4, 6, 4, 4, 12}, {4, 4, 10, 4, 12}},
	{{2}, {1, 4, 1, 14, 1, 4, 1, 8}},
	{{4, 8, 1, 4, 1, 8, 6, 6, 8, 1, 5, 8, 12}, {8, 1, 13, 12}},
	{{6, 4, 1, 8, 1, 4, 16}, {4, 1, 8, 1, 4, 8, 8}},
	{{14, 16}, {4, 14, 1, 15}},
	{{16, 15}, {19, 1, 14}},
	{{},{}},
	{{33}, {34}},
	{{69}, {34}},
	{{86}, {34}},
};
void init(int n)
{
	for(int i=0; i<=9; ++i) if(i!=6)
	{
		int cur=0;
		for(int t=0; cyc[i][0][t]; ++t) cur+=cyc[i][0][t], f[cur]=i;
		int len=0;
		while(cyc[i][1][len]) ++len;
		int t=0;
		while(cur<=n) cur+=cyc[i][1][t], f[cur]=i, ++t, t=(t==len?0:t);
	}
}
int main()
{
	scanf("%d", &T);
	init(500000);
	while(T--)
	{
		scanf("%d%s", &n, s+1);
		ct=sum=0;
		for(int i=1; i<=n; ++i) sum+=s[i]=='R'?1:-1;
		int v=0, len=1;
		for(int i=2; i<=n; ++i)
		{
			if(s[i]!=s[i-1]) ++len;
			else v^=f[len], len=1;
		}
		v^=f[len];
		if(v) ++sum;
		puts(sum>0?"Alice":"Bob");
	}
	return 0;
}