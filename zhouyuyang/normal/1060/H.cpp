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
 
#define inf 2000000000
#define sqr(x) ((x)*(x))
using namespace std;
int d,mo,ND,at[20];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void mulnum(int x,int val,int res){
	int y=4;
	printf("+ %d %d %d\n",x,x,y);
	printf("+ %d %d %d\n",x,x,res);
	for (val-=2;val<0||(val&1);val+=mo);
	for (val/=2;val;){
		if (val&1) printf("+ %d %d %d\n",res,y,res);
		if (val/=2) printf("+ %d %d %d\n",y,y,y);
	}
}
int a[12][12],c[12][12];
int getsqr(int x){
	memset(a,0,sizeof(a));
	For(i,0,d) c[i][0]=1;
	For(i,1,d) For(j,1,i) c[i][j]=c[i-1][j]+c[i-1][j-1];
	For(i,0,d) For(j,0,d) a[i][j]=1ll*c[d][i]*power(j,d-i)%mo;
	a[2][d+1]=1;
	For(i,0,d){
		int t=i;
		For(j,i+1,d) if (a[j][i]>a[t][i]) t=j;
		For(j,i,d+1) swap(a[i][j],a[t][j]);
		int v=power(a[i][i],mo-2);
		For(j,i,d+1) a[i][j]=1ll*a[i][j]*v%mo;
		For(j,0,d) if (j!=i)
			Rep(k,d+1,i) a[j][k]=(a[j][k]+mo-1ll*a[j][i]*a[i][k]%mo)%mo;
	}
	int ans=++ND;
	printf("^ %d %d\n",x,ans);
	mulnum(ans,a[0][d+1],ans);
	for (int i=1;i<=d;i++){
		printf("+ %d 5 %d\n",x,x);
		printf("^ %d 6\n",x);
		mulnum(6,a[i][d+1],6);
		printf("+ %d 6 %d\n",ans,ans); 
	}
	return ans;
}
int main(){
	scanf("%d%d",&d,&mo);
	for (int i=1;i<=15;i++) at[i]=1;
	int x=1,y=2,z=3; ND=6;
	mulnum(y,mo-1,z);
	printf("+ %d %d %d\n",z,x,z);
	printf("+ %d %d %d\n",y,x,y);
	z=getsqr(z); y=getsqr(y);
	mulnum(z,mo-1,z);
	printf("+ %d %d %d\n",y,z,z);
	mulnum(z,power(4%mo,mo-2),z);
	printf("f %d\n",z);
}