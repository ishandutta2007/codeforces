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
#define y1 wzpakking 
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1<<29)
using namespace std;
int n;
char s[10];
int LIM=1e9;
int main(){
	scanf("%d",&n);
	int l=0,r=2*LIM,mid;
	for (int i=1;i<=n;i++){
		mid=(1ll*l+r)/2;
		if (mid<=LIM) printf("%d 0\n",LIM-mid);
		else printf("0 %d\n",mid-LIM);
		fflush(stdout);
		scanf("%s",s+1);
		if (s[1]=='b') l=mid+1;
		else r=mid-1;
	}
	if (l<=r){
		if (l<=LIM) printf("%d 0 %d 1\n",LIM-l,LIM-l);
		else printf("0 %d 1 %d\n",l-LIM,l-LIM);
	}
	else{
		if (l==0) printf("%d 1 %d 3",LIM,LIM-1);
		else if (l==2*LIM+1) printf("1 %d 3 %d",LIM,LIM-1);
		else if (l<=LIM) printf("%d 1 %d 3\n",LIM-l,LIM-l-1);
		else printf("1 %d 3 %d\n",l-LIM,l-LIM+1);
	}
}