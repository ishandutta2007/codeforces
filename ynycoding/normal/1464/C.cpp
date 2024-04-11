#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define ll long long
#define N 100005
using std::abs;
int n, a[N], cnt[30];
ll T;
char s[N];
int main()
{
	scanf("%d%lld", &n, &T);
	scanf("%s", s+1);
	for(int i=1; i<=n; ++i) a[i]=s[i]-'a';
	if(n==1) return puts((1<<a[1])==T?"Yes":"No"), 0;
	T-=(1<<a[n]), T+=(1<<a[n-1]);
	for(int i=1; i<=n-2; ++i) ++cnt[a[i]];
	for(int i=25; ~i; --i)
	{
		if(cnt[i]&1)
		{
			ll d=std::min((T>>i), (ll)cnt[i]);
			d|=1;
			ll T1=abs(T-(d<<i));
			if(d+2<=cnt[i]) T1=std::min(T1, abs(T-((d+2)<<i)));
			T=T1;
		}
		else
		{
			ll d=std::min((T>>i), (ll)cnt[i]);
			if(d&1) d^=1;
			ll T1=abs(T-(d<<i));
			if(d+2<=cnt[i]) T1=std::min(T1, abs(T-((d+2)<<i)));
			T=T1;
		}
	}
	puts(T?"No":"Yes");
	return 0;
}