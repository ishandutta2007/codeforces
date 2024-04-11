#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
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


const int mo[2]={998244353,1000000007};
pll operator +(const pll &a,const pll &b){
	return pll((a.fi+1ll*b.fi*b.fi+19260817)%mo[0],(a.se+1ll*b.se*b.se+18931226)%mo[1]);
}
pll operator -(const pll &a,const pll &b){
	return pll((a.fi+2ll*mo[0]-1ll*b.fi*b.fi%mo[0]-19260817)%mo[0],
			   (a.se+2ll*mo[1]-1ll*b.se*b.se%mo[1]-18931226)%mo[1]);
}


struct edge{
	int to,next;
};
const int N=105;
bool GG; int n;
struct forest{
	edge e[N*2];
	int head[N],tot;
	int fa[N],m,vis[N];
	pll hsh[N],fhsh[N];
	void clear(){
		memset(head,0,sizeof(head));
		tot=0;
	}
	int get(int x){
		return x==fa[x]?x:fa[x]=get(fa[x]);
	}
	void add(int x,int y){
		e[++tot]=(edge){y,head[x]};
		head[x]=tot;
		e[++tot]=(edge){x,head[y]};
		head[y]=tot;
	}
	
	void init(){
		clear();
		For(i,1,n) fa[i]=i;
		scanf("%d",&m);
		For(i,1,m){
			int x,y;
			scanf("%d%d",&x,&y);
			if (get(x)!=get(y))
				fa[get(x)]=get(y);
			else GG=1;
			add(x,y);
		}
		int tmp=0;
		For(i,1,n) tmp+=(head[i]!=0);
		if (tmp==n) GG=1;
	}
	
	
	void dfs1(int x,int fa){
		hsh[x]=(pll){459,47293};
		vis[x]=1;
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa){
				dfs1(e[i].to,x);
				hsh[x]=hsh[x]+hsh[e[i].to];
			}
	}
	void dfs2(int x,int fa){
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa){
				hsh[e[i].to]=hsh[e[i].to]+(hsh[x]-hsh[e[i].to]);
				dfs2(e[i].to,x);
			}
	}
	pll calc(){
		memset(vis,0,sizeof(vis));
		For(i,1,n)
			if (!vis[i]&&head[i]){
				dfs1(i,0);
				dfs2(i,0);
			}
		pll ans(0,0);
		For(i,1,n) if (head[i]){
			ans.fi=(ans.fi+hsh[i].fi)%mo[1];
			ans.se=(ans.se+hsh[i].se)%mo[1];
		}
		return ans;
	}
	
	void output(){
		For(i,1,n)
			for (int j=head[i];j;j=e[j].next)
				if (i<e[j].to)
					printf("%d %d\n",i,e[j].to);
	}
}f[N];


vector<pll > A,B;
void solve(){
	A.clear();
	int spe=GG=0;
	scanf("%d%*d",&n);
	For(i,1,n){
		f[i].init();
		if (!spe&&f[i].m==n-2) spe=i;
	}
	if (GG||!spe){
		puts("NO");
		return;
	}
	For(i,1,n)
		A.PB(f[i].calc());
	sort(A.begin(),A.end());
	int p=1;
	for (;;p++)
		if (!f[spe].head[p])
			break;
	For(i,1,n) if (i!=p){
		B.clear();
		forest tr=f[spe],G;
		tr.add(i,p);
		For(j,1,n){
			G.clear();
			For(x,1,n) if (x!=j)
				for (int k=tr.head[x];k;k=tr.e[k].next)
					if (tr.e[k].to!=j&&x<tr.e[k].to)
						G.add(x,tr.e[k].to);
			B.push_back(G.calc());
		}
		sort(B.begin(),B.end());
		if (A==B){
			puts("YES");
			tr.output();
			return;
		}
	}
	puts("NO");
}
int main(){
	int T; scanf("%d",&T);
	while (T--) solve();
}