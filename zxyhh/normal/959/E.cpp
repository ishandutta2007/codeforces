//2018 0501 
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
const int xh1[7]={3,5,3,9,3,5,3};
int main()
{
    ll n=rd(),f=n&1;n+=n&1;
    ll ans=1;
    n=(n-2)/2;ans+=(n/8)*31;
    rep(i,1,n%8) ans+=xh1[i-1];
    rep(i,4,50) {
        ll k=1ll<<(1ll*i);
        ans+=max((n-(k>>1ll))/k+(n>=(k>>1ll)),0)*(k|1ll);
    }
    wrt(ans-f,'\n');
}