#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define PQ priority_queue
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
#define fi first
#define se second
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(j);i<=(int)k;i++)
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1ll<<61)
#define sqr(x) (1ll*(x)*(x))
#define pbi pair<bool,unsigned short>
using namespace std;

const int N=1005;
int n,k,x[N],y[N];
int D[N*N],dis[N][N];
int cnt,vis[N];
vector<int> e[N];
bool dfs(int x,int cnt){
	if (x>n) return 1;
	if (vis[x]) return dfs(x+1,cnt);
	for (auto i:e[x]) cnt-=!(vis[i]++);
	if (cnt>=0&&dfs(x+1,cnt)) return 1;
	vis[x]=1; int t=cnt;
	for (auto i:e[x]) cnt+=(!--vis[i]);
	if ((--cnt)>=0&&cnt>t&&dfs(x+1,cnt)) return 1;
	vis[x]=0; return 0;
}
bool check(int mid){
	For(i,1,n) vis[i]=0,e[i].resize(0);
	For(i,1,n) For(j,1,n)
		if (dis[i][j]>mid) e[i].PB(j);
	return dfs(1,k);
} 
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	For(i,1,n) For(j,i+1,n) D[++*D]=dis[i][j]=(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
	sort(D+1,D+*D+1); D[++*D]=2147480000;
	int l=1,r=*D,ans;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(D[mid])) ans=mid,r=mid-1;
		else l=mid+1;
	}
	check(D[ans]);
	For(i,1,n) if (vis[i]) printf("%d ",i),k--;
	For(i,1,n) if (!vis[i]&&k) printf("%d ",i),k--;
}