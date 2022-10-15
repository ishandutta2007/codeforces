#include <cstdio>
const int N=2e5+10;
int T,n,a[N],b[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);bool tag=true;
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		for(int i=0;i<n;++i)scanf("%d",&b[i]);
		for(int i=0;i<n;++i){
			tag&=a[i]<=b[i];int t=(i+1)%n;
			if(a[i]!=b[i])tag&=b[t]>=b[i]-1;
		}
		puts(tag?"Yes":"No");
	}
	return 0;
}