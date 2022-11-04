#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
#define INF (1ll<<60)
using namespace std;
const int N=100005;
char s[N];
int ch[N*32][4];
int nd,n;
ll wzp;
struct Mat{
	ll a[4][4];
	Mat(){
		memset(a,0,sizeof(a));
	}
	Mat operator *(const Mat &b)const{
		Mat c;
		For(i,0,3) For(j,0,3){
			c.a[i][j]=INF;
			For(k,0,3) c.a[i][j]=min(c.a[i][j],a[i][k]+b.a[k][j]);
		}
		return c;
	}
}p[66];
void dfs(int x,int s,int d){
	For(i,0,3)
		if (ch[x][i]) dfs(ch[x][i],s,d+1);
		else p[0].a[s][i]=min(p[0].a[s][i],1ll*d);
}
bool check(Mat x,ll v){
	For(i,0,3) For(j,0,3)
		if (x.a[i][j]<=v) return 1;
	return 0;
}
int main(){
	scanf("%lld%s",&wzp,s+1);
	n=strlen(s+1);
	For(i,1,n) s[i]-='A';
	For(i,1,n){
		int x=0;
		For(j,i,min(i+30,n)){
			if (!ch[x][s[j]])
				ch[x][s[j]]=++nd;
			x=ch[x][s[j]];
		}
	}
	For(i,0,3) For(j,0,3)
		p[0].a[i][j]=INF;
	For(i,0,3) if (ch[0][i])
		dfs(ch[0][i],i,1);
	int tp=0;
	for (;;){
		p[tp+1]=p[tp]*p[tp];
		if (!check(p[tp+1],wzp)) break;
		tp++;
	}
	Mat x,y;
	ll ans=0;
	for (;tp>=0;tp--)
		if (check(y=x*p[tp],wzp-1))
			ans+=(1ll<<tp),x=y;
	printf("%lld\n",ans+1);
}