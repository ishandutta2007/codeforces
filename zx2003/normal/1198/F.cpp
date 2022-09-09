#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,i,a[N],p[N],ans[N],g0,g1;
int main(){
	srand(time(0));
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i),p[i]=i;
	for(;clock()*1.0/CLOCKS_PER_SEC<0.45;){
		random_shuffle(p+1,p+n+1);g0=g1=0;
		for(i=1;i<=n;++i)if(!g0 || a[p[i]]%g0)g0=__gcd(g0,a[p[i]]),ans[p[i]]=1;
			else g1=__gcd(g1,a[p[i]]),ans[p[i]]=2;
		if(g0==1 && g1==1){puts("YES");for(i=1;i<=n;++i)printf("%d%c",ans[i],i==n?'\n':' ');return 0;}
	}
	puts("NO");
	return 0;
}