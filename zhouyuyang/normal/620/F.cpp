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
const int N=50005;
int ch[N*22][2],nd;
int a[N],val[N],que[N],res[N];
int n,Q,S,blk,f[N*20];
int L[N],R[N],lg[N];
int st[105][16][N];
pii q[N*2];
void insert(int v){
	int x=1;
	for (int val=1<<19;val;val>>=1){
		int fl=((v&val)!=0);
		if (!ch[x][fl]) ch[x][fl]=++nd;
		x=ch[x][fl];
	}
}
int find(int v){
	int x=1,ans=0;
	if (!ch[x][0]&&!ch[x][1]) return 0;
	for (int val=1<<19;val;val>>=1){
		int fl=((v&val)==0);
		if (!ch[x][fl]) x=ch[x][fl^1];
		else ans+=val,x=ch[x][fl];
	}
	return ans;
}
void work(){
	int top=0; nd=1;
	For(i,1,*val) q[++top]=pii(a[val[i]],i);
	For(i,1,*que) q[++top]=pii(a[que[i]],-1);
	sort(q+1,q+top+1);
	For(i,1,top)
		if (q[i].se==-1) insert(f[q[i].fi-1]);
		else res[q[i].se]=find(f[q[i].fi]);
	for (;nd;nd--) ch[nd][0]=ch[nd][1]=0;
	nd=1;
	Rep(i,top,1)
		if (q[i].se==-1) insert(f[q[i].fi]);
		else res[q[i].se]=max(res[q[i].se],find(f[q[i].fi-1]));
	for (;nd;nd--) ch[nd][0]=ch[nd][1]=0;
}
int main(){
	For(i,1,1000000) f[i]=f[i-1]^i;
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,2,n) lg[i]=lg[i/2]+1;
	S=1000; blk=(n-1)/S+1;
	For(i,1,blk) L[i]=R[i-1]+1,R[i]=min(n,i*S);
	For(i,1,blk){
		*val=*que=0;
		For(j,1,n) val[++*val]=j;
		For(j,L[i],R[i]) que[++*que]=j;
		work();
		For(j,1,n) st[i][0][j]=res[j];
		For(j,1,15) For(k,1,n-(1<<j)+1)
			st[i][j][k]=max(st[i][j-1][k],st[i][j-1][k+(1<<(j-1))]);
	}
	while (Q--){
		int l,r,bl,br;
		scanf("%d%d",&l,&r);
		if (l+S>=r){
			*val=*que=0;
			For(j,l,r) val[++*val]=que[++*que]=j;
			work(); int ans=0;
			For(j,1,*val) ans=max(ans,res[j]);
			printf("%d\n",ans);
		}
		else{
			bl=(l-1)/S+1,br=(r-1)/S+1;
			int k=lg[r-l+1],ans=0;
			For(i,bl+1,br-1){
				ans=max(ans,st[i][k][l]);
				ans=max(ans,st[i][k][r-(1<<k)+1]);
			}
			*val=*que=0;
			For(j,l,R[bl]) val[++*val]=que[++*que]=j;
			For(j,L[br],r) val[++*val]=que[++*que]=j;
			work();
			For(j,1,*val) ans=max(ans,res[j]);
			printf("%d\n",ans);
		}
	}
}
/*
O(NSlog+MS+M(N/S)log)
*/