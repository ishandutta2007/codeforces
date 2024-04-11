#include <cstdio>
int b, k, a, cnt;
int main()
{
	scanf("%d%d", &b, &k);
	for(int i=1; i<k; ++i) scanf("%d", &a), cnt+=((a&1)&&(b&1))?1:0;
	scanf("%d", &a);
	cnt+=a%2;
	if(cnt&1) puts("odd"); else puts("even");
	return 0;
}