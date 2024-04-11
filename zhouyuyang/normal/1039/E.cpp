#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
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
const int N=100005;
int n,w,Q,B,x[N];
int st[18][N][2];
int nxt[N],mv[N][2];
int f[N][2],ans[N],tot;
struct que{
	int id,k;
	bool operator <(const que &a)const{
		if (k!=a.k)
			return k<a.k;
		return id>a.id;
	}
}q[N*50];
void upd(int id){
	int las=(id-1)/B*B+B;
	if (nxt[id]>n||nxt[id]>las)
		f[id][0]=1,f[id][1]=id;
	else f[id][0]=f[nxt[id]][0]+1,
		 f[id][1]=f[nxt[id]][1];
}
int main(){
	scanf("%d%d%d",&n,&w,&Q);
	For(i,1,n){
		scanf("%d",&x[i]);
		st[0][i][0]=st[0][i][1]=x[i];
	}
	For(k,1,16) For(i,1,n-(1<<k)+1)
		st[k][i][0]=min(st[k-1][i][0],st[k-1][i+(1<<(k-1))][0]),
		st[k][i][1]=max(st[k-1][i][1],st[k-1][i+(1<<(k-1))][1]);
	for (;B*B*B<6*n;B++);
	for (int i=n;i;i--){
		nxt[i]=i+1;
		mv[i][0]=mv[i][1]=x[i];
		int mn=x[i],mx=x[i]; upd(i);
		for (int j=i+1;j<=n&&(j-1)%B;j++){
			mn=min(mn,x[j]);
			mx=max(mx,x[j]);
			q[++tot]=(que){i,mx-mn};
		}
	}
	For(i,1,Q){
		int x; scanf("%d",&x);
		q[++tot]=(que){-i,w-x};
	}
	sort(q+1,q+tot+1);
	int cnt=0;
	for (int i=1;i<=tot;i++)
		if (q[i].id<0){
			int j=1,s=-1;
			for (;j<=n;){
				s+=f[j][0]; j=f[j][1];
				if (j>n) break;
				int mn=mv[j][0],mx=mv[j][1];
				int mn2,mx2,k=0,l=nxt[j];
				for (;l+(1<<k)-1<=n;k++){
					mx2=max(mx,st[k][l][1]);
					mn2=min(mn,st[k][l][0]);
					if (mx2-mn2>q[i].k) break;
					mn=mn2,mx=mx2;
				}
				for (k--;k>=0;k--)
					if (l+(1<<k)-1<=n){
						mx2=max(mx,st[k][l][1]);
						mn2=min(mn,st[k][l][0]);
						if (mx2-mn2>q[i].k) continue;
						mn=mn2,mx=mx2; l+=(1<<k);
					}
				mv[j][0]=mn;
				mv[j][1]=mx;
				nxt[j]=l; j=l;
			}
			ans[-q[i].id]=s;
		}
		else{
			int j=q[i].id,be=(j-1)/B*B+1;
			mv[j][0]=min(mv[j][0],x[nxt[j]]);
			mv[j][1]=max(mv[j][1],x[nxt[j]]); 
			for (nxt[j]++;j>=be;j--) upd(j);
		}
	For(i,1,Q)
		printf("%d\n",ans[i]); 
}