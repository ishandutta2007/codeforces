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

const int N=1000005;
char s[N];
int lp[N],rp[N];
int rd[N],f[N];
int n,sp,sd;
int main(){
	scanf("%d%s",&n,s+1);
	For(i,1,n){
		lp[i]=(s[i]=='P'?i:lp[i-1]);
		sp+=(s[i]=='P');
		sd+=(s[i]=='*');
	}
	rp[n+1]=rd[n+1]=n+1;
	Rep(i,n,1){
		rp[i]=(s[i]=='P'?i:rp[i+1]);
		rd[i]=(s[i]=='*'?i:rd[i+1]);
	}
	if (sp==1){
		int ls=0,rs=0,lp,rp,i;
		for (i=1;s[i]!='P';i++) if (s[i]=='*'&&!(ls++)) lp=i;
		for (i=n;s[i]!='P';i--) if (s[i]=='*'&&!(rs++)) rp=i;
		printf("%d %d",max(ls,rs),ls>rs?i-lp:(ls<rs?rp-i:min(i-lp,rp-i)));
		return 0;
	}
	int l=1,r=n,ans=1;
	while (l<=r){
		int mid=(l+r)/2;
		memset(f,0,sizeof(f)); f[1]=1;
		For(i,1,n) if (f[i]){
			if (s[i]=='.') f[i+1]=1;
			if (s[i]=='P') f[min(rp[i+1],min(i+mid+1,n+1))]=1;
			if (s[i]=='*'){
				if (rp[i]>n||rp[i]-i>mid) continue;
				f[rp[i]+1]=1;
				if (rp[rp[i]+1]<=n&&rp[rp[i]+1]-i<=mid)
					f[lp[min(rp[i]+mid,n)]>rp[rp[i]+1]?lp[min(rp[i]+mid,n)]:min(rp[i]+mid+1,n+1)]=1;
			}
		}
		if (f[n+1])
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d %d\n",sd,ans);
}