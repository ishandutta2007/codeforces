#include <cstdio>
typedef long long LL;
const int N=1e5+10;
int T,n,k,a[N],s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&k);bool tag=true;
		for(int i=n-k+1;i<=n;++i)scanf("%d",&s[i]);
		if(k==1){puts("Yes");continue;}
		for(int i=n-k+2;i<=n;++i)a[i]=s[i]-s[i-1];
		for(int i=n-k+2;i<n;++i)tag&=a[i]<=a[i+1];
		tag&=s[n-k+1]<=(LL)a[n-k+2]*(n-k+1);
		puts(tag?"Yes":"No");
	}
	return 0;
}