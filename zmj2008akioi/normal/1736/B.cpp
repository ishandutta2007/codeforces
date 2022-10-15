#include <cstdio>
const int N=1e5+10;
int T,n,a[N],b[N];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),a[0]=a[n+1]=1;bool tag=true;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n+1;++i)b[i]=a[i-1]*a[i]/gcd(a[i-1],a[i]);
		for(int i=1;i<=n;++i)tag&=gcd(b[i],b[i+1])==a[i];
		puts(tag?"Yes":"No");
	}
	return 0;
}