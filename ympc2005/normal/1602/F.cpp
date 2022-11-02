#include <bits/stdc++.h>
#define TT template<typename T>
using namespace std;

typedef long long LL;
const int MAXN = 500005;
int n,d;
int s[MAXN],a[MAXN],p[MAXN];

LL Read()
{
	LL x = 0,f = 1; char c = getchar();
	while(c > '9' || c < '0'){if(c == '-') f = -1;c = getchar();}
	while(c >= '0' && c <= '9'){x = (x*10) + (c^48);c = getchar();}
	return x * f;
}
TT void Put1(T x)
{
	if(x > 9) Put1(x/10);
	putchar(x%10^48);
}
//
TT void Put(T x,char c = -1)
{
	if(x < 0) putchar('-'),x = -x;
	Put1(x); if(c >= 0) putchar(c);
}
TT T Max(T x,T y){return x > y ? x : y;}
TT T Min(T x,T y){return x < y ? x : y;}
TT T Abs(T x){return x < 0 ? -x : x;}

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n = Read(); d = Read();
	for(int i = 1;i <= n;++ i) s[i] = Read(),a[i] = Read(),p[i] = i;
	sort(p+1,p+n+1,[](int x,int y){
		if(Max(s[x],a[x]) ^ Max(s[y],a[y])) return Max(s[x],a[x]) < Max(s[y],a[y]);
		return s[x] < s[y];
	});
	int ans = 0;
	for(int i = 1;i <= n;++ i)
		if(s[p[i]] >= d) ++ans,d = Max(d,a[p[i]]);
	Put(ans,'\n');
	return 0;
}