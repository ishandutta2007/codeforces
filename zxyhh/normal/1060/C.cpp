#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<string>
#include<queue>
#include<cmath>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
#define ldb long double
using namespace std;
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
void write(ll prt_x){ if (prt_x>=10) write(prt_x/10),putchar(prt_x%10+'0'); else putchar(prt_x+'0'); }
inline void wrt(ll prt_x,char prt_c){if (prt_x<0) putchar('-'),prt_x=-prt_x; write(prt_x); if (prt_c) putchar(prt_c);}
int n,m;
ll a[2005],b[2005],sa[2005],sb[2005],ta[2005],tb[2005],ans,x;
ll min(ll A,ll B)
{
    if (!~A) return B;
    if (!~B) return A;
    return std::min(A,B);
}
int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	memset(ta, -1, sizeof(ta));
	memset(tb, -1, sizeof(tb));

	n=rd(),m=rd();
	for (int i = 1; i <= n; i++)
		a[i]=rd();
	for (int i = 1; i <= m; i++)
		b[i]=rd();
	x=rd();
	for (int i = 1; i <= n; i++)
		sa[i] = sa[i - 1] + a[i];
	for (int i = 1; i <= m; i++)
		sb[i] = sb[i - 1] + b[i];
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			ta[j - i + 1] = min(ta[j - i + 1], sa[j] - sa[i - 1]);
	for (int i = 1; i <= m; i++)
		for (int j = i; j <= m; j++)
			tb[j - i + 1] = min(tb[j - i + 1], sb[j] - sb[i - 1]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (ta[i] * tb[j] <= x)
				ans = std::max(ans, (ll)i * (ll)j);
	wrt(ans,'\n');

	return 0;
}