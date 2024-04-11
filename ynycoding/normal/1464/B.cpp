#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define ll long long
#define N 100005
int n, x, y, id[N], top;
ll ans, mn, val[N];
char s[N];
bool cmp(int a, int b) { return val[a]<val[b]; }
int main()
{
	scanf("%s", s+1);
	scanf("%d%d", &x, &y);
	n=strlen(s+1);
	for(int i=1, cx=0, cy=0; i<=n; ++i)
	{
		if(s[i]=='?')
		{
			id[++top]=i;
			ans+=1ll*cy*y;
			val[i]-=1ll*cy*y;
			val[i]+=1ll*cx*x;
			++cx;
		}
		else
		{
			if(s[i]=='0')
			{
				ans+=1ll*cy*y;
				++cx;
			}
			else
			{
				ans+=1ll*cx*x;
				++cy;
			}
		}
	}
	for(int i=n, cx=0, cy=0; i; --i)
	{
		if(s[i]=='?')
		{
			val[i]-=1ll*cy*x;
			val[i]+=1ll*cx*y;
			++cx;
		}
		else
		{
			if(s[i]=='0') ++cx;
			else ++cy;
		}
	}
	std::sort(id+1, id+top+1, cmp);
	mn=ans;
	for(int i=1; i<=top; ++i)
	{
		ans+=val[id[i]];
		mn=std::min(mn, ans-1ll*i*(i-1)/2*(x+y));
	}
	printf("%lld\n", mn);
	return 0;
}