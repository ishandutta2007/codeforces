#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;

const int N=200005;
int n,s,t,ans,a[N];
int p[N],fa[N];
pii b[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
bool vis[N];
vector<int> c[N];
void dfs(int x){
	vis[x]=1; c[t].PB(x);
	if (!vis[p[x]]) dfs(p[x]);
}
int main(){
	scanf("%d%d",&n,&s);
	For(i,1,n){
		scanf("%d",&a[i]);
		b[i]=pii(a[i],i);
	}
	sort(b+1,b+n+1);
	For(i,1,n) p[b[i].se]=i;
	For(i,1,n)
		if (a[i]==b[i].fi&&p[i]!=i){
			p[b[i].se]=p[i];
			b[p[i]].se=b[i].se;
			p[i]=b[i].se=i;
		}
	For(i,1,n) fa[i]=i;
	For(i,1,n) fa[get(i)]=get(p[i]);
	int las=-1;
	For(i,0,n){
		if (p[b[i].se]==b[i].se) continue;
		if (las>=0&&a[las]==a[b[i].se]){
			int x=las,y=b[i].se;
			int X=get(x),Y=get(y);
			if (X!=Y) fa[X]=Y,swap(p[x],p[y]);
		}
		las=b[i].se;
	}
	For(i,1,n)
		if (!vis[i]&&p[i]!=i)
			++t,dfs(i);
	For(i,1,t) ans+=c[i].size();
	if (ans>s)
		return puts("-1"),0;
	s=min(s-ans,t);
	if (s<=1){
		printf("%d\n",t);
		For(i,1,t){
			printf("%d\n",c[i].size());
			For(j,0,c[i].size()-1)
				printf("%d ",c[i][j]);
			puts("");
		}
		return 0;
	}
	printf("%d\n",t-s+2);
	For(i,1,t-s){
		printf("%d\n",c[i+s].size());
		For(j,0,c[i+s].size()-1)
			printf("%d ",c[i+s][j]);
		puts("");
		ans-=c[i+s].size();
	}
	printf("%d\n",ans);
	For(i,1,s)
		For(j,0,c[i].size()-1)
			printf("%d ",c[i][j]);
	printf("\n%d\n",s);
	Rep(i,s,1)
		printf("%d ",c[i][0]);
}