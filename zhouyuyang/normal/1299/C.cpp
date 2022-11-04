#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=1000005;
int n,a[N],t;
pll q[N];
bool cmp(pll x,pll y){
	return 1ll*x.fi*y.se<1ll*y.fi*x.se;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	int t=0;
	For(i,1,n){
		pll tmp(a[i],1);
		for (;t&&cmp(tmp,q[t]);){
			tmp.fi+=q[t].fi;
			tmp.se+=q[t].se;
			--t;
		}
		q[++t]=tmp;
	}
	For(i,1,t)
		For(j,1,q[i].se)
			printf("%.10lf\n",q[i].fi*1.0/q[i].se);
}