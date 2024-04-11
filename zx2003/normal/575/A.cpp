#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+5;
int n,m,mo,s[N],i,j,x,y;
pair<ll,int>a[N];ll K;
struct mat{
	int a[2][2];
	inline mat operator*(const mat&rhs)const{
		static mat ans;
		for(int i=0;i<2;++i)for(int j=0;j<2;++j)ans.a[i][j]=
			(1ll*a[i][0]*rhs.a[0][j]+1ll*a[i][1]*rhs.a[1][j])%mo;
		return ans;
	}
	inline void trs(int&x,int&y){
		int xx=(1ll*x*a[0][0]+1ll*y*a[1][0])%mo,yy=(1ll*x*a[0][1]+1ll*y*a[1][1])%mo;
		x=xx;y=yy;
	}
}f[60][N];
inline void work(int u,ll d){if(d>0)for(j=59;j>=0;--j)if(d>>j&1)f[j][u].trs(x,y),u=(u+(1ll<<j))%n;}
int main(){
	scanf("%lld%d%d",&K,&mo,&n);y=1;if(!K){puts("0");return 0;}
	for(i=0;i<n;++i)scanf("%d",s+i);scanf("%d",&m);
	for(i=0;i<n;++i)f[0][i]=(mat){0,s[(i+n-1)%n],1,s[i]};
	for(i=1;i<60;++i)for(j=0;j<n;++j)f[i][j]=f[i-1][j]*f[i-1][(j+(1ll<<i-1))%n];
	for(i=1;i<=m;++i)scanf("%lld%d",&a[i].first,&a[i].second);sort(a+1,a+m+1);
	for(i=1;i<=m && a[i].first<K;++i){
		work((a[i-1].first+(i>1?2:1))%n,a[i].first-a[i-1].first-(i>1?2:1));
		x=(1ll*x*(a[i].first==a[i-1].first+1 && i>1?a[i-1].second:s[(a[i].first+n-1)%n])+1ll*y*a[i].second)%mo;
		if(a[i].first+1<K && (i==m || a[i].first+1<a[i+1].first))
			y=(1ll*y*a[i].second+1ll*x*s[(a[i].first+1)%n])%mo;else swap(x,y);
	}
	work((a[i-1].first+(i>1?2:1))%n,K-a[i-1].first-(i>1?2:1));printf("%d\n",y%mo);
	return 0;
}