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
using namespace std;
const int mo=998244353;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
const int N=105;
int n,t,spe[N*N];
int x[N],y[N],X[N],Y[N];
struct que{
	int l,r,v;
};
vector<que> Q[N];
int cnt[N];
int calc(int T){
	int ans=0; *X=*Y=0;
	For(i,1,N-1) Q[i].resize(0);
	CLR(cnt,0);
	For(i,1,n){
		X[++*X]=x[i]-T;
		X[++*X]=x[i]+T+1;
		Y[++*Y]=y[i]-T;
		Y[++*Y]=y[i]+T+1;
	}
	sort(X+1,X+*X+1);
	sort(Y+1,Y+*Y+1);
	*X=unique(X+1,X+*X+1)-X-1;
	*Y=unique(Y+1,Y+*Y+1)-Y-1;
	For(i,1,n){
		int p1=lower_bound(Y+1,Y+*Y+1,y[i]-T)-Y;
		int p2=lower_bound(Y+1,Y+*Y+1,y[i]+T+1)-Y-1;
		Q[lower_bound(X+1,X+*X+1,x[i]-T)-X].PB((que){p1,p2,1});
		Q[lower_bound(X+1,X+*X+1,x[i]+T+1)-X].PB((que){p1,p2,-1});
	}
	For(i,1,(*X)-1){
		for (auto j:Q[i])
			For(k,j.l,j.r) cnt[k]+=j.v;
		int sum=0;
		For(k,1,(*Y)-1)
			if (cnt[k]) sum+=Y[k+1]-Y[k];
		ans=(ans+1ll*sum*(X[i+1]-X[i]))%mo;
	}
	return ans;
}
int val[10],f[10],poly[10];
int main(){
	scanf("%d%d",&n,&t);
	spe[++*spe]=-1; spe[++*spe]=t-1;
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	For(i,1,n) For(j,i+1,n){
		int val=(max(abs(x[i]-x[j]),abs(y[i]-y[j]))+1)/2;
		if (val<t) spe[++*spe]=val-1;
	}
	sort(spe+1,spe+*spe+1);
	*spe=unique(spe+1,spe+*spe+1)-spe-1;
	int ans=1ll*t*calc(t)%mo;
	For(l,2,*spe){
		CLR(val,0);
		int st=spe[l-1]+1,ed=min(st+3,spe[l]),len=ed-st;
		For(j,st,ed) val[j-st]=calc(j);
		For(j,1,3) val[j]=(val[j]+val[j-1])%mo;
		CLR(poly,0);
		For(i,0,3){
			int tmp=1;
			For(j,0,3) if (i!=j)
				tmp=1ll*tmp*(i+mo-j)%mo;
			int v=1ll*val[i]*power(tmp,mo-2)%mo;
			//printf("%d\n",v);
			CLR(f,0); f[0]=1;
			For(j,0,3) if (i!=j){
				Rep(k,3,1) f[k]=(1ll*f[k]*(mo-j)+f[k-1])%mo;
				f[0]=1ll*f[0]*(mo-j)%mo;
			}
			For(j,0,3)
				poly[j]=(poly[j]+1ll*v*f[j])%mo;
		}
		len=spe[l]-st;
		//printf("%d %d %d %d\n",len,poly[0],poly[1],poly[2]);
		ans=(ans+mo-poly[0])%mo;
		ans=(ans+mo-1ll*len*poly[1]%mo)%mo;
		ans=(ans+mo-1ll*len*len%mo*poly[2]%mo)%mo;
		ans=(ans+mo-1ll*len*len%mo*len%mo*poly[3]%mo)%mo;
		//printf("%d\n",ans);
	}
	printf("%d\n",ans);
}
/*
2 10
0 0
2 0
*/