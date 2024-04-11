#include <cstdio>
#include <algorithm>
const int N=200005;
int T, a, b, ok[N], tot;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &a, &b);
		tot=0;
		std::fill(ok, ok+a+b+1, 0);
		int n=a+b, l=(n+1)>>1, r=n>>1;
		for(int i=0; i<=(a-l>0?std::min(r-(a-l), b):std::min(a, l-(b-r))); ++i)
			ok[std::abs(a-l)+i*2]=1;
		for(int i=0; i<=(a-r>0?std::min(l-(a-r), b):std::min(a, r-(b-l))); ++i)
			ok[std::abs(a-r)+i*2]=1;
		for(int i=0; i<=a+b; ++i) tot+=ok[i];
		printf("%d\n", tot);
		for(int i=0; i<=a+b; ++i) if(ok[i]) printf("%d ", i);
		puts("");
	}
	return 0;
}