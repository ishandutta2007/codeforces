

#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
#define fi first
#define se second
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(j);i<=(int)k;i++)
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i++)
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

const int N=100005;
int n,X[N],Y[N];
int x,y,id[N],ans[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&X[i],&Y[i]);
	For(i,1,n) id[i]=i;
	for (;;){
		random_shuffle(id+1,id+n+1); 
		ans[id[1]]=1; int x=X[id[1]],y=Y[id[1]];
		For(i,2,n){
			if (sqr(x+X[id[i]])+sqr(y+Y[id[i]])<=sqr(x-X[id[i]])+sqr(y-Y[id[i]]))
				x+=X[id[i]],y+=Y[id[i]],ans[id[i]]=1;
			else x-=X[id[i]],y-=Y[id[i]],ans[id[i]]=-1;
		}
		if (sqr(x)+sqr(y)<=sqr(1500000)){
			For(i,1,n) printf("%d ",ans[i]);
			return 0;
		}
	}
}