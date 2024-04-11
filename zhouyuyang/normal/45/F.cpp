#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
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

#define INF (1<<29)
#define sqr(x) ((x)*(x))
#define eps (1e-7)

#define OUT(x) return printf("%d",x),0
using namespace std;
int n,m,ans,fl;
int main(){
	scanf("%d%d",&m,&n);
	if (n==1) OUT(-1);
	if (n==2&&m==3) OUT(11);
	if (n==3&&m==5) OUT(11);
	for (;;){
		if (n>=m+m) OUT(ans+1);
		if (n>=m) OUT(ans+3+2*(n==m));
		if (!fl) m-=n-2,ans=4,fl=1;
		else if (n/2==1) OUT(-1);
		else m-=n/2-1,ans+=2;
	}
}