#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
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

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;

const int N=100005;
db fac[N],prob[N],ans;
db C(int x,int y){
	return fac[x]/fac[y]/fac[x-y];
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	fac[0]=prob[0]=1;
	For(i,1,N-1){
		fac[i]=fac[i-1]*i;
		prob[i]=prob[i-1]*(k+1-i)/(m+1-i);
	}
	//ans=0;
	For(i,0,n) For(j,0,n)
		ans+=C(n,i)*C(n,j)*prob[n*(i+j)-i*j];
	cout<<setprecision(15);
	if (ans<1e99)
		cout<<ans<<endl;
	else puts("1e99");
}