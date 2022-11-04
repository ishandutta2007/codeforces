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
const int mo=1000000007;
const int N=200005,M=2000000;
int n,a[N],b[N],cnt[M+5];
int mn[M+5],mx[M+5],t[M+5];
void init(){
	For(i,0,M+2) mn[i]=233333333;
	For(i,2,M) For(j,1,M/i) mn[i*j]=min(mn[i*j],i);
}
void insert(int v){
	b[++*b]=v;
	for (;v!=1;){
		int p=mn[v],cnt=0;
		for (;v%p==0;v/=p,cnt++);
		if (cnt>mx[p]) mx[p]=cnt,t[p]=1;
		else if (cnt==mx[p]) t[p]++;
	}
}
bool check(int v){
	for (;v!=1;){
		int p=mn[v],cnt=0;
		for (;v%p==0;v/=p,cnt++);
		if (cnt==mx[p]&&t[p]==1) return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&n); init();
	For(i,1,n) scanf("%d",&a[i]),cnt[a[i]]++;
	For(i,1,M) if (cnt[i]>=2) insert(i),insert(i-1);
	Rep(i,M,1) if (cnt[i]==1)
		if (mx[i]) insert(i-1);
		else insert(i);
	int ans=1,ans2=0;
	For(i,1,M) For(j,1,mx[i])
		ans=1ll*ans*i%mo;
	For(i,1,M) if (cnt[i]>=3-(i==2)) ans2=1;
	For(i,1,*b) if (check(b[i])) ans2=1;
	printf("%d\n",(ans+ans2)%mo);
}