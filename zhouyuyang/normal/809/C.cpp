

#include<cstdio>
#include<algorithm>
#define ll long long
#define maxn 510
#define For(i,x,y) for(ll i=x;i<=y;i++)
#define FOr(i,x,y) for(ll i=x;i>=y;i--)
using namespace std;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) x=-x,putchar('-');write(x);putchar('\n');}
ll k;	const ll mod=1e9+7;
ll work(ll x,ll y,ll p){
	if (!x||!y||p>=k)	return 0;
	if (x<y)	swap(x,y);
	ll t=x;	for(;t!=(t&-t);t-=(t&-t));	ll w=min(k,p+t);
	if (t>=y)	return ((w-p)*(p+w+1)/2%mod*y%mod+work(x-t,y,p+t))%mod;
	else	return ((w-p)*(p+w+1)/2%mod*t%mod+work(x-t,min(y,t),p+t)+work(min(t,x),y-t,p+t)+work(x-t,y-t,p))%mod;
}
int main(){
	ll Q=read();
	while(Q--){
		ll x1=read(),y1=read(),x2=read(),y2=read();	k=read();
		writeln((work(x2,y2,0)+work(x1-1,y1-1,0)-work(x1-1,y2,0)-work(x2,y1-1,0)+mod+mod)%mod);
	}
}