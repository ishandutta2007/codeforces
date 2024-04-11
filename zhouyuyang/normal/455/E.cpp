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
#define INF (1ll<<60)
using namespace std;
const int N=100005;
int a[N],n,Q;
ll s[N],ans[N];
int qq[N],st[N],tp;
struct query{
	int x,y,id;
	bool operator <(const query &a)const{
		return x<a.x;
	}
}q[N];
ll calc(int x,int y,int v){
	return s[x]-s[v]+1ll*(y+v)*a[v];
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	scanf("%d",&Q);
	For(i,1,Q){
		scanf("%d%d",&q[i].y,&q[i].x);
		q[i].id=i;
	}
	sort(q+1,q+Q+1);
	qq[0]=1<<30;
	int pos=1;
	For(i,1,n){
		for (;tp&&calc(i,qq[tp-1]+1,st[tp])
				>=calc(i,qq[tp-1]+1,i);tp--);
		if (tp){
			int l=qq[tp],r=qq[tp-1]+1;
			while (l<r){
				int mid=(l+r)>>1;
				if (calc(i,mid,st[tp])<calc(i,mid,i)) r=mid;
				else l=mid+1;
			}
			qq[tp]=l;
		}
		st[++tp]=i; qq[tp]=1-i;
		for (;pos<=Q&&q[pos].x==i;pos++){
			int l=1,r=tp;
			while (l<r){
				int mid=(l+r)>>1;
				if (qq[mid]<=q[pos].y-i) r=mid;
				else l=mid+1;
			}
			ans[q[pos].id]=calc(i,q[pos].y-i,st[l]);
		}
	}
	For(i,1,Q) printf("%lld\n",ans[i]);
}