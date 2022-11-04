#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
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
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(j);i<=(int)k;i++)
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i++)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define SWP(x,y) if (a[x]>a[y]) swap(x,y);
using namespace std;

const int N=1005;
int a[N],X[N*N],Y[N*N],n;
void add(int x,int y){
	a[y]-=a[x]; a[x]+=a[x];
	X[++*X]=x; Y[*X]=y;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	int cnt=0;
	For(i,1,n) cnt+=(a[i]!=0);
	if (cnt<2) return puts("-1"),0;
	if (n<=2) return puts("0"),0;
	int idA=1,idB=2;
	For(i,3,n){
		int idC=i;
		SWP(idA,idB); SWP(idA,idC); SWP(idB,idC);
		for (;a[idA];){
			int val=a[idB]/a[idA];
			for (;val;val>>=1)
				add(idA,(val&1)?idB:idC);
			SWP(idA,idB); SWP(idA,idC); SWP(idB,idC);
		}
		idA=idB; idB=idC;
	} 
	printf("%d\n",*X);
	for (int i=1;i<=*X;i++)
		printf("%d %d\n",X[i],Y[i]);
}