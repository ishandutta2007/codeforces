#include <cstdio>
const int N=1e6+10;
int T,n,k,b;
long long s,l,r,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d %lld",&n,&k,&b,&s);
		l=1ll*b*k,r=l+1ll*n*(k-1);
		if(s<l||s>r){puts("-1");continue;}
		s-=l;
		for(int i=1;i<=n;++i){
			if(s>=k-1)s-=k-1,a[i]=k-1;
			else a[i]=s,s=0;
		}
		a[1]+=l;
		for(int i=1;i<=n;++i)printf("%lld ",a[i]);
		putchar('\n');
	}
	return 0;
}