#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
//using namespace std;
using std::min;
using std::max;
using std::swap;
using std::sort;
using std::reverse;
using std::random_shuffle;
using std::lower_bound;
using std::upper_bound;
using std::unique;
using std::vector;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
void open2(const char *s){
#ifdef DEBUG
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
const int N=1010;
namespace seg
{
	int s[1<<21];
	int t[1<<21];
	#define lc (p<<1)
	#define rc ((p<<1)|1)
	#define mid ((L+R)>>1)
	void add(int p,int l,int r,int v,int L,int R)
	{
		if(l<=L&&r>=R)
		{
			t[p]=max(t[p],v);
			s[p]=max(s[p],v);
			return;
		}
		if(l<=mid)
			add(lc,l,r,v,L,mid);
		if(r>mid)
			add(rc,l,r,v,mid+1,R);
		s[p]=max(min(s[lc],s[rc]),t[p]);
	}
	int query(int p,int l,int r,int L,int R)
	{
		if(l<=L&&r>=R)
			return s[p];
		int res=0x7fffffff;
		if(l<=mid)
			res=min(res,query(lc,l,r,L,mid));
		if(r>mid)
			res=min(res,query(rc,l,r,mid+1,R));
		res=max(res,t[p]);
		return res;
	}
}
struct info
{
	int x1,y1,x2,y2,v;
};
info c[N*N];
int t;
int cmp(info a,info b)
{
	return a.x1<b.x1;
}
int dx[N*N],dy[N*N],tx,ty;
int a[N][N];
int ax[N][N],ay[N][N];
int n,vx,vy;
int main()
{
	open("cf243d");
	scanf("%d%d%d",&n,&vx,&vy);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			ax[i][j]=(ll)vy*j+(ll)vx*i;
			ay[i][j]=(ll)vx*j-(ll)vy*i;
			dx[++tx]=ax[i][j];
			dy[++ty]=ay[i][j];
		}
	sort(dx+1,dx+tx+1);
	sort(dy+1,dy+ty+1);
	tx=unique(dx+1,dx+tx+1)-dx-1;
	ty=unique(dy+1,dy+ty+1)-dy-1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			ax[i][j]=lower_bound(dx+1,dx+tx+1,ax[i][j])-dx;
			ay[i][j]=lower_bound(dy+1,dy+ty+1,ay[i][j])-dy;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			t++;
			c[t].x1=min(min(ax[i][j],ax[i][j-1]),min(ax[i-1][j],ax[i-1][j-1]));
			c[t].x2=max(max(ax[i][j],ax[i][j-1]),max(ax[i-1][j],ax[i-1][j-1]));
			c[t].y1=min(min(ay[i][j],ay[i][j-1]),min(ay[i-1][j],ay[i-1][j-1]));
			c[t].y2=max(max(ay[i][j],ay[i][j-1]),max(ay[i-1][j],ay[i-1][j-1]));
			c[t].v=a[i][j];
		}
	sort(c+1,c+t+1,cmp);
	ll ans=0;
	for(int i=1;i<=t;i++)
	{
		int s=seg::query(1,c[i].y1,c[i].y2-1,1,ty);
		if(s<c[i].v)
		{
			ans+=c[i].v-s;
			seg::add(1,c[i].y1,c[i].y2-1,c[i].v,1,ty);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}