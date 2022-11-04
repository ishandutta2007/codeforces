#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
#define fi first
#define se second
#define BG begin
#define ED end

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

#define INF (1<<29)
#define sqr(x) ((x)*(x))
#define eps (1e-7)
using namespace std;
const int N=1005;
struct que{
	double x; int v;
	bool operator <(const que &a)const{
		if (abs(x-a.x)>eps)
			return x<a.x;
		return v<a.v;
	}
}q[N*2];
int n,m;
double x[N],y[N],r[N];
int calc(double ang){
	double X=sin(ang),Y=cos(ang);
	int tot=0;
	For(i,1,n){
		double val=-x[i]*X+y[i]*Y;
		q[++tot]=(que){val-r[i],1};
		q[++tot]=(que){val+r[i],-1};
	}
	sort(q+1,q+tot+1);
	int tmp=0,ans=0;
	For(i,1,tot)
		ans=max(ans,tmp+=q[i].v);
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
	double st=0,ed=2*acos(-1),step=0.0005;
	int ans=0;
	for (;step>eps;step/=5){
		int mx=0; double at;
		for (double i=st;i<ed;i+=step){
			int now=calc(i);
			if (now>mx) mx=now,at=i;
		}
		st=at-5*step;
		ed=at+5*step;
		ans=max(ans,mx);
	}
	printf("%lld\n",1ll*m*(m+1)/2+n+1ll*ans*m-m);
}