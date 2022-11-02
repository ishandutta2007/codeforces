#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
#define int ll
typedef long long ll;
const int N=200005;
int n,d,b,zs,tot,a[N],f[N],g[N];
int l,r,ans1,ans2;
signed main(){
	scanf("%d%d%d",&n,&d,&b);
	int t=n/2; tot=t*b; for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		f[i]=min(a[i],tot)+f[i-1]; tot-=min(a[i],tot);
	}
	tot=t*b;
	for(int i=n;i;i--){
		g[i]=min(a[i],tot)+g[i+1]; tot-=min(a[i],tot);
	}
	tot=t;
	zs=0;
	for(int i=1;i<=tot;i++){
		r=min(r+d+1,n); if(zs+b<=f[r])zs+=b; else ans1++;
	}
	tot=(n+1)/2+1; zs=0;
	l=n+1;
	for(int i=n;i>=tot;i--){
		l=max((ll)1,l-d-1); if(zs+b<=g[l])zs+=b; else ans2++;
	}
	cout<<max(ans1,ans2)<<endl;
}