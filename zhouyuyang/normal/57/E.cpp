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
const int d[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int n,a[205][205],cnt[55];
const int tim=40;
const int mo=1000000007;
pii q[40005];
ll k;
int main(){
	scanf("%lld%d",&k,&n);
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x+100][y+100]=-1;
	}
	a[100][100]=1;
	int h=0,t=1;
	q[1]=pii(100,100);
	while (h!=t){
		pii p=q[++h];
		if (a[p.fi][p.se]==k+1||a[p.fi][p.se]==tim+1) break;
		for (int i=0;i<8;i++){
			pii np=p;
			np.fi+=d[i][0]; np.se+=d[i][1];
			if (!a[np.fi][np.se]){
				a[np.fi][np.se]=a[p.fi][p.se]+1;
				cnt[a[np.fi][np.se]]++;
				q[++t]=np;
			}
		}
	}
	if (k<=tim||cnt[tim+1]==0)
		printf("%d\n",t);
	else{
		ll p=k-tim,v1=p,v2=p+1;
		if (v1%2) v2/=2; else v1/=2;
		printf("%d\n",((v1%mo)*(v2%mo)%mo*28%mo+p%mo*cnt[tim+1]%mo+t)%mo);
	}
}