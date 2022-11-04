#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint ungigned
#define db double
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
#define pdd pair<double,double>
struct mat{
	double a[3][3];
	mat(){
		For(i,0,2) For(j,0,2)
			a[i][j]=0;
	}
	mat operator *(const mat &b)const{
		mat c;
		For(i,0,2) For(j,0,2) For(k,0,2)
			c.a[i][j]+=a[i][k]*b.a[k][j];
		return c;
	}
};
struct node{
	int id;
	ll las;
	mat pre;
};
vector<node> S;
mat bas[100005],f[40],org;
pdd p[100005];
int n;
ll m;
double b;
int main(){
	scanf("%d%lld",&n,&m);
	For(i,1,n){
		db x,y,v;
		scanf("%lf%lf%lf",&x,&y,&v);
		b=max(b,y*v);
		p[i]=pdd(x*v,v);
	}
	sort(p+1,p+n+1,greater<pdd>());
	org.a[2][0]=1;
	For(i,1,n){
		bas[i].a[1][1]=1;
		bas[i].a[2][2]=1;
		bas[i].a[0][0]=1-p[i].se;
		bas[i].a[0][1]=p[i].se;
		bas[i].a[0][2]=p[i].fi;
		bas[i].a[1][2]=b;
	}
	S.push_back((node){1,m,org});
	For(i,2,n){
		for (;;)
			if ((bas[i]*S.back().pre).a[0][0]>
				(bas[S.back().id]*S.back().pre).a[0][0])
					S.pop_back();
			else break;
		if (!S.back().las) continue;
		node tmp=S.back();
		f[0]=bas[tmp.id];
		For(j,1,35) f[j]=f[j-1]*f[j-1];
		Rep(j,35,0)
			if (tmp.las-(1ll<<j)>=1)
				if ((bas[i]*f[j]*tmp.pre).a[0][0]<=
					(bas[tmp.id]*f[j]*tmp.pre).a[0][0]){
						tmp.pre=f[j]*tmp.pre;
						tmp.las-=(1ll<<j);
					}
		tmp.pre=f[0]*tmp.pre;
		--tmp.las;
		if (tmp.las) tmp.id=i;
		S.push_back(tmp);
	}
	int id=S.back().id;
	ll las=S.back().las;
	mat ans=S.back().pre,x=bas[id];
	for (;las;las/=2,x=x*x)
		if (las&1) ans=x*ans;
	printf("%.15lf\n",ans.a[0][0]);
}