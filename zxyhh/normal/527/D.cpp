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
#define maxn 400005
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
int n,dp[maxn];
struct num
{
	int x,w;
	bool operator < (const num &B) const {return (x<B.x)||(x==B.x&&w<B.w);}
}a[maxn];
struct TREE
{
	int mx[maxn<<2];
	inline int Max(int A,int B){return A>B?A:B;}
	void update(int pos,int l,int r,int x,int y)
	{
		if (l==r) {mx[pos]=Max(mx[pos],y);return ;}
		int mid=(l+r)>>1;
		if (x<=mid) update(pos<<1,l,mid,x,y);
		else update(pos<<1|1,mid+1,r,x,y);
		mx[pos]=Max(mx[pos<<1],mx[pos<<1|1]);
	}
	int query(int pos,int l,int r,int ql,int qr)
	{
		if (l==ql&&r==qr) return mx[pos];
		int mid=(l+r)>>1;
		if (qr<=mid) return query(pos<<1,l,mid,ql,qr);
		else if (ql>mid) return query(pos<<1|1,mid+1,r,ql,qr);
		else return Max(query(pos<<1,l,mid,ql,mid),query(pos<<1|1,mid+1,r,mid+1,qr));
	}
}tr;
int H[maxn<<1],tot;
/*
y>=b+c
x>=a+b
x+y>=b+c+a+b>=a+c
*/
int main()
{
	n=rd();
	rep(i,1,n) a[i].x=rd(),a[i].w=rd(),H[++tot]=a[i].x+a[i].w,H[++tot]=a[i].x-a[i].w;
	sort(a+1,a+1+n);sort(H+1,H+1+tot);
	int Ans=0;
	rep(i,1,n){
		dp[i]=tr.query(1,1,n<<1,1,lower_bound(H+1,H+1+tot,a[i].x-a[i].w)-H);
		dp[i]++;
		tr.update(1,1,n<<1,lower_bound(H+1,H+1+tot,a[i].x+a[i].w)-H,dp[i]);
		if (dp[i]>Ans) Ans=dp[i];
	}
	wrt(Ans,'\n');
}