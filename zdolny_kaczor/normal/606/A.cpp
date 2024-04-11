# include <cstdio>
# include <set>
using namespace std;
int amo=0;
void inc (int x)
{
	if (x>0)
		amo+=x/2;
	else
		amo+=x;
}
int main()
{
	int a, b, c, d, e, f;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
	a-=d;
	b-=e;
	c-=f;
	inc(a);
	inc(b);
	inc(c);
	if (amo>=0)
	{
		printf("Yes\n");
	}
	else
		printf("No\n");
}