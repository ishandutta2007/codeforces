#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint ungigned
#define db long double
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
using namespace std;
const int N=30005,K=205;
int a[K][N],q[K][N];
int vis[N],pre[N];
vector<pii> vec[N];
int n,k,id[N];
void GG(){
	puts("-1");
	exit(0);
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,k) For(j,1,n){
		scanf("%d",&a[i][j]);
		if (!a[i][j]) id[i]=j;
	}
	For(i,1,k) if (!id[i]) GG();
	For(i,2,k){
		For(j,1,n)
			if (a[1][j]+a[i][j]==a[1][id[i]])
				q[i][a[1][j]]=j,vis[j]=1;
		Rep(j,a[1][id[i]],1){
			if (!q[i][j]) break;
			pre[q[i][j]]=q[i][j-1];
		}
	}
	vis[id[1]]=1;
	For(i,1,n) if (!vis[i]){
		int at=id[1],mn=0;
		For(j,2,k){
			int v=(a[1][id[j]]+a[1][i]-a[j][i])/2;
			if (v>=mn) mn=v,at=q[j][v];
		}
		vec[at].push_back(pii(a[1][i],i)); 
	}
	For(j,1,n){
		sort(vec[j].begin(),vec[j].end());
		for (int i=0,la=a[1][j],cur=j;i<vec[j].size();){
			if ((++la)!=vec[j][i].fi) GG();
			for (;i<vec[j].size()-1&&vec[j][i+1].fi==la;)
				pre[vec[j][i++].se]=cur;
			pre[vec[j][i].se]=cur;
			cur=vec[j][i++].se;
		}
	}
	For(i,1,n)
		if (pre[i]) printf("%d %d\n",i,pre[i]);
}