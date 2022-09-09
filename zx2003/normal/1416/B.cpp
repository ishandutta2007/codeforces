#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int T,n,i,a[N],s;
inline void opt(int i,int j,int x){
	a[i]-=i*x;a[j]+=i*x;
assert(a[i]>=0 && x>=0);
	printf("%d %d %d\n",i,j,x);
}
int main(){
	for(scanf("%d",&T);T--;){
		s=0;scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i),s+=a[i];
		if(s%n){puts("-1");continue;}
		printf("%d\n",3*(n-1));
		for(i=2;i<=n;++i)opt(1,i,(i-a[i]%i)%i),opt(i,1,a[i]/i);
		for(i=2;i<=n;++i)opt(1,i,s/n);
for(i=2;i<=n;++i)assert(a[i]==a[i-1]);
	}
}