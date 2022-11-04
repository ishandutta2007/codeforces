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

#define INF (1ll<<61)
#define sqr(x) (1ll*(x)*(x))
using namespace std;
const int N=100005,K=55;
const int mo=1000000007;
int n,k,ans;
int x[K],y[K],v[K];
int X[K],Y[K];
int id1[N],id2[N],fac[N];
vector<pii> nx[K];
ll hz[K];
unordered_map<ll,ll> f[K][K];
int main(){
	scanf("%d%d",&n,&k); fac[0]=1;
	srand(n^(k+2333333+6666666)^19260817^19491001);
	For(i,1,n) id1[i]=id2[i]=i,fac[i]=1ll*fac[i-1]*i%mo;
	random_shuffle(id1+1,id1+n+1);
	random_shuffle(id2+1,id2+n+1);
	For(i,0,k-1){
		scanf("%d%d%d",&x[i],&y[i],&v[i]); --v[i];
		x[i]=id1[x[i]]; y[i]=id2[y[i]];
		X[++*X]=x[i]; Y[++*Y]=y[i];
	}
	sort(X+1,X+*X+1);
	sort(Y+1,Y+*Y+1);
	*X=unique(X+1,X+*X+1)-X-1;
	*Y=unique(Y+1,Y+*Y+1)-Y-1;
	For(i,0,k-1){
		x[i]=LB(X+1,X+*X+1,x[i])-X;
		y[i]=LB(Y+1,Y+*Y+1,y[i])-Y;
		nx[x[i]].PB(pii(y[i],v[i]));
	}
	Rep(i,*X,1){
		hz[i]=hz[i+1];
		For(j,0,nx[i].size()-1)
			hz[i]|=1ll<<nx[i][j].fi;
	}
	f[0][0][0]=1;
	For(i,1,*X) For(j,0,i-1){
		auto &c=f[i][j],&a=f[i][j+1];
		for (auto p:f[i-1][j]){
			(c[p.fi&hz[i+1]]+=p.se)%=mo;
			for (auto g:nx[i])
				if (!(p.fi&(1ll<<g.fi)))
					(a[(p.fi|(1ll<<g.fi))&hz[i+1]]+=1ll*p.se*g.se%mo)%=mo;
		}
		f[i-1][j].clear();
	}
	For(j,0,*X) for (auto p:f[*X][j])
		(ans+=1ll*p.se*fac[n-j]%mo)%=mo;
	printf("%d",ans); 
}