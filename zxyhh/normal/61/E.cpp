/*
	Author: zxy_hhhh
	date: 2019/03/29
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
using namespace std;
inline ll rd()
{
	ll _x=0;int _ch=getchar(),_f=1;
	for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
	if (_ch=='-'){_f=0;_ch=getchar();}
	for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
	return _f?_x:-_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
#define maxn 1000005
int a[maxn],H[maxn];
int tr1[maxn],tr2[maxn];
int n;
inline void add(int x,int v,int *tr) {
	for(;x<=n;x+=x&-x) tr[x]+=v;
}
inline int query(int x,int *tr) {
	int ans=0;
	for(;x;x-=x&-x) ans+=tr[x];
	return ans;
}
int main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	n=rd();
	rep(i,1,n) H[i]=a[i]=rd();
	sort(H+1,H+1+n);
	rep(i,1,n) a[i]=lower_bound(H+1,H+1+n,a[i])-H;
	rep(i,1,n) add(a[i],1,tr2);
	ll ans=0;
	rep(i,1,n) {
		add(a[i],-1,tr2);
		ans+=1ll*(query(n,tr1)-query(a[i],tr1))*(query(a[i]-1,tr2));
		add(a[i],1,tr1);
	}
	wrt(ans,'\n');
}