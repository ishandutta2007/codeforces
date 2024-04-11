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
int n;
int x[100005];
int y[100005];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d%d",&x[i],&y[i]);
	if (n&1) return puts("NO"),0;
	For(i,1,n/2){
		int dx=x[i+1]-x[i],dy=y[i+1]-y[i];
		if (x[i+n/2]-dx!=x[(i+n/2)%n+1]||
			y[i+n/2]-dy!=y[(i+n/2)%n+1])
				return puts("NO"),0;
	}
	puts("YES");
}