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

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int N=195000,Q=1050000;
int n,q,a[N],p[N][8];
int l[Q],t[N],ss[20];
vector<int> no[N];
int dp[Q*5][8],ans[Q];
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++){
		int x,x1,y; scanf("%d",&x); x1=x;
		for (int j=2;j*j<=x1;j++){
			for (y=0;x%j==0;x/=j,y^=1);
			if (y) p[i][t[i]++]=j;
		}
		if (x>1)
			p[i][t[i]++]=x;
	}
	for (int i=1,x;i<=q;i++)
		scanf("%d%d",&l[i],&x),no[x].push_back(i);
	for (int i=1;i<=n;i++){
		for (int s=0;s<1<<t[i];s++){
			int x=1,x1=0;
			for (int j=0;j<t[i];j++)
				if ((s>>j)&1) x*=p[i][j]; else x1++;
			for (int j=0;j<8&&j+x1<12;j++)
				ss[j+x1]=max(ss[j+x1],dp[x][j]);
		}
		for (auto j:no[i])
			for (int k=0;;k++)
				if (ss[k]>=l[j]){
					ans[j]=k; break;
				}
		for (int s=0;s<1<<t[i];s++){
			int x=1,x1=0;
			for (int j=0;j<t[i];j++)
				if ((s>>j)&1) x*=p[i][j]; else x1++;
			dp[x][x1]=i;
		}
	}
	for (int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
}