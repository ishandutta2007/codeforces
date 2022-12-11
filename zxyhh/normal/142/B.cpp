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
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
inline ll rd(){
	ll x=0;int ch=getchar(); bool f=1;
	while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
	if (ch=='-'){f=0;ch=getchar();}
	while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?x:-x;
}
void write(ll x){ if (x>=10) write(x/10),putchar(x%10+'0'); else putchar(x+'0'); }
inline void wrt(ll x,int p){if (x<0) putchar('-'),x=-x; write(x); if (p) putchar(p);}
ll n,m;
int T;
int main()
{
//	freopen("psycho.in","r",stdin);
//	freopen("psycho.out","w",stdout);
//	T=rd();
//	while(T--){
		n=rd(),m=rd();
		if (n==1||m==1) {wrt(max(n,m),'\n');return 0;}
		if (n==2||m==2){
			ll p=max(n,m),ans=(p/4ll)*4ll;
			if ((p&3ll)<=2) ans+=(p&3ll)*2ll;
			else ans+=4;
			wrt(ans,'\n');
			return 0;
		}
		wrt((n*m+1ll)>>1ll,'\n');
//	}
}