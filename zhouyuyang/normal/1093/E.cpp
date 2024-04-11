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
 
#define inf 1<<30
#define sqr(x) ((x)*(x))
using namespace std;
const int N=200005;
int a[N],b[N],pos[N],val[N];
int n,Q,cnt,blk,v[205][1005];
void build(int id){
	int L=(id-1)*blk+1,R=min(n,id*blk);
	For(i,L,R) v[id][i-L+1]=val[i];
	sort(v[id]+1,v[id]+(R-L+1)+1);
}
int bf1(int l,int r,int L,int R){
	int ans=0;
	For(i,l,r) ans+=(val[i]>=L&&val[i]<=R);
	return ans;
}
int bf2(int id,int l,int r){
	int L=(id-1)*blk+1,R=min(n,id*blk);
	int lp=lower_bound(v[id]+1,v[id]+(R-L+1)+1,l)-v[id];
	int rp=lower_bound(v[id]+1,v[id]+(R-L+1)+1,r+1)-v[id]-1;
	return rp-lp+1;
}
void chg(int id,int v1,int v2){
	int L=(id-1)*blk+1,R=min(n,id*blk);
	For(i,1,R-L+1) if (v[id][i]==v1){
		v[id][i]=1<<30; break;
	}
	For(i,1,R-L) if (v[id][i+1]<v[id][i])
		swap(v[id][i+1],v[id][i]);
	v[id][R-L+1]=v2;
	Rep(i,R-L,1) if (v[id][i+1]<v[id][i])
		swap(v[id][i+1],v[id][i]);
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]),pos[a[i]]=i;
	For(i,1,n) scanf("%d",&b[i]),val[pos[b[i]]]=i;
	blk=1000; cnt=(n-1)/blk+1;
	For(i,1,cnt) build(i);
	while (Q--){
		int tp;
		scanf("%d",&tp);
		if (tp==1){
			int l,r,L,R,ans=0;
			scanf("%d%d%d%d",&l,&r,&L,&R);
			int bl=(l-1)/blk+1,br=(r-1)/blk+1;
			if (bl==br) ans+=bf1(l,r,L,R);
			else{
				ans=bf1(l,bl*blk,L,R)+bf1((br-1)*blk+1,r,L,R);
				For(i,bl+1,br-1) ans+=bf2(i,L,R);
			}
			printf("%d\n",ans);
		}
		else{
			int x,y;
			scanf("%d%d",&x,&y);
			int px=pos[b[x]],py=pos[b[y]];
			int bx=(px-1)/blk+1,by=(py-1)/blk+1;
			chg(bx,x,y); chg(by,y,x);
			val[px]=y; val[py]=x;
			swap(b[x],b[y]);
		}
	}
}