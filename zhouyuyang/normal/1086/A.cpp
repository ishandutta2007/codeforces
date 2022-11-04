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
 
#define inf 1<<30
#define sqr(x) ((x)*(x))
using namespace std;
int x[5],y[5];
void walk(int x,int y,int px,int py){
	for (;x<px;printf("%d %d\n",++x,y));
	for (;x>px;printf("%d %d\n",--x,y));
	for (;y<py;printf("%d %d\n",x,++y));
	for (;y>py;printf("%d %d\n",x,--y));
}
int main(){
	for (int i=1;i<=3;i++)
		scanf("%d%d",&x[i],&y[i]);
	int ans=1e9,px=1e9,py=1e9;
	for (int i=0;i<=1000;i++)
		for (int j=0;j<=1000;j++){
			int val=0;
			For(k,1,3)
				val+=abs(i-x[k])+abs(j-y[k]); 
			if (val<ans)
				ans=val,px=i,py=j;
		}
	printf("%d\n",ans+1);
	printf("%d %d\n",px,py);
	for (int i=1;i<=3;i++)
		walk(px,py,x[i],y[i]);
}