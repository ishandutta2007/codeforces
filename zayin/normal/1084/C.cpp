#include<bits/stdc++.h>
#define maxn 100500
#define modu 1000000007
using namespace std;
typedef long long LL;

char s[maxn];
LL sum[maxn];

int main()
{
	scanf("%s",s+1);

	LL ans=0;
	int i,j;
	for (i=1,j=0;s[i];++i)
	{
		if (s[i]=='a')	sum[i]=sum[j]+1;
		if (s[i]=='b')	j=i;
		sum[i]=(sum[i]+sum[i-1])%modu;
	}
	printf("%lld\n",sum[i-1]);
	return 0;
}