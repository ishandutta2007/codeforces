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
#define maxn 300005
int st[20][maxn],lg[maxn];
int n,a[maxn];
int gcd(int A,int B){return B==0?A:gcd(B,A%B);}
void init() {
	n=rd();
	rep(i,1,n) a[i]=rd(),st[0][i]=a[i];
	rep(i,2,n) lg[i]=lg[i>>1]+1;
	rep(i,1,19)
		rep(j,1,n-(1<<i)+1) 
			st[i][j]=gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
}
int query(int l,int r) {
	int g=lg[r-l+1];
	return gcd(st[g][l],st[g][r-(1<<g)+1]);
}
int vis[1000005];
bool check(int x) {
	memset(vis,0,sizeof vis);
	rep(i,1,x) vis[a[i]]++;
	if (vis[query(1,x)]) return 1;
	rep(i,x+1,n) {
		vis[a[i-x]]--,vis[a[i]]++;
		if (vis[query(i-x+1,i)]) return 1;
	}
	return 0;
}
int res[maxn],tot;
int main()
{
	init();
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	memset(vis,0,sizeof vis);
	rep(i,1,ans) vis[a[i]]++;
	if (vis[query(1,ans)]) res[++tot]=1;
	rep(i,ans+1,n) {
		vis[a[i-ans]]--,vis[a[i]]++;
		if (vis[query(i-ans+1,i)]) res[++tot]=i-ans+1;
	}
	wrt(tot,' '),wrt(ans-1,'\n');
	rep(i,1,tot) wrt(res[i],' ');
	putchar('\n');
}