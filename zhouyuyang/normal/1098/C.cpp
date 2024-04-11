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
const int N=100005;
int n,ans,cnt[N];
ll s;
ll mnv(int x){
	CLR(cnt,0);
	int lvl=1,rest=n;
	ll sum=0;
	cnt[1]=1;
	for (;rest;++lvl){
		rest-=cnt[lvl];
		sum+=1ll*cnt[lvl]*lvl;
		cnt[lvl+1]=min((ll)rest,1ll*cnt[lvl]*x);
	}
	return sum;
}
int main(){
	scanf("%d%lld",&n,&s);
	if (1ll*n*(n+1)/2<s||2*n-1>s)
		return puts("No"),0;
	puts("Yes");
	if (1ll*n*(n+1)/2==s){
		For(i,1,n-1)
			printf("%d ",i);
		return 0;
	}
	int l=1,r=n,ans=-1;
	while (l<=r){
		int mid=(l+r)/2;
		if (mnv(mid)<=s)
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	s-=mnv(ans);
	int pos=20;
	for (;!cnt[pos];pos--);
	for (;s;){
		int at=20;
		for (;cnt[at]<=1;at--);
		int can=pos+1-at;
		int tmp=min((ll)can,s);
		//printf("%d %d\n",at,tmp);
		s-=tmp;
		cnt[at]--;
		cnt[at+tmp]++;
		pos=max(pos,at+tmp);
	}
	/*For(i,1,pos)
		printf("%d ",cnt[i]);
	puts("");*/
	int presum=0;
	For(i,2,pos){
		int at=presum+1,rest=ans;
		For(j,1,cnt[i]){
			printf("%d ",at);
			if (!--rest) at++,rest=ans;
		}
		presum+=cnt[i-1];
	}
}