#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define PQ priority_queue
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
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i--)
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
#define pbi pair<bool,unsigned short>
using namespace std;
int e[32],p[32],ans[32],n,mo;
bool f[32][32][50005];
pbi fr[32][32][50005];
int main(){
	scanf("%d%d",&n,&mo);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		if (x<=31) e[++*e]=x,p[*e]=i;
	}
	For(i,1,*e){
		f[i][e[i]][e[i]%mo]=1;
		fr[i][e[i]][e[i]%mo]=pbi(1,-1);
		For(x,0,31) For(j,0,mo-1) if (f[i-1][x][j]){
			f[i][x][j]=1; fr[i][x][j]=pbi(0,j);
			int nxt=(j*(e[i]>=10?100:10)+e[i])%mo;
			f[i][x^e[i]][nxt]=1; fr[i][x^e[i]][nxt]=pbi(1,j);
		}
	}
	if (!f[*e][0][0]){
		puts("No");
		return 0;
	}
	puts("Yes");
	int id1=0,id2=0;;
	Rep(i,*e,1){
		int to=fr[i][id1][id2].se;
		if (fr[i][id1][id2].fi==1){
			ans[++*ans]=p[i];
			id1^=e[i];
		}
		id2=to;
		if (id2==-1) break;
	}
	printf("%d\n",*ans);
	Rep(i,*ans,1) printf("%d ",ans[i]);	
}