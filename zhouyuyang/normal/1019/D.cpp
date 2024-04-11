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

struct P{
	int x,y;
	P operator +(const P &a)const{
		return (P){x+a.x,y+a.y};
	}
	P operator -(const P &a)const{
		return (P){x-a.x,y-a.y};
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
	ll operator ^(const P &a)const{
		return 1ll*x*a.x+1ll*y*a.y;
	}
}p[2005];
P up=(P){1,(int)(1e9+7)};
P ri=(P){(int)(1e9+7),-1};
bool cmp(const P &a,const P &b){
	return (a^up)<(b^up);
}
struct que{
	P d; int x,y;
}q[2000000];
int n,tot;
ll S;
bool cmp2(const que &a,const que &b){
	return a.d*b.d>0;
}
int rk[2005],pos[2005];
void chk(const P a,const P b,int l,int r,ll aim){
	for (int mid;l<=r;){
		mid=(l+r)>>1;
		ll del=a*(p[pos[mid]]-b);
		if (del==aim){
			P A=p[pos[mid]],B=b,C=B+a;
			printf("Yes\n%d %d\n%d %d\n%d %d",A.x,A.y,B.x,B.y,C.x,C.y);
			exit(0);
		}
		del<aim?l=mid+1:r=mid-1;
	}
}
int main(){
	scanf("%d%lld",&n,&S); S*=2;
	for (int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+n+1,cmp);
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++){
			static P del; del=p[j]-p[i];
			if (ri*del>0) q[++tot]=(que){del,i,j};
			else q[++tot]=(que){(P){-del.x,-del.y},j,i};
		}
	for (int i=1;i<=n;i++) pos[i]=rk[i]=i;
	sort(q+1,q+tot+1,cmp2);
	for (int i=1;i<=tot;i++){
		static que Q; Q=q[i];
		chk(Q.d,p[Q.x],max(rk[Q.x],rk[Q.y])+1,n,S);
		chk(Q.d,p[Q.x],1,min(rk[Q.x],rk[Q.y])-1,S);
		swap(rk[Q.x],rk[Q.y]);
		pos[rk[Q.x]]=Q.x;
		pos[rk[Q.y]]=Q.y;
	}
	puts("No");
}