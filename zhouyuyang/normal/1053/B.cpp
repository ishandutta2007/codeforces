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

#define inf ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;

const int N=300005;
int s[N],cnt[N][2];
int n;
ll ans;
int main(){
	scanf("%d",&n); s[0]=0;
	for (int i=1;i<=n;i++){
		ll x; scanf("%lld",&x); s[i]=s[i-1];
		for (;x;s[i]+=(x&1),x/=2);
	}
	cnt[0][0]=1;
	for (int i=1;i<=n;i++){
		cnt[i][0]=cnt[i-1][0];
		cnt[i][1]=cnt[i-1][1];
		cnt[i][s[i]&1]++;
	}
	for (int i=1;i<=n;i++){
		if (i>=64) ans+=cnt[i-64][s[i]&1];
		int tmpmx=0;
		for (int j=i-1;j>i-64&&j>=0;j--){
			tmpmx=max(tmpmx,s[j+1]-s[j]);
			if (tmpmx*2<=s[i]-s[j]&&(s[j]+s[i])%2==0) ans++;
		}
	}
	printf("%lld\n",ans);
}