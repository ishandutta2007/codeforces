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
#define PQ priority_queue
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
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i++)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

using namespace std;

const int N=200005;
const int lim=314000000;
int w[N],p[N],A[N],B[N];
int aim[N],c[N],pd[N],e[N],n,m;
vi b[N],x[N],d[N];
PQ<pii > Q;
bool upd(int k1,int k2){
	if (A[k1]==-1||A[k1]>k2)
		return A[k1]=k2,1;
	return 0;
}
int dfs(int k){
	if (pd[k]) return B[k]=-2;
	if (B[k]) return B[k];
	pd[k]=1;
	For(i,0,x[k].size()-1){
		int j=x[k][i];
		if (c[j]) continue;
		int num=e[j];
		For(k1,0,d[j].size()-1){
			int k2=dfs(d[j][k1]);
			if (k2==-2){
				pd[k]=0;
				return B[k]=-2;
			}
			num=min(num+k2,lim);
		}
		B[k]=max(B[k],num);
	}
	pd[k]=0;
	return B[k];
}
int main(){
	scanf("%d%d",&m,&n);
	For(i,1,m){
		int v; scanf("%d",&v);
		x[v].PB(i); aim[i]=v;
		scanf("%d",&v);
		For(j,1,v){
			int x;
			scanf("%d",&x);
			if (x==-1) w[i]++;
			else{
				c[i]++;
				b[x].PB(i);
				d[i].PB(x);
			}
		}
	}
	CLR(A,0xff); CPY(e,w);
	for (int i=1;i<=m;i++)
		if (!c[i]&&upd(aim[i],w[i]))
			Q.push(pii(-A[aim[i]],aim[i]));
	while (!Q.empty()){
		int x=Q.top().se; Q.pop();
		if (pd[x]) continue; pd[x]=1;
		For(i,0,b[x].size()-1){
			int j=b[x][i]; c[j]--;
			w[j]=min(w[j]+A[x],lim);
			if (!c[j]&&upd(aim[j],w[j]))
				Q.push(pii(-A[aim[j]],aim[j]));
		}
	}
	CLR(pd,0); CLR(B,0); CLR(c,0);
	For(i,1,n) if (A[i]==-1)
		For(j,0,b[i].size()-1)
			c[b[i][j]]=1;
	For(i,1,n)
		if (A[i]>=0) dfs(i);
		else B[i]=-1;
	For(i,1,n) printf("%d %d\n",A[i],B[i]);
}