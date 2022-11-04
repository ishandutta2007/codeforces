#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define PQ priority_queue
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(j);i<=(int)k;i++)
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1ll<<61)
#define sqr(x) (1ll*(x)*(x))
using namespace std;

const int N=100005;
int l[N],r[N],a[N*2];
int n,t[N*2],R[N*2],Md[N*2];
void add(int k,int v){
	for (;k<=2*n;k+=k&(-k)) t[k]+=v;
}
int ask(int k){
	int ans=0;
	for (;k;k-=k&(-k)) ans+=t[k];
	return ans;
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x]=y; a[y]=x;
	}
	ll ans=1ll*n*(n-1)*(n-2)/6;
	ll s1=0,s2=0;
	Rep(i,2*n,1) if (a[i]>i)
		R[i]+=ask(a[i]),add(a[i],1);
	CLR(t,0);
	Rep(i,2*n,1) if (a[i]<i)
		Md[a[i]]+=ask(i)-ask(a[i]-1),add(a[i],1);
	CLR(t,0);
	For(i,1,2*n) if (a[i]>i)
		Md[i]+=ask(a[i])-ask(i-1),add(a[i],1);
	For(i,1,n*2) if (a[i]>i){
		s1+=1ll*Md[i]*(n-1-Md[i]);
		s2+=1ll*R[i]*(n-1-Md[i]-R[i]);
	}
	printf("%lld\n",ans-s1/2-s2);
}