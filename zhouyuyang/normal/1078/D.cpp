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
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);++i)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);--i)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define inf 0x3f3f3f3f
using namespace std;
const int N=300005;
struct seg{
	int v[N*4],tp;
	void build(int k,int l,int r,int *a){
		if (l==r) return v[k]=a[l],void(0);
		int mid=(l+r)/2;
		build(k*2,l,mid,a); build(k*2+1,mid+1,r,a);
		v[k]=(tp?min(v[k*2],v[k*2+1]):max(v[k*2],v[k*2+1]));
	}
	int ask(int k,int l,int r,int x,int y){
		if (l==x&&r==y) return v[k];
		int mid=(l+r)/2;
		if (y<=mid) return ask(k*2,l,mid,x,y);
		if (x>mid) return ask(k*2+1,mid+1,r,x,y);
		return tp?min(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y)):
				  max(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
	}
}mn[20],mx[20];
int r[N],n,id[N];
int L[20][N];
int R[20][N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&r[i]),r[i+n]=r[i+n+n]=r[i];
	For(i,1,3*n) L[0][i]=max(i-r[i],1),R[0][i]=min(i+r[i],3*n);
	For(i,1,18){
		mn[i-1].tp=1; mx[i-1].tp=0;
		mn[i-1].build(1,1,3*n,L[i-1]);
		mx[i-1].build(1,1,3*n,R[i-1]);
		For(j,1,3*n){
			L[i][j]=mn[i-1].ask(1,1,3*n,L[i-1][j],R[i-1][j]);
			R[i][j]=mx[i-1].ask(1,1,3*n,L[i-1][j],R[i-1][j]);
		}
	}
	mn[18].tp=1; mx[18].tp=0;
	mn[18].build(1,1,3*n,L[18]);
	mx[18].build(1,1,3*n,R[18]);
	For(i,1,n){
		int l=n+i,r=n+i,ans=0;
		Rep(j,18,0){
			int L=mn[j].ask(1,1,3*n,l,r);
			int R=mx[j].ask(1,1,3*n,l,r);
			if (R-L+1<n)
				l=L,r=R,ans+=(1<<j);
		}
		printf("%d ",ans+((r-l+1)<n));
	}
}