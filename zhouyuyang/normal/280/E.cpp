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

#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int N=6005;
typedef pair<double,double> data;
int n,q,a,b,tot,k;
double x[N],tmp,ans[N],sum;
data c[N*2];
int main(){
	scanf("%d%d%d%d",&n,&q,&a,&b);
	For(i,1,n){
		scanf("%lf",&x[i]);
		if (i==1){
			c[tot++]=data{1,2*(1-x[i])};
			c[tot++]=data{1e18,2*(1e18-x[i])};
			k=0;
		}
		else{
			Rep(j,tot-1,k+1) c[j+2]=c[j];
			tot+=2; k++;
			c[k]=c[k+1]=data{tmp,0};
			For(j,0,k) c[j].fi+=a;
			For(j,k+1,tot-1) c[j].fi+=b;
			For(j,0,tot-1) c[j].se+=2*(c[j].fi-x[i]);
		}
		if (c[0].se>=0)
			k=-1,tmp=c[0].fi;
		else{
			for (k=0;k<tot;k++)
				if (c[k].se<=0&&c[k+1].se>0) break;
			tmp=c[k].fi-c[k].se/(c[k+1].se-c[k].se)*(c[k+1].fi-c[k].fi);
		}
		ans[i]=tmp;
	}
	ans[n]=min(ans[n],(double)q);
	Rep(i,n,2) ans[i-1]=min(max(ans[i-1],ans[i]-b),ans[i]-a);
	For(i,1,n) printf("%.15lf ",ans[i]),sum+=(ans[i]-x[i])*(ans[i]-x[i]);
	printf("\n%.15lf",sum);
}