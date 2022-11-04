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
const int N=100005;
vector<pii> ok[N];
int n,ans[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n/2;i++){
		int val;
		scanf("%d",&val); 
		for (int j=1;j*j<=val;j++)
			if (val%j==0){
				int k=val/j;
				if ((j+k)&1) continue;
				ok[i].PB(pii((k-j)/2,(k+j)/2));
			}
		sort(ok[i].begin(),ok[i].end());
	}
	int mx=0;
	For(i,1,n/2){
		pii tmp(1e9,1e9);
		for (auto j:ok[i])
			if (j.fi>mx&&j.se<tmp.se)
				tmp=j;
		if (tmp.se>1e7)
			return puts("No"),0;
		ans[i*2-1]=tmp.fi;
		ans[i*2]=tmp.se;
		mx=tmp.se; 
	}
	printf("Yes\n");
	For(i,1,n)
		printf("%lld ",1ll*ans[i]*ans[i]-1ll*ans[i-1]*ans[i-1]);
}