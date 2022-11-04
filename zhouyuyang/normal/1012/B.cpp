#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
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
int n,m,k,fa[400005],ans;
int get(int x){
	return fa[x]==x?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,n+m) fa[i]=i;
	int ans=n+m-1;
	For(i,1,k){
		int x,y; scanf("%d%d",&x,&y);
		x=get(x); y=get(y+n);
		if (x!=y) fa[x]=y,ans--;
	}
	printf("%d\n",ans);
}