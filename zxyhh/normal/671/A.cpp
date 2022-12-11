/*
	>Author: zxy_hhhh
	>blog: zxy-hhhh.cn
	>date: 2019/01/29
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
#define maxn 100005
using namespace std;
inline ll rd() {
	ll _x=0;int _ch=getchar(),_f=1;
	for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
	if (_ch=='-'){_f=-1;_ch=getchar();}
	for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
	return _f*_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
double dp[maxn][4];
int n;
struct point {
	int x,y;
	void init(){x=rd(),y=rd();}
}a,b,t;
#define sqr(a) (1ll*(a)*(a))
inline double dis(point A,point B) {
	return sqrt(sqr(A.x-B.x)+sqr(A.y-B.y));
}
int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	a.init(),b.init(),t.init();
	n=rd();
	dp[0][0]=0,dp[0][1]=dp[0][2]=dp[0][3]=1e18;
	double ans=0;
	rep(i,1,n) {
		point p;
		p.init(),ans+=dis(t,p)*2.0;
		dp[i][1]=min(dp[i-1][1],dp[i-1][0]+dis(a,p)-dis(t,p));
		dp[i][2]=min(dp[i-1][2],dp[i-1][0]+dis(b,p)-dis(t,p));
		dp[i][3]=min(dp[i-1][2]+dis(a,p)-dis(t,p),
			         dp[i-1][1]+dis(b,p)-dis(t,p));
		dp[i][3]=min(dp[i][3],dp[i-1][3]);
	}
	printf("%.9lf\n",ans+min(dp[n][1],min(dp[n][2],dp[n][3])));
}