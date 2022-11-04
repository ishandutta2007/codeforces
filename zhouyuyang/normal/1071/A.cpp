#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1<<29)
using namespace std;
int n,m,fl;
int a[233333],b[233333];
bool vis[233333];
void check(int lim){
	if (1ll*lim*(lim+1)/2>n+m) return;
	int n1=n;
	*a=*b=0;
	for (int i=lim;i>=1;i--)
		if (n1>=i) a[++*a]=i,n1-=i,vis[i]=1;
	for (int i=lim;i;i--)
		if (!vis[i]) b[++*b]=i;
	if (fl) swap(a,b);
	printf("%d\n",*a);
	For(i,1,*a) printf("%d ",a[i]);
	printf("\n%d\n",*b);
	For(i,1,*b) printf("%d ",b[i]);
	exit(0); 
}
int main(){
	scanf("%d%d",&n,&m);
	if (n>m) swap(n,m),fl=1;
	for (int i=100000;i>=0;i--) check(i);
}