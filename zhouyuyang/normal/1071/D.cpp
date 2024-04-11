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
const int N=1000005;
int mn[N],pri[N],equ[N];
int F(int x,vector<int> &v){
	v.clear();
	for (;x!=1;){
		int p=mn[x],cnt=0;
		for (;x%p==0;x/=p,cnt++);
		v.PB(cnt);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	vector<int> V=v;
	int ans=1;
	For(i,0,v.size()-1)
		for (;V[i]--;ans*=pri[i+1]);
	return ans;
}
const int M=1005;
int dis[300][M],id[N],cnt;
int f[M],g[M];
void work(int *ans,vector<int> &v){
	for (;v.size()<25;v.PB(0));
	CLR(f,10); f[1]=0;
	for (auto i:v){
		CLR(g,10);
		For(j,0,24) Rep(k,1000/(j+1),1)
			g[k*(j+1)]=min(g[k*(j+1)],f[k]+abs(i-j));
		swap(f,g); 
	}
	For(i,1,1000) ans[i]=f[i];
}
int main(){
	For(i,2,N-1) if (!mn[i]){
		mn[i]=i; pri[++*pri]=i;
		For(j,2,(N-1)/i) if (!mn[i*j]) mn[i*j]=i;
	}
	vector<int> v;
	For(i,1,N-1){
		equ[i]=F(i,v);
		if (equ[i]==i){
			id[i]=++cnt;
			work(dis[cnt],v);
		}
	}
	int Q; scanf("%d",&Q);
	while (Q--){
		int x,y,ans=(1ll<<30); scanf("%d%d",&x,&y);
		x=id[equ[x]]; y=id[equ[y]];
		For(i,1,1000) ans=min(ans,dis[x][i]+dis[y][i]);
		printf("%d\n",ans);
	}
}