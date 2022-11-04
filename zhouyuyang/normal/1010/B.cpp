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
using namespace std;

int ask(int k){
	printf("%d\n",k);
	fflush(stdout);
	scanf("%d",&k);
	return k;
}
int m,n,lie[35];
int main(){
	scanf("%d%d",&m,&n);
	For(i,1,n){
		int v=ask(1);
		if (!v) return 0;
		if (v==-1) lie[i]=1;
		else lie[i]=-1;
	}
	int l=2,r=m,t=0;
	while (l<=r){
		t%=n;
		int mid=(l+r)/2;
		int val=lie[++t]*ask(mid);
		if (!val) return 0;
		if (val==-1) l=mid+1;
		else r=mid-1;
	}
}