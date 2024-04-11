#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define ull unsigned long long
using std::unordered_map;
const int N=40;
int n, ad=1, lim;
ull f;
char s[N];
unordered_map<ull, int> mp;
inline ull mul(ull x, ull y)
{
	ull ret=0;
	for(int i=n-1; ~i; --i)
	{
		ret<<=1;
		if((y>>i)&1) ret^=x;
		if((ret>>n)&1) ret^=f;
	}
	return ret;
}
int main()
{
	scanf("%s", s);
	n=strlen(s);
	for(int i=0; i<n; ++i) if(s[i]=='1') f|=1ull<<i;
	if(!f) return puts("-1"), 0;
	while(!(f&1)) f>>=1, ++ad;
	if(f==1) return printf("%d %d\n", ad, ad+1), 0;
	n=63-__builtin_clzll(f);
	lim=std::max(0, n/2-1);
	ull cur=1;
	for(int i=0; i<(1<<lim); ++i)
	{
		mp[cur]=i;
		cur<<=1;
		if((cur>>n)&1) cur^=f;
	}
	ull x=1;
	for(int i=1; i<=(1<<(n-lim)); ++i)
	{
		x=mul(x, cur);
		if(mp.count(x)) return printf("%d %lld\n", ad, ad+((ull)i<<lim)-mp[x]), 0;
	}
	puts("-1");
	return 0;
}