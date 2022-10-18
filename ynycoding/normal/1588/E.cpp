#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
#define ld double
#define x first
#define y second
using std::pair;
typedef pair<int, int> vec;
const int N=3005;
const ld Pi=acos(-1.0);
pair<int, int> operator -(const vec &a, const vec &b)
{
	return {a.x-b.x, a.y-b.y};
}
inline ld len(const vec &a) { return std::sqrt(1ll*a.x*a.x+1ll*a.y*a.y); }
inline ld ang(const vec &a) { return atan2(a.y, a.x); }
int n, R, ans;
inline ld lower(const vec &a)
{
	return ang(a)-std::asin(R/len(a));
}
inline ld upper(const vec &a)
{
	return ang(a)+std::asin(R/len(a));
}
pair<int, int> p[N];
int ok[N][N], is;
ld l, r;
inline void inter(ld x, ld y)
{
	int tcnt=0;
	while(y<l) x+=2*Pi, y+=2*Pi, ++tcnt;
	l=std::max(l, x);
	r=std::min(r, y);
}
inline bool chk(ld x)
{
	while(x<l) x+=2*Pi;
	return x<=r;
}
int main()
{
	scanf("%d%d", &n, &R);
	for(int i=1; i<=n; ++i) scanf("%d%d", &p[i].x, &p[i].y);
	for(int i=1; i<=n; ++i)
	{
		is=0;
		for(int j=1; j<=n; ++j) if(len(p[j]-p[i])>R)
		{
			auto v=p[j]-p[i];
			ld a=ang(v), s=std::asin(R/len(v));
			if(is)
			{
				inter(a-s, a+s);
			}
			else
			{
				is=1;
				l=a-s, r=a+s;
				if(l<0) l+=2*Pi, r+=2*Pi;
			}
			if(l>r) break;
		}
		if(l<=r) for(int j=1; j<=n; ++j)
		{
			ok[i][j]|=(!is)|chk(ang(p[j]-p[i]));
		}
	}
	for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) if(ok[i][j]&&ok[j][i])
		++ans;
	printf("%d\n", ans);
	return 0;
}