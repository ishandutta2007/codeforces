#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,d,m,i,a1[N],a2[N],x,j,n1,n2;
ll s1[N],s2[N],ans;
int main(){
	scanf("%d%d%d",&n,&d,&m);
	for(i=1;i<=n;++i)scanf("%d",&x),(x<=m?a1[++n1]:a2[++n2])=x;
	sort(a1+1,a1+n1+1,greater<int>());sort(a2+1,a2+n2+1,greater<int>());
	for(i=1;i<=n1;++i)s1[i]=s1[i-1]+a1[i];
	for(i=1;i<=n2;++i)s2[i]=s2[i-1]+a2[i];
	ans=s1[n1];
	for(i=0;i<=n2;++i){
		j=n-(i-1)*(d+1)-1;
		if(j>=0)ans=max(ans,s2[i]+s1[min(j,n1)]);else break;
	}
	printf("%lld\n",ans);
}