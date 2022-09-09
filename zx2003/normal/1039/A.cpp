#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,i,c[N],x[N];
ll a[N],b[N],t,lo[N],hi[N],v;
void E(){puts("No");exit(0);}
int main(){
	scanf("%d%lld",&n,&t);
	for(i=1;i<=n;++i)scanf("%lld",a+i);
	for(i=1;i<=n;++i)hi[i]=4e18,lo[i]=a[i]+t;
	for(i=1;i<=n;++i){
		scanf("%d",x+i);
		if(x[i]<i)E();
		++c[i],--c[x[i]];
		if(x[i]<n)hi[x[i]]=min(hi[x[i]],a[x[i]+1]+t-1);
	}
	for(i=1;i<=n;++i){
		c[i]+=c[i-1];
		if(c[i]>0)lo[i]=max(lo[i],a[i+1]+t);;
		if(lo[i]>hi[i])E();
	}
	for(i=1;i<=n;++i){
		++v;
		if(v>hi[i])E();
		b[i]=v=max(v,lo[i]);
	}
	puts("Yes");
	for(i=1;i<=n;++i)printf("%lld%c",b[i],i==n?'\n':' ');
	return 0;
}