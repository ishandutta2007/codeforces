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
ll a[105];
int n,m,b[105];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll fi=0,se=0;
	for (int s=2;s<=m*2;s++){
		for (int i=1;i<=n;i++)
			b[i+1]=a[i]%s;
		b[1]=0; b[n+2]=s-1;
		sort(b+1,b+n+3);
		for (int i=n+2,tp=0;i>1;i--,tp^=1){
			int l=b[i-1]+1,r=min(b[i],m);
			if (!tp) l=max(l,b[n+1]/2+1);
			else l=max(l,b[n]/2+1);
			/*
			l-r 
			tp:0
			  :1
			   2*a<=v<=b
			   
			*/ 
			int L=max(l,s-r),R=min(r,s-l);
			/*
			l+r==s 
			*/ 
			if (L<=R){
				if (!tp) se+=R-L+1;
				else fi+=R-L+1;
			} 
			/*
			tp=0
			         
			*/ 
		}
	}
	ll ano=(1ll*m*m-se-fi)/2;
	printf("%lld %lld %lld %lld\n",ano,ano,fi,se); 
}