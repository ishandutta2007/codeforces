#include <cstdio>
#include <cctype>
#include <iostream>
#define re register
#define ll long long
#define y1 y1____
#define abs(x) ((x)>0?(x):-(x))
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int MAXN=1e3+1;
struct Edge{
	int to,nxt;
	ll dat;
}e[MAXN<<1];
int cnt,head[MAXN];
bool vis[MAXN];
inline void add_e(int from,int to,ll dat){
	e[++cnt].to=to,e[cnt].dat=dat;
	e[cnt].nxt=head[from],head[from]=cnt;
}
ll dist(ll x1,ll y1,ll x2,ll y2){
	return abs(x1-x2)+abs(y1-y2);
}
struct Sp{
	ll x,y;
}a[100];
int n,ans,now;
bool flg=0;
void dfs(int x,int sum,ll t){
	if(x>n || t<0)return;
	vis[x]=1;
	if(sum>ans)ans=sum;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;ll dat=e[i].dat;
		if(vis[y])continue;
		if(!flg && y>x)continue;
		dfs(y,sum+1,t-dat);
	}
	if(x==1)flg=1,dfs(now+1,sum+1,t-dist(a[1].x,a[1].y,a[now+1].x,a[now+1].y)),flg=0;
	vis[x]=0;
}
ll ax,ay,bx,by,xs,ys,t;
int main(){
	a[1].x=read(),a[1].y=read(),ax=read(),ay=read(),bx=read(),by=read();
	xs=read(),ys=read(),t=read();
	for(n=2;;n++){
		a[n].x=ax*a[n-1].x+bx;
		a[n].y=ay*a[n-1].y+by;
		if(a[n].x>2e16 || a[n].y>2e16){n--;break;}
	}
	for(re int i=n-1;i;i--){
		ll dat=dist(a[i].x,a[i].y,a[i+1].x,a[i+1].y);
		add_e(i,i+1,dat),add_e(i+1,i,dat);
	}
	for(re int i=1;i<=n;i++){
		ll dat=dist(a[i].x,a[i].y,xs,ys);
		now=i;dfs(i,1,t-dat);
	}
	printf("%d\n",ans);
	return 0;
}