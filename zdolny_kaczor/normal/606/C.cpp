# include <cstdio>
# include <set>
using namespace std;
const int MN = 1e5+16;
int pinv[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d", &x);
		pinv[x]=i;
	}
	int len = 0, last = 0, res = 0;
	for (int i=1; i<=n; ++i)
	{
		if (pinv[i]>last)
		{
			last=pinv[i];
			len++;
		}
		else
		{
			last=pinv[i];
			len=1;
		}
		res=max(res, len);
	}
	printf("%d\n", n-res);
}