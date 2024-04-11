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

struct P{
	int x,y;
	P(){}
	P(int _x,int _y){
		x=_x; y=_y;
	}
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
	ll dis()const{
		return 1ll*x*x+1ll*y*y;
	}
	bool operator <(const P &a)const{
		return x!=a.x?x<a.x:y<a.y;
	}
}tmp;
bool LEFT(const P &a,const P &b){
	return a*b<0; 
}
bool cmp(const P &a,const P &b){
	return a*b==0?a.dis()<b.dis():LEFT(b,a);
}
const int N=100005;
struct convex{
	P a[N];
	P con[N];
	int n;
	void init(ll *res){
		for (int i=1;i<=n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		for (int i=2;i<=n;i++)
			if (a[i]<a[1]) swap(a[1],a[i]);
		for (int i=2;i<=n;i++) a[i]=a[i]-a[1];
		sort(a+2,a+n+1,cmp);
		for (int i=2;i<=n;i++) a[i]=a[i]+a[1];
		int t=0; con[0]=P(0,0);
		for (int i=1;i<=n;i++){
			for (;t>=2&&!LEFT(a[i]-con[t],con[t]-con[t-1]);t--);
			con[++t]=a[i];
		}
		con[0]=con[t];
		con[++t]=con[1];
		con[t+1]=con[2];
		for (int i=1;i<t;i++){
			res[++*res]=(con[i]-con[i-1]).dis();
			res[++*res]=(con[i]-con[i-1])^(con[i+1]-con[i]);
		}
	}	
}A,B;
ll S[N*4],T[N*4];
int nxt[N*4];
bool KMP(ll *A,ll *B){
	int tmp=*A;
	for (int i=1;i<=tmp;i++) A[++*A]=A[i];
	for (int i=2,j=1;i<=*B;i++){
		for (;j>1&&B[i]!=B[j];j=nxt[j-1]+1);
		nxt[i]=((j+=(B[i]==B[j]))-1);
	}
	for (int i=1,j=1;i<=*A;i++){
		for (;j>1&&(j>*B||A[i]!=B[j]);j=nxt[j-1]+1);
		if ((j+=(A[i]==B[j]))>*B) return 1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&A.n,&B.n);
	A.init(S); B.init(T);
	puts(KMP(T,S)?"YES":"NO");
}